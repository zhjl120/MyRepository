#pragma  once

#include <iostream>
#include <string>
using namespace std;

class PersonBuilder{
public:
	virtual void BuildHead() = 0;
	virtual void BuildBody() = 0;
	virtual void BuildArmLeft() = 0;
	virtual void BuildArmRight() = 0;
	virtual void BuildLegLeft() = 0;
	virtual void BuildLegRight() = 0;

};

class PersonThinBuilder : public PersonBuilder
{
public:
	void BuildHead();
	void BuildBody();
	void BuildArmLeft();
	void BuildArmRight();
	void BuildLegLeft();
	void BuildLegRight();
};

class PersonDirector{
public:
	PersonDirector(PersonBuilder* pb);
		
	void CreatePerson();

private:
	PersonBuilder* m_pBuilder;
};