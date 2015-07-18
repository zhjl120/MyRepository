
-------------创建登录用户-----------------------------
create login "ROSS\zhjl120" from windows--创建一个以Windows验证的登录用户
create login "zhjl" with password='123'  --创建一个以sqlserver验证的登录用户


-------------创建数据库用户---------------------------
create user zhjl for login zhjl20  --创建一个以zhjl120登录名映射的数据库用户

grant create table to zhjl --给zhjl这个用户授予创建数据表的权限

grant insert ,update,delete
on object::test1.score
to zhjl --为用户zhjl在数据库test1下的score表中增加插入，更新，删除权限

deny insert ,update,delete
on object::test1.score
to zhjl --设置用户zhjl在数据库test1下的score表中 ，拒绝其拥有插入，更新，删除权限

revoke create table to zhjl --取消用户zhjl的创建表的权限