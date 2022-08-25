#include "date.h"
#include <ctime>
#include <Windows.h>
#include<fstream>
#include <iostream>
#include <sstream>
#pragma execution_character_set( "utf-8" )
using namespace std;
date::date()
{
	day = month = year = 0;
}

date::date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

date::~date()
{
}

void date::input()
{
	SetConsoleOutputCP(65001);
	cin >> this->day >> this->month >> this->year;
	while (!this->check())
	{
		cout << "Lỗi ngày tháng năm rồi! Nhập lại nè: ";
		cin >> this->day >> this->month >> this->year;
	}
}

void date::input_file(ifstream& filein) {
	filein >> this->day;
	filein >> this->month;
	filein >> this->year;
};

void date::output()
{
	string out;
	string more = "/";
	ostringstream addDay;

	addDay << day;
	out = addDay.str();
	out += more;

	ostringstream addMonth;
	addMonth << month;
	out += addMonth.str();
	out += more;

	ostringstream addYear;
	addYear << year;
	out += addYear.str();

	cout << out;
}


bool date::check()
{
	if (year < 0)
		return false;
	if (month < 0 || month > 12)
		return false;
	if (day < 0)
		return false;
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 == 0) || year % 400 == 0)
		{
			if (day > 29)
				return false;

		}
		else
		{
			if (day > 28)
				return false;
		}
	}
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day > 31)
			return false;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day > 30)
			return false;
	}
	return true;
}

void date::setDate(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

bool date::checkDateBeforeNow()
{
	date today = getRealTime();
	if (this->year > today.year)
		return false;
	else if (this->month > today.month)
		return false;
	else if (this->day > today.day)
		return false;
	return true;
}

bool date::checkDateAfterNow()
{
	date today = getRealTime();
	if (this->year < today.year)
		return false;
	else if (this->month < today.month)
		return false;
	else if (this->day < today.day)
		return false;
	return true;
}

bool date::checkLessThanDay(const date& A)
{
	if (year < A.year)
		return true;
	if (year == A.year && month < A.month)
		return true;
	if (year == A.year && month == A.month && day < A.day)
		return true;
	return false;
}

bool date::checkMoreThanDay(const date& A)
{
	if (year > A.year)
		return true;
	if (year == A.year && month > A.month)
		return true;
	if (year == A.year && month == A.month && day > A.day)
		return true;
	return false;
}



date getRealTime()
{
	struct tm realDate;
	time_t now = time(0);
	localtime_s(&realDate, &now);
	int year = 1900 + realDate.tm_year;
	int month = 1 + realDate.tm_mon;
	int day = realDate.tm_mday;
	date newDate(day, month, year);
	return newDate;
}

int date::getDay() {
	return this->day;
}
int date::getMonth() {
	return this->month;
}
int date::getYear() {
	return this->year;
}

