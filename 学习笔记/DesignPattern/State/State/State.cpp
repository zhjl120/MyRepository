// State.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include "CaseOne.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	C_Context context(new ConcreteStateA);

	context.Request();
	context.Request();
	context.Request();
	context.Request();

	//----------------------------------------------------------
	//状态模式：当一个对象的内在状态改变时允许改变其行为，这个对象看起来像是改变了其类。
	//状态模式主要解决的是当控制一个对象状态转换的条件表达式过于复杂的情况。把状态的判断逻辑转移到表示不同状态
	//的一系列类当中，可以把复杂的判断逻辑简化。
	//好处： 将于特定状态相关的行为局部化，并且将不同状态的行为分割开来。
	//用处： 当一个对象的行为取决于它的状态，并且它必须在运行时刻根据状态改变它的行为时，就可以考虑使用状态模式。
	cout<<"------------------------------------------------\n";

	Work project;

	project.SetTime(9);			//早上9点：开始工作
	project.WriteProgram();
	project.SetTime(10);		
	project.WriteProgram();
	project.SetTime(12);	   
	project.WriteProgram();
	project.SetTime(13);
	project.WriteProgram();
	project.SetTime(14);
	project.WriteProgram();
	project.SetTime(17);
	project.SetFinish(false);
	project.WriteProgram();
	project.SetTime(19);
	project.WriteProgram();
	project.SetTime(22);
	project.WriteProgram();


	cout<<"\n\n";
	system("pause");
	return 0;
}

