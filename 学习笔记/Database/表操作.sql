create table stuinfo--创建表
(
	stuno int not null,   --格式: 列名 数据类型 约束
	stuname varchar(20) not null,
	stusex varchar(2),
	stumajor varchar(30),
	stutel varchar(20)
)

create table stuinfopk --创建表
(
	stuno int PRIMARY KEY,  --设置学号列为主键
	stuname varchar(20) not null,
	stusex varchar(2),
	stumajor varchar(30),
	stutel varchar(20)
)

--修改数据表结构

alter table stuinfo  
add sturemarks varchar(50) --增加一个新字段 

alter table stuinfo
alter column sturemarks varchar(20)  --修改一个已有字段

alter table stuinfo
drop column sturemarks  --删除一个字段


drop table stuinfopk  --删除表（连表内数据一并删掉了）
truncate table stuinfo  --只删除表中的数据，并不删除表本身

sp_rename stuinfo,studentinfo  --使用存储过程重命名表