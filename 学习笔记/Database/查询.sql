select * from STUDENT --查询表内全部内容

SELECT SNO,SNAME FROM STUDENT --查询表内特定字段,查询多个字段用逗号隔开

SELECT DISTINCT SNO,SNAME FROM STUDENT --distinct关键字用于去除重复记录 

SELECT SNO AS '学号',SNAME AS '姓名' FROM STUDENT --设置字段别名
SELECT SNO AS '学号', '' AS phone FROM STUDENT  --可添加新的字段（只是显示，并没有真的添加字段）

SELECT SNO ,SNAME INTO SNONAME FROM STUDENT--将查询结果保存到新表SNONAME中

SELECT SNO+SNAME AS '学号姓名' FROM STUDENT--将两个字段连接成一个新字段（注意两个字段的数据类型）

SELECT * FROM CLASS WHERE DEPT='计算机系' --查询表中属于计算机系的学生
SELECT * FROM SCORE WHERE GRADE>80 --查询表中成绩大于88的学生（还可用其它关系运算符，如，> < >= <= !=）
SELECT * FROM CLASS WHERE CLASSNO <>'可视化06103' --查询不是该专业以外的所有学生

SELECT * FROM SCORE WHERE GRADE BETWEEN 90 AND 100--查询成绩在90到100之间的学生，使用between关键字（注意它是包含起始值和结束值的）
SELECT * FROM SCORE WHERE GRADE >=90 AND GRADE <=100 --效果同上

SELECT * FROM SCORE WHERE GRADE IN(77,88,99) --查询成绩是88和99的学生
SELECT * FROM SCORE WHERE GRADE =88 OR GRADE =99 OR GRADE =77--效果同上

SELECT * FROM SCORE WHERE SNO IS NULL --查询表中有NULL值的记录
SELECT * FROM SCORE WHERE SNO IS NOT NULL --查询表中有非NULL值的记录

--------------------排序----------------------

SELECT * FROM SCORE ORDER BY SNO --以学号进行排序（默认是升序）
SELECT * FROM SCORE ORDER BY SNO DESC --以降序进行排序,DESC是降序的关键字，ASC是升序排列

SELECT * FROM SCORE ORDER BY SNO DESC ,GRADE --以多个字段进行排列，只有当第一个字段出现相同值时，才会用第二个字段进行排序

SELECT TOP 5 SNO,COURSE ,GRADE  FROM SCORE  ORDER BY SNO --查询前五条记录

SELECT TOP 5 PERCENT SNO,COURSE ,GRADE  FROM SCORE  --查询表中前5%的记录，PERCENT是百分百关键字

SELECT * FROM SCORE WHERE GRADE >90 ORDER BY GRADE  DESC--where语句与order by语句的结合使用，它是先筛选满足where条件的记录，再对它们进行排序


---------------------高级条件查询---------------------------------

SELECT * FROM SCORE WHERE COURSE ='大学英语' AND GRADE =66  ORDER BY SNO  --AND 语句表示多个条件同时满足

SELECT * FROM SCORE WHERE GRADE =77 OR GRADE=66 -- OR语句 只要满足任意条件即可

SELECT * FROM SCORE WHERE GRADE =66 OR COURSE ='大学英语' AND GRADE  =77--AND和OR的优先级是AND优先，使用中最好用括号将特定关系括在一起

SELECT * FROM SCORE WHERE GRADE NOT BETWEEN 70 AND 100 --NOT就是对结果取反的意思，即将成绩不在70到100之间的记录显示出来

SELECT * FROM STUDENT  WHERE SNAME LIKE '张%'--查询表中姓张的记录
SELECT * FROM STUDENT  WHERE SNAME LIKE '%伟%'--查询姓名中含有伟字的记录

SELECT * FROM STUDENT  WHERE SNAME LIKE '张_'--下划线_代表一个字符，表示名字是姓张的，且只有两个字的名字的记录
SELECT * FROM STUDENT  WHERE SNAME LIKE '张__'--两个下划线表示两个字符，即姓张的，且名字是三个字的记录

SELECT * FROM STUDENT WHERE SNAME LIKE '[张李]%' --查询姓张或姓李的记录
SELECT * FROM STUDENT WHERE SNAME LIKE '[^张李]%' --查询除了姓张或姓李的以外的记录

--通配符 中括号[] 使用： [nr]% 表示只要是以n或r开头的记录都可以被查询
--						 [a-e]% 表示只要开头是a到e的记录都可以被查询
--						 [^b]% 表示除了开头是b的记录都可以被查询

--  LIKE '%5#%%' ESCAPE '#'  定义转意字符#，表示在#后面紧跟的符号不是通配符，而是需要查询的符号，这句的意思即是：查询包含字符串‘5%’的记录
