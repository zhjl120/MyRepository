
-------------������¼�û�-----------------------------
create login "ROSS\zhjl120" from windows--����һ����Windows��֤�ĵ�¼�û�
create login "zhjl" with password='123'  --����һ����sqlserver��֤�ĵ�¼�û�


-------------�������ݿ��û�---------------------------
create user zhjl for login zhjl20  --����һ����zhjl120��¼��ӳ������ݿ��û�

grant create table to zhjl --��zhjl����û����贴�����ݱ��Ȩ��

grant insert ,update,delete
on object::test1.score
to zhjl --Ϊ�û�zhjl�����ݿ�test1�µ�score�������Ӳ��룬���£�ɾ��Ȩ��

deny insert ,update,delete
on object::test1.score
to zhjl --�����û�zhjl�����ݿ�test1�µ�score���� ���ܾ���ӵ�в��룬���£�ɾ��Ȩ��

revoke create table to zhjl --ȡ���û�zhjl�Ĵ������Ȩ��