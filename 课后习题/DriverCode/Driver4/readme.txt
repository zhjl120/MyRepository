-----------------------
ithurricane [http://hi.baidu.com/ithurricane]
2010/02/04
-----------------------
support WDK7/VS2008
fix Privilege Problem
modify register source

-----------------------
bobo 2009/05/21
-----------------------
�޸�bug: VC6 + DDK2003 -> vc6.dsp --> # PROP Cmd_Line "ddkbuild -WNETWXP free ."
         �޸�: ��ddkbuild.cmd��,����DDk2003û��WNETWXP��������������WNETWXP������Ч����ͬ��WNETXP

-----------------------
bobo 2009/05/08
-----------------------
exe:
  1.TestApp��Unicode��ΪMulti-Byte(Ϊ��ʡ��,�ַ�ƴ��,ע�����д����Multi-Byte���), 
      ��TestApp.vcproj��CharacterSet="1" ��ΪCharacterSet="2"
  2.TestApp���غ�ж��sys(modify from MyZwDriverControl.c)�� ò�ƽ�������́E
	  a.����app,load driver
	  b.��appǿ�ƹص�E��ʱû������unload driver
	  c.������app,��ʱ�����ٴ�load driver(����˵û��loadʧ��),һ������ʹ��driver
	  d.�����˳�app,unload driver

	  ps: MyZwDriverControl ӁEclass LoadNTDriver(copy from 0ginr.com)������, 
	      MyZwDriverControl��load��unload��,������ע�������,ɾ����ׁE
		  class LoadNTDriver��load������ע�᱁Eunload��ɾ��ע�᱁E
		  MyZwDriverControl����LockXxxDatabase.
  3.���غ�ж��sys������class LoadNTDriver, ������ELoadNTDriver.h"

sys:
  DriverEntry��E�ӡע���޷��
  default uIoControlCode �䳁EIoCode
  ���к������ӷ�ҳ���Ƿ�ҳ��ÁE#pragma alloc_text(PAGE, DispatchXX))

-----------------------
bobo 2009/04/27
-----------------------
1.����target os����Eֻ��ѡһ��os
2.����DDK�汾������OSѡԁE
3.fix bug : "mybuild.bat" �ڵ� PROJECT_MYBUILD_CMD_LINE ��������(DDK + OS)д����
            DDK·������Ĭ�ϵģ��ٸ����д�鷳����

			DDK 2000       --- C:\\NTDDK
			DDK XP         --- C:\\WINDDK\\2600
			DDK 2003       --- C:\\WINDDK\\3790.1830
			WDK 6001.18002 --- C:\\WINDDK\\6001.18002

4.֧��WDK + win2008
// todo : 5.����check�� freeѡԁE(mybuild.bat�ű���E�ҁE��� "chk ." ӁE"fre .")

6.��һ������EasySysʱ�����Զ��趨�û���������(WXPBASE,WNETBASE...)��
  ���Ǹ���ע�᱁EHKEY_LOCAL_MACHINE -- SOFTWARE\\Microsoft\\WINDDK �趨DDK·���ġ�
  (��һ�û���װ�˶��DDK���ټӸ�WDK�����·����Ҫ�����ж���)

  ��"mybuild.bat"Ҳ��set������������������E�ʵû���ˡ�

7.�ű�ÁE��������忴 "ddkbuild.cmd":: Usage output

-----------------------
bobo 2009/04/23
-----------------------
1.����MS sample��ʽ�޸�"sources"

-----------------------.
bobo 2009/04/18
-----------------------
1. ����common.h, ���ڶ���exe��sys�Ĺ�ͨIOCTL
2. ����console APP (for VS2005)����, ���ڲ���sys. ���ĸ�hello world������.
   (����ֻҪ���DriverMonitor�Ϳ��Բ���������)
// todo : 3. ��dsp_proj.htm(VC6)��E���clean��ҁE���,��VC6ʹ��clean.bat
// todo : 4. ����MFC APP����,���ڲ���sys
5. �����޸�ע��
6.�޸�print�꣬��Ӧcheck��free�汾��build
  #if DBG
  #define dprintf DbgPrint
  #else
  #define dprintf
  #endif

ԽдԽ�����ˣ���easy��.....

-----------------------
bobo 2009/04/16
-----------------------
1.OnInitDialog()��E���OnChangeAuthor()
2.�޸�OnChangeAuthor()�ַ���
3.�޸�hfile.htm,cfile.htm����Ӧ�Լ�ϰ��
-----------------------

bobo 2009/04/10
-----------------------
1.GenerateRandomStrings()��new û���ͷţ�
  ��Ϊ�ֲ���ׁE���ֲ�̫������,64��С)
