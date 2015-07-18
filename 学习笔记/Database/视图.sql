------------------------------创建视图-----------------------------

--1.视图:视图是一个虚拟表，称其为虚拟表的原因是：视图内的数据并属于视图本身，而属于创建视图时用到的基本表
--       可以认为，视图是一个表中的数据经过某种筛选后的显示方式，或则多个表中的数据经过筛选后的显示方式。

CREATE VIEW VIEW1--创建一个名为VIEW1的视图
AS --后跟查询语句
SELECT 起始年份,终止年份 FROM nddzb

SELECT * FROM VIEW_YEAR--创建完视图后，可以直接对它进行查询，可省略很多重复操作

CREATE VIEW VIEW_BOY--将性别为男的记录创建为一个视图
AS
SELECT * FROM STUDENT 
WHERE SSEX ='男'

CREATE VIEW VIEW_GIRL(学号,姓名,性别)--在创建视图时可以为视图字段取别名
AS
SELECT SNO,SNAME,SSEX
FROM STUDENT 
WHERE SSEX ='女'

CREATE VIEW VIEW_GIRL2
AS
SELECT SNO AS 学号 ,SNAME AS 姓名,SSEX AS 性别--在创建视图时也可以在查询语句中为视图字段取别名
FROM STUDENT 
WHERE SSEX ='女'

--注意：在创建视图的SELECT语句中不能包括：COMPUTE,COMPUTE BY,ORDER BY,OPTION,INTO,临时表,表变量
SELECT * FROM INFORMATION_SCHEMA .VIEWS --查看数据库中视图的信息

CREATE VIEW VIEW_GIRL3
WITH ENCRYPTION--创建一个加密视图,系统将会隐藏定义视图的语句，这样别人就看不到视图所使用的基表和语句了，从而提高安全性
AS
SELECT * FROM STUDENT 
WHERE SSEX ='女'


-----------------------------查看与修改视图-------------------------

SELECT * FROM VIEW_GIRL3 --查询视图与查询表是一样的

ALTER VIEW VIEW_GIRL3--修改视图的内容，将其查询条件更改为男生
AS 
SELECT  SNO,SNAME ,SSEX  FROM STUDENT --这里的查询语句将覆盖先前的查询语句
WHERE SSEX ='男'


----------------------------使用视图操作表数据----------------------

--1.在视图中更改数据，在原表中的数据也会被更改

INSERT INTO VIEW_GIRL3
--INSERT INTO VIEW_GIRL3(SNO,SNAME)  也可插入指定的字段
VALUES ('10315110201','仲俊霖','男')

--并不是所有视图都可以更新数据
--查询结果来自多个表或视图的视图不能更新数据，还有其它几种情况也不能更新数据

UPDATE VIEW_GIRL3
SET SNAME ='张三' --将学号是201的学生姓名修改为张三
WHERE SNO='10315110201'

DELETE FROM VIEW_GIRL3--删除操作，同时也删除了基表中的数据
WHERE SNO='10315110201'

DROP VIEW VIEW_GIRL3--删除视图
