
--1.使用无连接规则连接两表

SELECT * FROM SCORE ,CLASS --使用无连接规则连接两表，它们的结果是所有字段加在一起，记录是两张表中记录的乘积

--2.有连接规则连接两表，它是有条件的（加上where子句），两个表中有公共的字段作为连接的条件
--  只有两个表有共同的字段才能使用等值连接
SELECT STUDENT .SNO,STUDENT .SNAME,STUDENT .SSEX,STUDENT .CLASSNO,SCORE.COURSE,SCORE .GRADE
FROM STUDENT ,SCORE 
WHERE STUDENT .SNO=SCORE .SNO--以两张表中相同的字段sno作为连接条件

SELECT a .SNO,a .SNAME,a .SSEX,a .CLASSNO,b.COURSE,b .GRADE
FROM STUDENT a,SCORE b --可使用别名来代替表名，在表名过长的情况下可以简化操作，操作中使用别名时就不能在使用原名了，所有表名都需要改成别名
WHERE a.SNO=b .SNO--以两张表中相同的字段sno作为连接条件

--3.多表连接查询

SELECT STUDENT .SNO,STUDENT.SNAME,STUDENT .SSEX,STUDENT .CLASSNO,CLASS .DEPT,SCORE .GRADE,SCORE .COURSE--想要查询的字段
FROM STUDENT ,SCORE ,CLASS--来自3张表
WHERE STUDENT .SNO=SCORE .SNO AND STUDENT .CLASSNO=CLASS .CLASSNO--各表之间的联系
ORDER BY SNO--以学号排序

--4.INNER JION连接查询  （又叫做 内部连接或内连接）

SELECT STUDENT .SNO,STUDENT.SNAME,STUDENT .SSEX,STUDENT .CLASSNO,CLASS .DEPT,SCORE .GRADE,SCORE .COURSE--想要查询的字段
FROM STUDENT 
INNER JOIN SCORE-- 连接的表
ON STUDENT .SNO=SCORE .SNO--连接的条件
INNER JOIN CLASS--连接的表
ON STUDENT.CLASSNO=CLASS .CLASSNO--连接的条件
ORDER BY STUDENT .SNO DESC 


----------------------高级连接查询----------------
--1.自连接
SELECT * 
FROM STUDENT A,STUDENT B--为同一个表设置两个别名，做自连接
WHERE A.SNO=B.SNO
      AND A.SNAME='叶颜军'--设置选择条件
 
--2.内连接   只返回两个表中不相同的记录
--    包括:  等值连接，自然连接，不等值连接

--。。。。

--3.左外连接，它返回连接语句左边的全部记录和连接符右边表中与左边相同的记录

SELECT 字段名  FROM 表1  --返回两表的相同记录和表1的全部记录
LEFT OUTER JION 表2
ON 连接条件

--4.右外连接 
SELECT 字段名 FROM 表1--返回两表相同的记录和表2的全部记录
LEFT OUTER JION 表2
ON 连接条件

--5.全外连接   返回两个表中的所有内容，两表中没有匹配的记录会以空值的形式出现
SELECT 字段名 FROM 表1
FULL OUTER JION 表2
ON 连接条件

--6.交叉连接   即返回两表中记录的乘积
SELECT 字段名 FROM 表1
CROSS JION 表2

------------------------组合查询----------------------
--将多个select语句的结果组合在一起，并且将多个语句的查询结果放到一个结果里面

SELECT * FROM STUDENT WHERE SNAME ='李刚' --将查询结果组合到一起需要它们的字段数目一样，且每个字段的类型兼容
UNION --使用UNION 是会去除重复值的，如果希望它不去除重复值，需要在其后面加上ALL
--UNION ALL
SELECT * FROM STUDENT WHERE SNO='6310410102'

SELECT * FROM SCORE WHERE GRADE=99 AND COURSE ='体育'--讲个查询的结果结合到一起,并以学号排序,ORDER BY必须放在所有语句的末尾
UNION
SELECT * FROM SCORE WHERE SNO ='6320210611'
ORDER BY SNO


-------------------------子查询------------------------
--一条查询语句当中包含另一条查询语句

SELECT * FROM SCORE 
WHERE GRADE =(SELECT  MIN(GRADE) FROM SCORE )--在查询的条件中再插入一条查询语句查询最小的成绩,以给前面的查询语句提供条件


