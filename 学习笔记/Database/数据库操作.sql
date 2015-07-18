CREATE DATABASE TEST2 --最简单的创建数据库语句

ALTER DATABASE TEST2--修改数据库test2的名字为test3
MODIFY NAME=TEST3

ALTER DATABASE TEST3
ADD FILE(NAME=TEST3_1,FILENAME='f:\DATABASE\test3_1.ndf')--添加数据库文件并放到指定目录下

DROP DATABASE TEST3 --删除数据库

--练习1----------------
CREATE DATABASE dbtest
ON--设置数据库属性
(
NAME='dbtest',--数据库文件名
FILENAME='F:\DATABASE\dbtest.mdf',--数据库文件存放路径
size=8mb,--文件大小
maxsize=16mb,--最大大小
filegrowth=5%--增长比例
)
alter database dbtest--修改数据库
add log file--增加日志文件
(
	name=dbtest201,--日志文件的名字
	filename='f:\DATABASE\dbtest201.ldf',--存放路径，ldf是日志文件格式
	size=2mb,--大小
	maxsize=50mb,--最大大小
	filegrowth=10%--文件增长率
)