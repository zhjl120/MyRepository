------------------------------������ͼ-----------------------------

--1.��ͼ:��ͼ��һ�����������Ϊ������ԭ���ǣ���ͼ�ڵ����ݲ�������ͼ���������ڴ�����ͼʱ�õ��Ļ�����
--       ������Ϊ����ͼ��һ�����е����ݾ���ĳ��ɸѡ�����ʾ��ʽ�����������е����ݾ���ɸѡ�����ʾ��ʽ��

CREATE VIEW VIEW1--����һ����ΪVIEW1����ͼ
AS --�����ѯ���
SELECT ��ʼ���,��ֹ��� FROM nddzb

SELECT * FROM VIEW_YEAR--��������ͼ�󣬿���ֱ�Ӷ������в�ѯ����ʡ�Ժܶ��ظ�����

CREATE VIEW VIEW_BOY--���Ա�Ϊ�еļ�¼����Ϊһ����ͼ
AS
SELECT * FROM STUDENT 
WHERE SSEX ='��'

CREATE VIEW VIEW_GIRL(ѧ��,����,�Ա�)--�ڴ�����ͼʱ����Ϊ��ͼ�ֶ�ȡ����
AS
SELECT SNO,SNAME,SSEX
FROM STUDENT 
WHERE SSEX ='Ů'

CREATE VIEW VIEW_GIRL2
AS
SELECT SNO AS ѧ�� ,SNAME AS ����,SSEX AS �Ա�--�ڴ�����ͼʱҲ�����ڲ�ѯ�����Ϊ��ͼ�ֶ�ȡ����
FROM STUDENT 
WHERE SSEX ='Ů'

--ע�⣺�ڴ�����ͼ��SELECT����в��ܰ�����COMPUTE,COMPUTE BY,ORDER BY,OPTION,INTO,��ʱ��,�����
SELECT * FROM INFORMATION_SCHEMA .VIEWS --�鿴���ݿ�����ͼ����Ϣ

CREATE VIEW VIEW_GIRL3
WITH ENCRYPTION--����һ��������ͼ,ϵͳ�������ض�����ͼ����䣬�������˾Ϳ�������ͼ��ʹ�õĻ��������ˣ��Ӷ���߰�ȫ��
AS
SELECT * FROM STUDENT 
WHERE SSEX ='Ů'


-----------------------------�鿴���޸���ͼ-------------------------

SELECT * FROM VIEW_GIRL3 --��ѯ��ͼ���ѯ����һ����

ALTER VIEW VIEW_GIRL3--�޸���ͼ�����ݣ������ѯ��������Ϊ����
AS 
SELECT  SNO,SNAME ,SSEX  FROM STUDENT --����Ĳ�ѯ��佫������ǰ�Ĳ�ѯ���
WHERE SSEX ='��'


----------------------------ʹ����ͼ����������----------------------

--1.����ͼ�и������ݣ���ԭ���е�����Ҳ�ᱻ����

INSERT INTO VIEW_GIRL3
--INSERT INTO VIEW_GIRL3(SNO,SNAME)  Ҳ�ɲ���ָ�����ֶ�
VALUES ('10315110201','�ٿ���','��')

--������������ͼ�����Ը�������
--��ѯ������Զ�������ͼ����ͼ���ܸ������ݣ����������������Ҳ���ܸ�������

UPDATE VIEW_GIRL3
SET SNAME ='����' --��ѧ����201��ѧ�������޸�Ϊ����
WHERE SNO='10315110201'

DELETE FROM VIEW_GIRL3--ɾ��������ͬʱҲɾ���˻����е�����
WHERE SNO='10315110201'

DROP VIEW VIEW_GIRL3--ɾ����ͼ
