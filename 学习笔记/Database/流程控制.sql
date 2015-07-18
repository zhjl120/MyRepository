
---------------------Transact-SQL--------------------

------------运算符------------------
--算数运算符 :   + - * / %
--赋值运算符 :   =
--位运算符   :   &  |  ^  按位与 按位或 按位异或
--比较运算符 :   > < >= <= != !< !>
--逻辑运算符 :   ALL (全部为TRUE才为TRUE) 
--			     AND (满足所有条件才为TRUE)
--			     ANY (任何一个条件满足就为TRUE)
--				 BETWEEN(只要满足在它规定的范围内就为TRUE)
--				 EXISTS(如果子查询不为空则返回TRUE)
--				 IN (如果操作数等于表达式中的任何一个就为TRUE)
--				 LIKE(用于模糊查询)
--				 NOT(表示非 ，对布尔运算取反)
--				 OR(表示或)
--				 SOME(如果在操作数中有一些为TRUE则为TRUE)

--字符串连接运算符: +(连接两个字符串)
--一元运算符      : +(正) -(负)



---------------------常量，变量--------------------

--1.常量  

SELECT GRADE+5 FROM SCORE --并不改变值，这里的5就是常量

--2.变量
--局部变量：用一个@号表示   全局变量：用两个@号表示，全局变量是系统定义的变量，用户只能使用它，而不能自定义全局变量

DECLARE @ABC VARCHAR(20)--定义VARCHAR型变量ABC
DECLARE @BCD INT   
DECLARE @CDE CHAR(5) --定义了3个变量   
SET @ABC ='1234567'--使用SET为变量赋值，SET一次只能为一个变量赋值
SELECT @BCD =123,@CDE ='HELLO'--还可用SELECT 为多个变量赋值
PRINT @ABC--打印变量
PRINT @CDE
PRINT @BCD

DECLARE @NAME VARCHAR(20)--定义变量
SELECT @NAME=SNAME--将查询的结果赋给变量
FROM STUDENT 
WHERE SNO='6310910329'
PRINT @NAME--显示变量

--常用的全局变量

SELECT * FROM STUDENT 
PRINT '一共查询了'+CAST(@@ROWCOUNT AS VARCHAR(5))+'条记录'--加号是字符串连接符,CAST用于转换类型(将全局变量转换为字符型)然后输出
SELECT @@ERROR 
SELECT @@CPU_BUSY													  --全局变量@@ROWCOUNT存储了查询的记录的条数,即上一条语句的查询记录的条数
					

-----------------------流程控制语句------------------
--BEGIN ... END   标记一个程序语句块的开始和结束
--IF...ELSE
--WHILE
--BREAK
--CONTINUE
--WAITFOR
--CASE	


----IF ELSE---

DECLARE @X REAL,@Y REAL,@Z REAL--定义三个变量
SELECT @X=9,@Y=5   --为XY赋值
IF @Y!=0	--判断除数是否不为0
BEGIN	--如果不为0，则开始执行语句快
SELECT @Z=@X/@Y	 --将x除以y的值赋给z
PRINT '结果为'+CAST(@Z AS CHAR)--将z转换为字符类型并输出
END	--语句块结束
ELSE--否则，即Y的值为0，则执行下面的语句块
BEGIN --如果ELSE后面只有一条语句，则可以省略BEGIN和END，它们就相当与C语言里else后面的大括号
PRINT '除数不能为0'
END

----WHILE-----

DECLARE @X INT ,@SUN INT--不能定义已经定义了的变量名
SELECT @X=1,@SUN=0
WHILE @X<=100
BEGIN 
SELECT @SUN =@SUN+@X
SELECT @X=@X+1
END
PRINT '结果为:'+CAST(@SUN AS CHAR)


-----BREAK--------
DECLARE @X INT
SELECT @X=1
WHILE @X<=10
BEGIN
  IF @X=5--判断x是否为5,如果是则跳出循环
     BREAK
  ELSE
    BEGIN
     PRINT CAST(@X AS CHAR)
     SELECT @X=@X+1
    END
END		 

----CONTINUE-----

DECLARE @X INT
SELECT @X=0;
WHILE @X <10
BEGIN 
	SELECT @X=@X+1
	IF @X%2=0
	   CONTINUE
	PRINT CAST(@X AS CHAR)
END
	  
	  
---WAITFOR------在一段指定的时间之后执行下一个语句块

WAITFOR DELAY '00:00:10'--在10秒后开始执行后面的语句
SELECT * FROM STUDENT 

---CASE--------

SELECT 
	CASE--表示进入选择状态，整个CASE语句相当于返回一个满足条件的值
	WHEN GRADE>=80 THEN '优秀'--当WHEN后面的条件满足时就返回'优秀'，否则执行下一条语句
	WHEN GRADE>=70 THEN '良好'
	WHEN GRADE>=60 THEN '及格'
	ELSE '不及格'--如果前面的条件都不符合就有返回ELSE后面的值
	END
FROM SCORE 

SELECT *,  --改进后的查询，返回所有的字段，并将查询的结果添加到新字段中
	CASE
	WHEN GRADE>=80 THEN '优秀'
	WHEN GRADE>=70 THEN '良好'
	WHEN GRADE>=60 THEN '及格'
	ELSE '不及格'
	END AS 等级 --为新的字段取一个别名
FROM SCORE 