---------------------------�洢����-----------------

--1.�����洢����

CREATE PROC STU --����һ���洢����
AS
SELECT * FROM STUDENT --�洢�����еĲ���

--2.ִ�д洢����

EXEC STU--ִ�д洢���̣�EXEC��EXECUTE�ļ�д��������ִ�д洢����

--3.�����������Ĵ洢����

CREATE PROC SEARCH --����洢����
@SNO VARCHAR(12) --��������Ҫ�Ĳ���������
AS 
SELECT * FROM SCORE 
WHERE SNO =@SNO --��������Ϊ��ѯ������ʹ��

EXEC SEARCH '6320210603 '--ִ�д������Ĵ洢����

--4.������Ĭ��ֵ�����Ĵ洢����

CREATE PROC SEARCH2 --��Ĭ��ֵ�����Ĵ洢����
@SNO VARCHAR(12) ='6320210603'--�ڴ����洢���̵�ʱ���Ϊ��������Ĭ��ֵ
AS 
SELECT * FROM SCORE
WHERE SNO =@SNO 

EXEC SEARCH2--���ڸô洢���̵Ĳ�����Ĭ��ֵ�����Բ�ѯ��ʱ����Դ��ݲ�����Ҳ���Բ����ݲ���

--5.��������������Ĵ洢����

CREATE PROC TEST1--�ô洢�������ڼ��㴫�ݽ��������Ľ׳˲�����ֵ
@X INT ,@Y INT OUTPUT--������������OUTPUT��ʾ�Ǵ�������
AS
DECLARE @I INT ,@T INT--����i���ڲ������ӽ׳���������t���ڱ���׳˺��ֵ
SELECT @I=1,@T=1--��ʼ������
WHILE @I<=@X--����
BEGIN
SELECT @T=@T*@I
SELECT @I=@I+1
END
SELECT @Y=@T--���׳˺��ֵ������������y

DECLARE @FACT INT--����������ڽ��մ洢���̷��ص�ֵ
EXEC TEST1 5,@FACT OUTPUT--��������������FACT���ڽ��շ���ֵ
SELECT @FACT--��ʾfact��ֵ

--6.����������SQL���Ĵ洢����

--------------------�޸Ĵ洢����----------------

ALTER PROC SEARCH2 --�������洢���̵Ĺؼ��ֻ�ΪALTER����
@NAME VARCHAR(10)
AS
SELECT * FROM STUDENT 
WHERE @NAME =SNAME 

EXEC SEARCH2 '��Ĭ��'

-----------------ɾ���洢����--------------------

DROP PROC SEARCH2

--------------ʹ��ϵͳ�洢����---------

SP_HELP STUDENT







------------------------------------------------�û��Զ��庯��------------------------------------------------------------
--���ࣺ  1.��������   2.��ֵ����

--1.��������
CREATE FUNCTION FUN1(@NO VARCHAR(12))--���庯��fun1����������������Ҫ�ṩ�Ĳ���
RETURNS VARCHAR(12)--��������ֵ����
AS
BEGIN--��ʼ������
RETURN(SELECT SNAME FROM STUDENT WHERE SNO =@NO)--�����ṩ��ѧ�Ų���ѧ��������������
END

SELECT DBO.FUN1 ('6310410102') AS ����--ִ�к�������ִ���Զ��庯��ʱ�����ں�����ǰ�����DBO

--2.��ֵ�������䷵�ؽ����һ�ű�
--  2.1��Ƕ����
CREATE FUNCTION FUN2(@SEX VARCHAR(2))
RETURNS TABLE--�����ķ���ֵ��һ�ű�
AS
RETURN (SELECT SNO,SNAME,SSEX ,CLASSNO FROM STUDENT WHERE  SSEX =@SEX )--��������Ůʿ����Ϣ��

SELECT * FROM FUN2('Ů')--���ں������ص���һ�ű�,�����ò�ѯ��佫�������һ����ѯ

--   2.2����亯��

CREATE FUNCTION FUN3(@NAME VARCHAR(12))
RETURNS @TEMP TABLE--����һ������temp ,����������һ�ű�
			  (
			    ѧ�� VARCHAR(12),
			    ���� VARCHAR(23),--�����Ǳ�Ľṹ,�൱����ʱ������һ�ű�
			    �Ա� VARCHAR(2 ),
			    רҵ VARCHAR(40),
			    ϵ�� VARCHAR(40)
			   )
AS
BEGIN--�����忪ʼ
INSERT INTO @TEMP --����ѯ�������ղ��½��ı�TEMP
SELECT SNO,SNAME ,SSEX ,STUDENT.CLASSNO ,DEPT --���ص��ֶ���Ҫ��TEMP����ֶ���ͬ
FROM STUDENT 
	 INNER JOIN CLASS 
	 ON STUDENT .CLASSNO=CLASS .CLASSNO
WHERE STUDENT .SNAME =@NAME --����ѧ����������ѯ������Ϣ
RETURN --����
END

SELECT * FROM FUN3('����')--��ѯ

------------------------�鿴���޸��û��Զ��庯��---------

ALTER FUNCTION FUN2(@SEX VARCHAR(2))
RETURNS TABLE--�����ķ���ֵ��һ�ű�
AS
RETURN (SELECT SNAME FROM STUDENT WHERE  SSEX =@SEX )--�޸���ԭ��FUN2�����еķ�����Ϣ,����ֻ����Ů��������,���Ҫ�޸��������ܿ������޸�

SELECT * FROM FUN2('��')

DROP FUNCTION FUN3 --ɾ������







-------------------------------------------------------�α�-----------------------------------------------------------------
--���ã�����ӵ�ǰ����һ�л��������
--      ���������ǰ��������
--		����λ���ض���������
--		������ѯ�Ľ����

--ʹ�÷���:�����α꣬���α꣬�����α꣬�ر��α�~

DECLARE CUR_STU CURSOR--�����α�
FOR
SELECT SNO,SNAME FROM STUDENT --�α������
WHERE SNO>'06310410102' AND SNO<'06310410129'--��ѧ���ڹ涨��Χ�ڵļ�¼��Ϊ�α������
-------------------------------------------------------------------------------------------------------------------------------------
OPEN CUR_STU --���α�

DECLARE @NO VARCHAR(12),@NAME VARCHAR(12)--��������������������ʱ����α��ڵļ�¼

PRINT '�α������еļ�¼����Ϊ'+CAST(@@CURSOR_ROWS AS VARCHAR(20))--ȫ�ֱ���@@cursor_rows������α��ڵļ�¼��

FETCH NEXT FROM CUR_STU INTO @NO,@NAME--��λ�α�
WHILE @@FETCH_STATUS =0--ͨ��whileѭ�����α��ڵļ�¼����ʾһ��
BEGIN
PRINT 'ѧ�ţ�'+@NO+'������'+@NAME--��Ϊ�����Ѿ�Ϊ�α궨λ�ˣ����Կ����������һ����¼
FETCH NEXT FROM CUR_STU INTO @NO ,@NAME--�ٽ��α�ָ����һ����¼��ͨ��ѭ�����Ա������м�¼
END
CLOSE CUR_STU--�ر��α�
DEALLOCATE CUR_STU--�ͷ��α���Դ����ɾ���α�
------------------------------------------------------------------------------------------------------------------------------------------
DELETE FROM STUDENT 
WHERE CURRENT OF CRU_STU


