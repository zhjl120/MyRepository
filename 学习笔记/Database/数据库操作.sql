CREATE DATABASE TEST2 --��򵥵Ĵ������ݿ����

ALTER DATABASE TEST2--�޸����ݿ�test2������Ϊtest3
MODIFY NAME=TEST3

ALTER DATABASE TEST3
ADD FILE(NAME=TEST3_1,FILENAME='f:\DATABASE\test3_1.ndf')--������ݿ��ļ����ŵ�ָ��Ŀ¼��

DROP DATABASE TEST3 --ɾ�����ݿ�

--��ϰ1----------------
CREATE DATABASE dbtest
ON--�������ݿ�����
(
NAME='dbtest',--���ݿ��ļ���
FILENAME='F:\DATABASE\dbtest.mdf',--���ݿ��ļ����·��
size=8mb,--�ļ���С
maxsize=16mb,--����С
filegrowth=5%--��������
)
alter database dbtest--�޸����ݿ�
add log file--������־�ļ�
(
	name=dbtest201,--��־�ļ�������
	filename='f:\DATABASE\dbtest201.ldf',--���·����ldf����־�ļ���ʽ
	size=2mb,--��С
	maxsize=50mb,--����С
	filegrowth=10%--�ļ�������
)