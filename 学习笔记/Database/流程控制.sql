
---------------------Transact-SQL--------------------

------------�����------------------
--��������� :   + - * / %
--��ֵ����� :   =
--λ�����   :   &  |  ^  ��λ�� ��λ�� ��λ���
--�Ƚ������ :   > < >= <= != !< !>
--�߼������ :   ALL (ȫ��ΪTRUE��ΪTRUE) 
--			     AND (��������������ΪTRUE)
--			     ANY (�κ�һ�����������ΪTRUE)
--				 BETWEEN(ֻҪ���������涨�ķ�Χ�ھ�ΪTRUE)
--				 EXISTS(����Ӳ�ѯ��Ϊ���򷵻�TRUE)
--				 IN (������������ڱ��ʽ�е��κ�һ����ΪTRUE)
--				 LIKE(����ģ����ѯ)
--				 NOT(��ʾ�� ���Բ�������ȡ��)
--				 OR(��ʾ��)
--				 SOME(����ڲ���������һЩΪTRUE��ΪTRUE)

--�ַ������������: +(���������ַ���)
--һԪ�����      : +(��) -(��)



---------------------����������--------------------

--1.����  

SELECT GRADE+5 FROM SCORE --�����ı�ֵ�������5���ǳ���

--2.����
--�ֲ���������һ��@�ű�ʾ   ȫ�ֱ�����������@�ű�ʾ��ȫ�ֱ�����ϵͳ����ı������û�ֻ��ʹ�������������Զ���ȫ�ֱ���

DECLARE @ABC VARCHAR(20)--����VARCHAR�ͱ���ABC
DECLARE @BCD INT   
DECLARE @CDE CHAR(5) --������3������   
SET @ABC ='1234567'--ʹ��SETΪ������ֵ��SETһ��ֻ��Ϊһ��������ֵ
SELECT @BCD =123,@CDE ='HELLO'--������SELECT Ϊ���������ֵ
PRINT @ABC--��ӡ����
PRINT @CDE
PRINT @BCD

DECLARE @NAME VARCHAR(20)--�������
SELECT @NAME=SNAME--����ѯ�Ľ����������
FROM STUDENT 
WHERE SNO='6310910329'
PRINT @NAME--��ʾ����

--���õ�ȫ�ֱ���

SELECT * FROM STUDENT 
PRINT 'һ����ѯ��'+CAST(@@ROWCOUNT AS VARCHAR(5))+'����¼'--�Ӻ����ַ������ӷ�,CAST����ת������(��ȫ�ֱ���ת��Ϊ�ַ���)Ȼ�����
SELECT @@ERROR 
SELECT @@CPU_BUSY													  --ȫ�ֱ���@@ROWCOUNT�洢�˲�ѯ�ļ�¼������,����һ�����Ĳ�ѯ��¼������
					

-----------------------���̿������------------------
--BEGIN ... END   ���һ����������Ŀ�ʼ�ͽ���
--IF...ELSE
--WHILE
--BREAK
--CONTINUE
--WAITFOR
--CASE	


----IF ELSE---

DECLARE @X REAL,@Y REAL,@Z REAL--������������
SELECT @X=9,@Y=5   --ΪXY��ֵ
IF @Y!=0	--�жϳ����Ƿ�Ϊ0
BEGIN	--�����Ϊ0����ʼִ������
SELECT @Z=@X/@Y	 --��x����y��ֵ����z
PRINT '���Ϊ'+CAST(@Z AS CHAR)--��zת��Ϊ�ַ����Ͳ����
END	--�������
ELSE--���򣬼�Y��ֵΪ0����ִ�����������
BEGIN --���ELSE����ֻ��һ����䣬�����ʡ��BEGIN��END�����Ǿ��൱��C������else����Ĵ�����
PRINT '��������Ϊ0'
END

----WHILE-----

DECLARE @X INT ,@SUN INT--���ܶ����Ѿ������˵ı�����
SELECT @X=1,@SUN=0
WHILE @X<=100
BEGIN 
SELECT @SUN =@SUN+@X
SELECT @X=@X+1
END
PRINT '���Ϊ:'+CAST(@SUN AS CHAR)


-----BREAK--------
DECLARE @X INT
SELECT @X=1
WHILE @X<=10
BEGIN
  IF @X=5--�ж�x�Ƿ�Ϊ5,�����������ѭ��
     BREAK
  ELSE
    BEGIN
     PRINT CAST(@X AS CHAR)
     SELECT @X=@X+1
    END
END		 

----CONTINUE-----

DECLARE @X INT
SELECT @X=0;
WHILE @X <10
BEGIN 
	SELECT @X=@X+1
	IF @X%2=0
	   CONTINUE
	PRINT CAST(@X AS CHAR)
END
	  
	  
---WAITFOR------��һ��ָ����ʱ��֮��ִ����һ������

WAITFOR DELAY '00:00:10'--��10���ʼִ�к�������
SELECT * FROM STUDENT 

---CASE--------

SELECT 
	CASE--��ʾ����ѡ��״̬������CASE����൱�ڷ���һ������������ֵ
	WHEN GRADE>=80 THEN '����'--��WHEN�������������ʱ�ͷ���'����'������ִ����һ�����
	WHEN GRADE>=70 THEN '����'
	WHEN GRADE>=60 THEN '����'
	ELSE '������'--���ǰ��������������Ͼ��з���ELSE�����ֵ
	END
FROM SCORE 

SELECT *,  --�Ľ���Ĳ�ѯ���������е��ֶΣ�������ѯ�Ľ����ӵ����ֶ���
	CASE
	WHEN GRADE>=80 THEN '����'
	WHEN GRADE>=70 THEN '����'
	WHEN GRADE>=60 THEN '����'
	ELSE '������'
	END AS �ȼ� --Ϊ�µ��ֶ�ȡһ������
FROM SCORE 