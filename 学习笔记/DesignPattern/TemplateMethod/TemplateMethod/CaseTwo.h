#pragma  once

#include <iostream>
using namespace std;

class TestPaper
{
public:
	void TestQusetion1();
	void TestQusetion2();
	void TestQusetion3();
	void TestQusetion4();
	void TestQusetion5();
};

class TestPaperC : public TestPaper
{
public:
	void Answer1();
	void Answer2();
	void Answer3();
	void Answer4();
	void Answer5();
};

class TestPaperD : public TestPaper
{
public:
	void Answer1();
	void Answer2();
	void Answer3();
	void Answer4();
	void Answer5();
};