2.OnInitDialog()��E���OnSelectIdeType(),��ʼ��IdeType
				  ����OnSelchangeDdkVersion(),��ʼ��DDK type
3.ddkbuild.cmd ��E�Ϊ VERSION=V7.3
4.VC6��ddkbuild.bat��Ϊddkbuild.cmd
5.�޸�OnSelchangeDdkVersion()�ڵ�DDK2000���߼��ж�
6.��VC6��dsp.htm������struct.h

-----------------------
ChiChou [http://hi.baidu.com/517826104]
2009/02/03
-----------------------

ChiChou ���� sudami�޸İ�E��ׁE

* ����BUG
	1.�ǳ����ص�BUG���������˳�ʱû���Ƴ�����ͼ�꣬��ĳЩ�������˳�ʱ
������������ҵĵ�������сE- -!����

	2.ԭ����DDK·��ʱ����ȡ��ע���޷��д���ˣ������޷���� DDK �� 
Path��ò�ƴ���ֱ�������Լҵ�DDK·����֮����δ���е㡣��������

	3.ԭ��û�м�E鹤�����������E氁E��Ƿ��ַ�����ô��������Ŀ¼��ʱ��E
�ͻ����������ʱ���ӶԷǷ��ַ���check���ܡ���E���/\|"<>*?:

	4.����һ��BUGû���޸�������ڹ����������E��硰project..��������ʱ��
Ҳ�������ļ����ʴ��󡣵�����û�а�E��޸���������ַ������ж��е��Ѷȡ���
ˮƽ���ӡ���(- -...)

* ������ÁE
	1.�Ѵ���Ū�� XPBUTTON ��ȥ����...ͼ��ҁEٶȡ�
	2.Ȼ��P���ű���ͼ�����������棬�����ÿ���~~
	3.ϰ���Ե� XP Manifest �����¡�

* �޸�ģ��E
	1.���ݸ���ϲ�ô�Eĸ�ʽ�޸�����~
	2.˳��ѡ�́E�ҹ������E濴����ĳ���������жϷ��������û������Ȼ��E
������ͬ���豸�����������˽�ȥ����

* ́Eƹ���
	1.sudami����е��鷳���˳�����Ҫ�����̡�ֱ�����������������˳���
ť��
	2.���̴���֮��EasySYS����û�ô��ˣ��������ˡ�́Eɺ��˳���ѡ���
	3.���ɹ��̺����ԴE��������ڡ����ߵ���Ϣ��
	4.���ɹ��̺�Ĳ���Ҳ�ǿ�ѡ�ġ�����ѡ���Զ��򿪹����ļ�������Ŀ¼��
	5.����Clean����~~~
-----------------------


-----------------------
sudami [sudami@163.com]
2008/08/13
-----------------------

	VS 2005��д������VC 6.0����ܶ�E���ö�EasySYS�汾(Include DIY)��ֻ
֧��VC 6.0.���������VBGOOD��̳����IceBoyСͬѧ��VBд�˸�֧��vs 2005��
demo.����,��Ҳ����д���������Լ��Ĺ���,�����Ժ�EٵĿ���������ЁE

	����,��Ҫ�Ƿ����Լ�дcode,�����ɵ�code����ǰ����Լ�����Ը������
��...

-----------------------
