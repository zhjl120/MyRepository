---------------------------存储过程-----------------

--1.创建存储过程

CREATE PROC STU --创建一个存储过程
AS
SELECT * FROM STUDENT --存储过程中的操作

--2.执行存储过程

EXEC STU--执行存储过程，EXEC是EXECUTE的简写，它用来执行存储过程

--3.创建带参数的存储过程

CREATE PROC SEARCH --定义存储过程
@SNO VARCHAR(12) --定义它需要的参数即类型
AS 
SELECT * FROM SCORE 
WHERE SNO =@SNO --将参数作为查询的条件使用

EXEC SEARCH '6320210603 '--执行带参数的存储过程

--4.创建带默认值参数的存储过程

CREATE PROC SEARCH2 --带默认值参数的存储过程
@SNO VARCHAR(12) ='6320210603'--在创建存储过程的时候就为参数设置默认值
AS 
SELECT * FROM SCORE
WHERE SNO =@SNO 

EXEC SEARCH2--由于该存储过程的参数有默认值，所以查询的时候可以传递参数，也可以不传递参数

--5.创建带输出参数的存储过程

CREATE PROC TEST1--该存储过程用于计算传递进来的数的阶乘并返回值
@X INT ,@Y INT OUTPUT--定义参数，后跟OUTPUT表示是传出参数
AS
DECLARE @I INT ,@T INT--变量i用于不断增加阶乘数，变量t用于保存阶乘后的值
SELECT @I=1,@T=1--初始化变量
WHILE @I<=@X--条件
BEGIN
SELECT @T=@T*@I
SELECT @I=@I+1
END
SELECT @Y=@T--将阶乘后的值赋给传出参数y

DECLARE @FACT INT--定义参数用于接收存储过程返回的值
EXEC TEST1 5,@FACT OUTPUT--传递两个参数，FACT用于接收返回值
SELECT @FACT--显示fact的值

--6.创建带多条SQL语句的存储过程

--------------------修改存储过程----------------

ALTER PROC SEARCH2 --将创建存储过程的关键字换为ALTER即可
@NAME VARCHAR(10)
AS
SELECT * FROM STUDENT 
WHERE @NAME =SNAME 

EXEC SEARCH2 '王默飞'

-----------------删除存储过程--------------------

DROP PROC SEARCH2

--------------使用系统存储过程---------

SP_HELP STUDENT







------------------------------------------------用户自定义函数------------------------------------------------------------
--分类：  1.标量函数   2.表值函数

--1.标量函数
CREATE FUNCTION FUN1(@NO VARCHAR(12))--定义函数fun1，后面括号内是需要提供的参数
RETURNS VARCHAR(12)--函数返回值类型
AS
BEGIN--开始函数体
RETURN(SELECT SNAME FROM STUDENT WHERE SNO =@NO)--根据提供的学号查找学生的姓名并返回
END

SELECT DBO.FUN1 ('6310410102') AS 姓名--执行函数，在执行自定义函数时必须在函数名前面加上DBO

--2.表值函数，其返回结果是一张表
--  2.1内嵌函数
CREATE FUNCTION FUN2(@SEX VARCHAR(2))
RETURNS TABLE--函数的返回值是一张表
AS
RETURN (SELECT SNO,SNAME,SSEX ,CLASSNO FROM STUDENT WHERE  SSEX =@SEX )--返回所有女士的信息表

SELECT * FROM FUN2('女')--由于函数返回的是一张表,所以用查询语句将函数想表一样查询

--   2.2多语句函数

CREATE FUNCTION FUN3(@NAME VARCHAR(12))
RETURNS @TEMP TABLE--定义一个变量temp ,它的类型是一张表
			  (
			    学号 VARCHAR(12),
			    姓名 VARCHAR(23),--这里是表的结构,相当于临时构建的一张表
			    性别 VARCHAR(2 ),
			    专业 VARCHAR(40),
			    系别 VARCHAR(40)
			   )
AS
BEGIN--函数体开始
INSERT INTO @TEMP --将查询结果插入刚才新建的表TEMP
SELECT SNO,SNAME ,SSEX ,STUDENT.CLASSNO ,DEPT --返回的字段需要和TEMP表的字段相同
FROM STUDENT 
	 INNER JOIN CLASS 
	 ON STUDENT .CLASSNO=CLASS .CLASSNO
WHERE STUDENT .SNAME =@NAME --根据学生的姓名查询他的信息
RETURN --返回
END

SELECT * FROM FUN3('杨敏')--查询

------------------------查看与修改用户自定义函数---------

ALTER FUNCTION FUN2(@SEX VARCHAR(2))
RETURNS TABLE--函数的返回值是一张表
AS
RETURN (SELECT SNAME FROM STUDENT WHERE  SSEX =@SEX )--修改了原来FUN2函数中的返回信息,这里只返回女生的名字,如果要修改其它功能可随意修改

SELECT * FROM FUN2('男')

DROP FUNCTION FUN3 --删除函数







-------------------------------------------------------游标-----------------------------------------------------------------
--作用：允许从当前检索一行或多行数据
--      允许操作当前行列数据
--		允许定位在特定的行上面
--		遍历查询的结果集

--使用方法:声明游标，打开游标，遍历游标，关闭游标~

DECLARE CUR_STU CURSOR--创建游标
FOR
SELECT SNO,SNAME FROM STUDENT --游标的内容
WHERE SNO>'06310410102' AND SNO<'06310410129'--将学号在规定范围内的记录作为游标的内容
-------------------------------------------------------------------------------------------------------------------------------------
OPEN CUR_STU --打开游标

DECLARE @NO VARCHAR(12),@NAME VARCHAR(12)--定义这两个变量用于临时存放游标内的记录

PRINT '游标结果集中的记录总数为'+CAST(@@CURSOR_ROWS AS VARCHAR(20))--全局变量@@cursor_rows存放了游标内的记录数

FETCH NEXT FROM CUR_STU INTO @NO,@NAME--定位游标
WHILE @@FETCH_STATUS =0--通过while循环将游标内的记录都显示一遍
BEGIN
PRINT '学号：'+@NO+'姓名：'+@NAME--因为上面已经为游标定位了，所以可以线输出第一条记录
FETCH NEXT FROM CUR_STU INTO @NO ,@NAME--再将游标指向下一条记录，通过循环可以遍历所有记录
END
CLOSE CUR_STU--关闭游标
DEALLOCATE CUR_STU--释放游标资源，即删除游标
------------------------------------------------------------------------------------------------------------------------------------------
DELETE FROM STUDENT 
WHERE CURRENT OF CRU_STU


