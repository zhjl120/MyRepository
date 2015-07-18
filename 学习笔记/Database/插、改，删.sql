
----------------------插入----------------------------

INSERT INTO nddzb (起始年份,终止年份,年代)--插入时表名后面跟字段名，如果是录入整条记录则可以省略字段名，直接添加值
VALUES ('1992-08-09','1993-09-01',90)--录入的值需要同表后的字段名类型匹配，且个数一样

INSERT INTO nddzb (终止年份,年代)--录入特定字段需要在表名后跟上字段名
VALUES ('1993-09-01',90)

INSERT INTO nddzb 
SELECT * FROM nddzb WHERE 年代='60'--将查询的记录插入到表中

INSERT INTO nddzb (起始年份,终止年份)--只将查询记录中特定的字段插入到表中，需指定需要字段
SELECT 起始年份,终止年份 FROM nddzb WHERE 年代='70'

-----------------------更新-----------------------------
--  UPDATE 表名  
--  SET 字段名=更新值  
--  WHERE 条件           用于筛选满足条件的记录

UPDATE nddzb 
SET 终止年份='1992-08-09' --将满足条件记录的终止年份字段修改为‘1992-08-09’
WHERE 起始年份 ='1970-01-01'--设置筛选条件

UPDATE nddzb 
SET 终止年份='1888-09-08',起始年份='1777-08-09'--更新多个字段用逗号隔开
WHERE 年代 ='60'

UPDATE SCORE   --将杜敏的大学英语成绩加10分，由于在STUDENT表中并没有学生的成绩，所以需要对STUDENT表和SCORE做连接，以查找到杜敏的大学英语成绩
SET GRADE =GRADE + 10 --将成绩加10
FROM SCORE ,STUDENT --记录来自两张表
WHERE STUDENT .SNAME='杜敏'--设定筛选记录的条件，姓名是杜敏，科目是大学英语
AND SCORE.COURSE='大学英语'
AND SCORE.SNO=STUDENT .SNO--两表连接的条件


UPDATE nddzb --将年代是60的记录都将年代字段设为NULL，相当与删除了内容
SET 年代=NULL --设为NULL的字段必须允许空才能实现删除
WHERE 年代='60'

UPDATE nddzb 
SET 起始年份=NULL,终止年份=NULL --同时删除多个字段
WHERE 年代='70'


----------------------删除------------------------------

DELETE FROM SNONAME --删除表内全部记录（表还是存在的）

DELETE FROM SNONAME --删除特定的记录，通过学号标识该学生的记录
WHERE SNO ='10315110201'

DELETE STUDENT --删除STUDENT表中'谭棋予'的记录
FROM STUDENT ,SCORE --这里设置两张表并没有实际意义，因为删除的只是STUDENT表中的记录，而没有删除SCORE表中的记录，这里做连接只是起演示作用
WHERE STUDENT .SNO=SCORE .SNO
AND STUDENT .SNAME='谭棋予' 


--TRUNCATE是将表中所有数据删除，而DELETE不仅可以删除全部记录，还可以进行有条件的删除
--但在执行效率上TRUNCATE比DELETE高
--TRUNCATE之所以效率高是因为执行它时SQL SERVER不会将其操作写进日志文件，也就是说TRUNCATE删除操作是不能回滚的，而DELETE删除是可以恢复的

TRUNCATE TABLE  表名  --直接删除表内全部内容

