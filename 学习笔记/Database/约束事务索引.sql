
----------------------------Լ��------------------------
--��������Լ��
alter table studentinfo 
add 
constraint pk_course PRIMARY KEY --�������
(
	stuno,stuname --�������������ֶι���
)

--�������Լ��
alter table score
add 
constraint fk_course foreign key(stuno) --�������Լ����stunoΪ��ֵ��fk_courseΪԼ�������ƣ�
references studentinfo(stuno)--�������ڱ������ֶ�

--���Լ��
alter table score
add
constraint ck_course --���Լ������Ϊck_course
check(stuno like '1%')





-------------------------����------------------------------
--��ʾ����
begin transaction tr_score  --��ʼ����tr_score����������
insert into score (stuno,score) values (1,'93')
insert into score (stuno,score) values (2,'88')--���������ָ����Ĳ���
insert into score (stuno,score) values (3,'67')
commit transaction tr_score --�ύ����������ʼ֮�������Ĳ���ֻ�����ύ֮����ܱ��浽���ݿ⣬���û���ύ���ڲ����г������⣬���begin������в������������Ӱ��

--�Զ��ύ����

--��ʽ����
set  implicit_transactions on --������ʽ����
insert into test1.dbo.score(stuno,score)values (4,65)--��ʼ����в���
commit  --�ύ����
set  implicit_transactions off --�ر���ʽ����

--���񱣴��
save transaction savepoint_1 --�����������еı���㣬���ڴ���������˵�����ܹ�ȷ��ĳһ���ֲ�����˳�����ʱ���������������ϱ���㣬������Ĳ������ִ���ʱ����ʹ��ǰ
							 --���еĲ����������Ч����ֻ�ǻع���������λ�ã��ɴ˱����ظ�����������������ϵͳ��ԭ��
rollback transaction savepoint_1  --�ع������񱣴��savepoint_1



---------------------����-------------------------------
create unique index inx_score --����һ��Ψһ�Ǿۼ�����������Ϊinx_score
on score(stuno)  --ʹ��score���е�stuno�ֶ�Ϊ�������

sp_helpindex score --ʹ�ô�����sp_helpindex��ѯscore���е�����

alter index inx_score  --�޸�ָ������Ϊ����
on score disable    --��score���е�����inx_score��Ϊ���ã����ǲ�û��ɾ����

alter index inx_score  --�޸�ָ������Ϊ����
on score rebuild    --��score���е�����inx_score��Ϊ����

drop index inx_score   --ɾ��ָ������

sp_rename 'score.inx_score','ix_score','index'  --����������inx_scoreΪix_score

