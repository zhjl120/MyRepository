---------------ϵͳ����-------------------

--1.�ۺϺ�����ϵͳ��������õĺ�������Ҫ�Ƕ�һ��ֵ���м��㣬Ȼ�󷵻�һ��ֵ��
--  ��Ҫ������SUM , AVG ,MIN ,MAX, COUNT

SELECT SUM(GRADE) FROM SCORE --�������гɼ��ĺ�
SELECT AVG(GRADE) FROM SCORE --����ƽ���ɼ�
SELECT MIN(GRADE) FROM SCORE --������С�ɼ�
SELECT MAX(GRADE) FROM SCORE --�������ɼ�
SELECT COUNT (SNO) FROM SCORE --���ؼ�¼����

--2.����ת������
--  ��Ҫ������CONVERT ,CAST

SELECT CONVERT (CHAR,GETDATE(),101)--GETDATE�������ڻ�ȡ��ǰʱ�ڣ�CONVERT�������ڽ�����ת��Ϊ�ַ���,���һ��������������ʱ����ʾ�ķ��
SELECT CAST (GETDATE() AS CHAR(10))--����ǰ����ת��Ϊ10���ַ����ַ���

--3.���ں���
--  ��Ҫ������GETDATE,DATEADD,DATEDIFF,DATENAME,DATEPART

SELECT GETDATE ()--��ȡ��ǰʱ��
SELECT DATEADD (YEAR,5,GETDATE())--��ָ�������ϼ���һ��ָ����ʱ�䣬�þ䷵���ڵ�ǰ�����ϼ���5����ʱ�䣬��һ��������ѡ:YEAR,QUARTEER,MONTH,WEEK,DAY,HOUR,MINUTE,SECOND
SELECT DATEDIFF (YEAR,'1992-08-09',GETDATE ())--��ȡ�������ڵĲ��һ������ȡֵͬ��
SELECT DATENAME (MONTH ,GETDATE ())--���ַ�����ʽ����ָ�������ڶΣ��þ伴���ص�ǰ���·�
SELECT DATEPART (DAY,GETDATE())--��������ʽ����ָ�����ڵ����ڶΣ��þ伴���ص�ǰ�Ǽ���



------------------�����ѯ----------------------
SELECT DEPT  FROM CLASS GROUP BY DEPT --��ָ���ֶν��з��飨ȥ���ظ�ֵ��������Ե���ĳһ���ֶ��ڵ�ֵ
SELECT SSEX,COUNT (SSEX) AS '����' FROM STUDENT GROUP BY SSEX --���Ա���з��飬��ͳ����Ů��������

SELECT CLASSNO, REPLICATE('=',COUNT(*))AS '�����Ա� ' FROM STUDENT GROUP BY CLASSNO --��ÿ���༶���飬��ʹ��REPLICATE�ؼ��ֽ�ÿ��������ֱ��ͼ����ʽ���ֳ���

SELECT CLASSNO,COUNT(*) AS '����' FROM STUDENT  GROUP BY CLASSNO ORDER BY COUNT(*)--�԰༶���飬ͳ�Ƹ������������������Ķ�������

SELECT CLASSNO,SSEX,COUNT(*) AS '����' 
FROM STUDENT
GROUP BY CLASSNO,SSEX 
ORDER BY CLASSNO --���༶���Ա���飬��ͳ�Ƹ�����Ů���������༶����

SELECT CLASSNO,
	   COUNT(CASE
				WHEN SSEX='��' THEN 1
				ELSE NULL END) AS '��������',
	   COUNT(CASE
			    WHEN SSEX='Ů' THEN 1
				ELSE NULL END) AS 'Ů������'
FROM STUDENT
GROUP BY CLASSNO

SELECT CLASSNO,COUNT(*)AS '����'
FROM STUDENT 
GROUP BY CLASSNO --���༶���з���
HAVING CLASSNO IN('��ý��06101','��Ϸ07103')--�ڷ����й��˳���Ҫ�鿴�ķ���
ORDER BY COUNT(*)--��ʱ��ֻ��鿴��Ҫ�ķ���ͳ����Ϣ��������ȫ���ķ���ͳ�ƣ���Ϳ���ʹ��HAVING��������˷���

SELECT CLASSNO,COUNT(*)AS '����'--Ч��ͬ�ϣ��������where������ɸѡ
FROM STUDENT
WHERE CLASSNO IN ('��ý��06101','��Ϸ07103')--ɸѡ��Ҫ�鿴�ķ���
GROUP BY CLASSNO --���༶���з���
ORDER BY COUNT(*)DESC--����������