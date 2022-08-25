#pragma once
#include "date.h"
using namespace std;

class goods
{
protected:
	string code;
	string name;
public:
	string getName();
	string getCode();
	virtual void input() = 0;
	virtual void input_file(ifstream& filein) = 0;
	virtual void output() = 0;
	virtual date getInDay() = 0;
	virtual date getOutDay() = 0;
	virtual date getEXP() = 0;
	virtual double getPrice() = 0;
};

