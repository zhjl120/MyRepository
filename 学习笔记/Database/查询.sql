select * from STUDENT --��ѯ����ȫ������

SELECT SNO,SNAME FROM STUDENT --��ѯ�����ض��ֶ�,��ѯ����ֶ��ö��Ÿ���

SELECT DISTINCT SNO,SNAME FROM STUDENT --distinct�ؼ�������ȥ���ظ���¼ 

SELECT SNO AS 'ѧ��',SNAME AS '����' FROM STUDENT --�����ֶα���
SELECT SNO AS 'ѧ��', '' AS phone FROM STUDENT  --������µ��ֶΣ�ֻ����ʾ����û���������ֶΣ�

SELECT SNO ,SNAME INTO SNONAME FROM STUDENT--����ѯ������浽�±�SNONAME��

SELECT SNO+SNAME AS 'ѧ������' FROM STUDENT--�������ֶ����ӳ�һ�����ֶΣ�ע�������ֶε��������ͣ�

SELECT * FROM CLASS WHERE DEPT='�����ϵ' --��ѯ�������ڼ����ϵ��ѧ��
SELECT * FROM SCORE WHERE GRADE>80 --��ѯ���гɼ�����88��ѧ����������������ϵ��������磬> < >= <= !=��
SELECT * FROM CLASS WHERE CLASSNO <>'���ӻ�06103' --��ѯ���Ǹ�רҵ���������ѧ��

SELECT * FROM SCORE WHERE GRADE BETWEEN 90 AND 100--��ѯ�ɼ���90��100֮���ѧ����ʹ��between�ؼ��֣�ע�����ǰ�����ʼֵ�ͽ���ֵ�ģ�
SELECT * FROM SCORE WHERE GRADE >=90 AND GRADE <=100 --Ч��ͬ��

SELECT * FROM SCORE WHERE GRADE IN(77,88,99) --��ѯ�ɼ���88��99��ѧ��
SELECT * FROM SCORE WHERE GRADE =88 OR GRADE =99 OR GRADE =77--Ч��ͬ��

SELECT * FROM SCORE WHERE SNO IS NULL --��ѯ������NULLֵ�ļ�¼
SELECT * FROM SCORE WHERE SNO IS NOT NULL --��ѯ�����з�NULLֵ�ļ�¼

--------------------����----------------------

SELECT * FROM SCORE ORDER BY SNO --��ѧ�Ž�������Ĭ��������
SELECT * FROM SCORE ORDER BY SNO DESC --�Խ����������,DESC�ǽ���Ĺؼ��֣�ASC����������

SELECT * FROM SCORE ORDER BY SNO DESC ,GRADE --�Զ���ֶν������У�ֻ�е���һ���ֶγ�����ֵͬʱ���Ż��õڶ����ֶν�������

SELECT TOP 5 SNO,COURSE ,GRADE  FROM SCORE  ORDER BY SNO --��ѯǰ������¼

SELECT TOP 5 PERCENT SNO,COURSE ,GRADE  FROM SCORE  --��ѯ����ǰ5%�ļ�¼��PERCENT�ǰٷְٹؼ���

SELECT * FROM SCORE WHERE GRADE >90 ORDER BY GRADE  DESC--where�����order by���Ľ��ʹ�ã�������ɸѡ����where�����ļ�¼���ٶ����ǽ�������


---------------------�߼�������ѯ---------------------------------

SELECT * FROM SCORE WHERE COURSE ='��ѧӢ��' AND GRADE =66  ORDER BY SNO  --AND ����ʾ�������ͬʱ����

SELECT * FROM SCORE WHERE GRADE =77 OR GRADE=66 -- OR��� ֻҪ����������������

SELECT * FROM SCORE WHERE GRADE =66 OR COURSE ='��ѧӢ��' AND GRADE  =77--AND��OR�����ȼ���AND���ȣ�ʹ������������Ž��ض���ϵ����һ��

SELECT * FROM SCORE WHERE GRADE NOT BETWEEN 70 AND 100 --NOT���ǶԽ��ȡ������˼�������ɼ�����70��100֮��ļ�¼��ʾ����

SELECT * FROM STUDENT  WHERE SNAME LIKE '��%'--��ѯ�������ŵļ�¼
SELECT * FROM STUDENT  WHERE SNAME LIKE '%ΰ%'--��ѯ�����к���ΰ�ֵļ�¼

SELECT * FROM STUDENT  WHERE SNAME LIKE '��_'--�»���_����һ���ַ�����ʾ���������ŵģ���ֻ�������ֵ����ֵļ�¼
SELECT * FROM STUDENT  WHERE SNAME LIKE '��__'--�����»��߱�ʾ�����ַ��������ŵģ��������������ֵļ�¼

SELECT * FROM STUDENT WHERE SNAME LIKE '[����]%' --��ѯ���Ż�����ļ�¼
SELECT * FROM STUDENT WHERE SNAME LIKE '[^����]%' --��ѯ�������Ż����������ļ�¼

--ͨ��� ������[] ʹ�ã� [nr]% ��ʾֻҪ����n��r��ͷ�ļ�¼�����Ա���ѯ
--						 [a-e]% ��ʾֻҪ��ͷ��a��e�ļ�¼�����Ա���ѯ
--						 [^b]% ��ʾ���˿�ͷ��b�ļ�¼�����Ա���ѯ

--  LIKE '%5#%%' ESCAPE '#'  ����ת���ַ�#����ʾ��#��������ķ��Ų���ͨ�����������Ҫ��ѯ�ķ��ţ�������˼���ǣ���ѯ�����ַ�����5%���ļ�¼
