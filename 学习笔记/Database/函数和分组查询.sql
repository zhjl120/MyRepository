---------------系统函数-------------------

--1.聚合函数：系统函数中最常用的函数，主要是对一组值进行计算，然后返回一个值。
--  主要包括：SUM , AVG ,MIN ,MAX, COUNT

SELECT SUM(GRADE) FROM SCORE --返回所有成绩的和
SELECT AVG(GRADE) FROM SCORE --返回平均成绩
SELECT MIN(GRADE) FROM SCORE --返回最小成绩
SELECT MAX(GRADE) FROM SCORE --返回最大成绩
SELECT COUNT (SNO) FROM SCORE --返回记录总数

--2.类型转换函数
--  主要包括：CONVERT ,CAST

SELECT CONVERT (CHAR,GETDATE(),101)--GETDATE函数用于获取当前时期，CONVERT函数用于将日期转换为字符串,最后一个参数用于设置时间显示的风格
SELECT CAST (GETDATE() AS CHAR(10))--将当前日期转换为10个字符的字符串

--3.日期函数
--  主要包括：GETDATE,DATEADD,DATEDIFF,DATENAME,DATEPART

SELECT GETDATE ()--获取当前时间
SELECT DATEADD (YEAR,5,GETDATE())--在指定日期上加上一段指定的时间，该句返回在当前日期上加上5年后的时间，第一个参数可选:YEAR,QUARTEER,MONTH,WEEK,DAY,HOUR,MINUTE,SECOND
SELECT DATEDIFF (YEAR,'1992-08-09',GETDATE ())--获取两个日期的差，第一个参数取值同上
SELECT DATENAME (MONTH ,GETDATE ())--以字符串形式返回指定的日期段，该句即返回当前的月份
SELECT DATEPART (DAY,GETDATE())--以整数形式返回指定日期的日期段，该句即返回当前是几号



------------------分组查询----------------------
SELECT DEPT  FROM CLASS GROUP BY DEPT --将指定字段进行分组（去掉重复值），它针对的是某一个字段内的值
SELECT SSEX,COUNT (SSEX) AS '人数' FROM STUDENT GROUP BY SSEX --按性别进行分组，并统计男女各多少人

SELECT CLASSNO, REPLICATE('=',COUNT(*))AS '人数对比 ' FROM STUDENT GROUP BY CLASSNO --将每个班级分组，并使用REPLICATE关键字将每班人数用直方图的形式表现出来

SELECT CLASSNO,COUNT(*) AS '人数' FROM STUDENT  GROUP BY CLASSNO ORDER BY COUNT(*)--以班级分组，统计各班人数，并按人数的多少排序

SELECT CLASSNO,SSEX,COUNT(*) AS '人数' 
FROM STUDENT
GROUP BY CLASSNO,SSEX 
ORDER BY CLASSNO --按班级和性别分组，并统计各班男女人数，按班级排序

SELECT CLASSNO,
	   COUNT(CASE
				WHEN SSEX='男' THEN 1
				ELSE NULL END) AS '男生人数',
	   COUNT(CASE
			    WHEN SSEX='女' THEN 1
				ELSE NULL END) AS '女生人数'
FROM STUDENT
GROUP BY CLASSNO

SELECT CLASSNO,COUNT(*)AS '人数'
FROM STUDENT 
GROUP BY CLASSNO --按班级进行分组
HAVING CLASSNO IN('多媒体06101','游戏07103')--在分组中过滤出想要查看的分组
ORDER BY COUNT(*)--有时候只想查看想要的分组统计信息，而不是全部的分组统计，这就可以使用HAVING语句来过滤分组

SELECT CLASSNO,COUNT(*)AS '人数'--效果同上，这里采用where语句进行筛选
FROM STUDENT
WHERE CLASSNO IN ('多媒体06101','游戏07103')--筛选想要查看的分组
GROUP BY CLASSNO --按班级进行分组
ORDER BY COUNT(*)DESC--按升序排列