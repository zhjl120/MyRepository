
----------------------------约束------------------------
--创建主键约束
alter table studentinfo 
add 
constraint pk_course PRIMARY KEY --添加主键
(
	stuno,stuname --主键由这两个字段构成
)

--增加外键约束
alter table score
add 
constraint fk_course foreign key(stuno) --增加外键约束（stuno为键值，fk_course为约束的名称）
references studentinfo(stuno)--主键所在表及主键字段

--检查约束
alter table score
add
constraint ck_course --检查约束名称为ck_course
check(stuno like '1%')





-------------------------事务------------------------------
--显示事务
begin transaction tr_score  --开始事务，tr_score是事务名称
insert into score (stuno,score) values (1,'93')
insert into score (stuno,score) values (2,'88')--可以做各种各样的操作
insert into score (stuno,score) values (3,'67')
commit transaction tr_score --提交事务，在事务开始之后所做的操作只有在提交之后才能保存到数据库，如果没有提交或在操作中出现问题，则从begin后的所有操作都不会产生影响

--自动提交事务

--隐式事务
set  implicit_transactions on --开启隐式事务
insert into test1.dbo.score(stuno,score)values (4,65)--开始后进行操作
commit  --提交事务
set  implicit_transactions off --关闭隐式事务

--事务保存点
save transaction savepoint_1 --设置在事务中的保存点，对于大量操作来说，在能够确定某一部分操作能顺利完成时可以在它后面设上保存点，当后面的操作出现错误时不用使先前
							 --所有的操作都变得无效，而只是回滚到保存点的位置，由此避免重复操作。类似于设置系统还原点
rollback transaction savepoint_1  --回滚到事务保存点savepoint_1



---------------------索引-------------------------------
create unique index inx_score --创建一个唯一非聚集索引，名称为inx_score
on score(stuno)  --使用score表中的stuno字段为这个索引

sp_helpindex score --使用触发器sp_helpindex查询score表中的索引

alter index inx_score  --修改指定索引为禁用
on score disable    --将score表中的索引inx_score设为禁用，但是并没有删除它

alter index inx_score  --修改指定索引为启用
on score rebuild    --将score表中的索引inx_score设为启用

drop index inx_score   --删除指定索引

sp_rename 'score.inx_score','ix_score','index'  --重命名索引inx_score为ix_score

