#pragma once

#include <iostream>
#include <string>
using namespace std;

class TestPaper2
{
public:
	void TestQusetion1();
	void TestQusetion2();
	void TestQusetion3();
	void TestQusetion4();
	void TestQusetion5();

	virtual string Answer1();
	virtual string Answer2();
	virtual string Answer3();
	virtual string Answer4();
	virtual string Answer5();
};

class TestPaperE : public TestPaper2
{
public:
	string Answer1();
	string Answer2();
	string Answer3();
	string Answer4();
	string Answer5();
};

class TestPaperF : public TestPaper2
{
public:
	string Answer1();
	string Answer2();
	string Answer3();
	string Answer4();
	string Answer5();
};