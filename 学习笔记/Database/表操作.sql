create table stuinfo--������
(
	stuno int not null,   --��ʽ: ���� �������� Լ��
	stuname varchar(20) not null,
	stusex varchar(2),
	stumajor varchar(30),
	stutel varchar(20)
)

create table stuinfopk --������
(
	stuno int PRIMARY KEY,  --����ѧ����Ϊ����
	stuname varchar(20) not null,
	stusex varchar(2),
	stumajor varchar(30),
	stutel varchar(20)
)

--�޸����ݱ�ṹ

alter table stuinfo  
add sturemarks varchar(50) --����һ�����ֶ� 

alter table stuinfo
alter column sturemarks varchar(20)  --�޸�һ�������ֶ�

alter table stuinfo
drop column sturemarks  --ɾ��һ���ֶ�


drop table stuinfopk  --ɾ��������������һ��ɾ���ˣ�
truncate table stuinfo  --ֻɾ�����е����ݣ�����ɾ������

sp_rename stuinfo,studentinfo  --ʹ�ô洢������������