
--1.ʹ�������ӹ�����������

SELECT * FROM SCORE ,CLASS --ʹ�������ӹ��������������ǵĽ���������ֶμ���һ�𣬼�¼�����ű��м�¼�ĳ˻�

--2.�����ӹ����������������������ģ�����where�Ӿ䣩�����������й������ֶ���Ϊ���ӵ�����
--  ֻ���������й�ͬ���ֶβ���ʹ�õ�ֵ����
SELECT STUDENT .SNO,STUDENT .SNAME,STUDENT .SSEX,STUDENT .CLASSNO,SCORE.COURSE,SCORE .GRADE
FROM STUDENT ,SCORE 
WHERE STUDENT .SNO=SCORE .SNO--�����ű�����ͬ���ֶ�sno��Ϊ��������

SELECT a .SNO,a .SNAME,a .SSEX,a .CLASSNO,b.COURSE,b .GRADE
FROM STUDENT a,SCORE b --��ʹ�ñ���������������ڱ�������������¿��Լ򻯲�����������ʹ�ñ���ʱ�Ͳ�����ʹ��ԭ���ˣ����б�������Ҫ�ĳɱ���
WHERE a.SNO=b .SNO--�����ű�����ͬ���ֶ�sno��Ϊ��������

--3.������Ӳ�ѯ

SELECT STUDENT .SNO,STUDENT.SNAME,STUDENT .SSEX,STUDENT .CLASSNO,CLASS .DEPT,SCORE .GRADE,SCORE .COURSE--��Ҫ��ѯ���ֶ�
FROM STUDENT ,SCORE ,CLASS--����3�ű�
WHERE STUDENT .SNO=SCORE .SNO AND STUDENT .CLASSNO=CLASS .CLASSNO--����֮�����ϵ
ORDER BY SNO--��ѧ������

--4.INNER JION���Ӳ�ѯ  ���ֽ��� �ڲ����ӻ������ӣ�

SELECT STUDENT .SNO,STUDENT.SNAME,STUDENT .SSEX,STUDENT .CLASSNO,CLASS .DEPT,SCORE .GRADE,SCORE .COURSE--��Ҫ��ѯ���ֶ�
FROM STUDENT 
INNER JOIN SCORE-- ���ӵı�
ON STUDENT .SNO=SCORE .SNO--���ӵ�����
INNER JOIN CLASS--���ӵı�
ON STUDENT.CLASSNO=CLASS .CLASSNO--���ӵ�����
ORDER BY STUDENT .SNO DESC 


----------------------�߼����Ӳ�ѯ----------------
--1.������
SELECT * 
FROM STUDENT A,STUDENT B--Ϊͬһ��������������������������
WHERE A.SNO=B.SNO
      AND A.SNAME='Ҷ�վ�'--����ѡ������
 
--2.������   ֻ�����������в���ͬ�ļ�¼
--    ����:  ��ֵ���ӣ���Ȼ���ӣ�����ֵ����

--��������

--3.�������ӣ����������������ߵ�ȫ����¼�����ӷ��ұ߱����������ͬ�ļ�¼

SELECT �ֶ���  FROM ��1  --�����������ͬ��¼�ͱ�1��ȫ����¼
LEFT OUTER JION ��2
ON ��������

--4.�������� 
SELECT �ֶ��� FROM ��1--����������ͬ�ļ�¼�ͱ�2��ȫ����¼
LEFT OUTER JION ��2
ON ��������

--5.ȫ������   �����������е��������ݣ�������û��ƥ��ļ�¼���Կ�ֵ����ʽ����
SELECT �ֶ��� FROM ��1
FULL OUTER JION ��2
ON ��������

--6.��������   �����������м�¼�ĳ˻�
SELECT �ֶ��� FROM ��1
CROSS JION ��2

------------------------��ϲ�ѯ----------------------
--�����select���Ľ�������һ�𣬲��ҽ�������Ĳ�ѯ����ŵ�һ���������

SELECT * FROM STUDENT WHERE SNAME ='���' --����ѯ�����ϵ�һ����Ҫ���ǵ��ֶ���Ŀһ������ÿ���ֶε����ͼ���
UNION --ʹ��UNION �ǻ�ȥ���ظ�ֵ�ģ����ϣ������ȥ���ظ�ֵ����Ҫ����������ALL
--UNION ALL
SELECT * FROM STUDENT WHERE SNO='6310410102'

SELECT * FROM SCORE WHERE GRADE=99 AND COURSE ='����'--������ѯ�Ľ����ϵ�һ��,����ѧ������,ORDER BY���������������ĩβ
UNION
SELECT * FROM SCORE WHERE SNO ='6320210611'
ORDER BY SNO


-------------------------�Ӳ�ѯ------------------------
--һ����ѯ��䵱�а�����һ����ѯ���

SELECT * FROM SCORE 
WHERE GRADE =(SELECT  MIN(GRADE) FROM SCORE )--�ڲ�ѯ���������ٲ���һ����ѯ����ѯ��С�ĳɼ�,�Ը�ǰ��Ĳ�ѯ����ṩ����


