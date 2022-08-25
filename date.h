#pragma once
#include "date.h"
#include <ctime>
#include<fstream>
#include <iostream>
using namespace std;


class date
{
private:
	int day;
	int month;
	int year;
public:
	date();
	date(int day, int month, int year);
	~date();
	void input();   //Nhap ngay
	void output();  //Xuat ngay
	bool check();  //Kiem tra ngay hop le
	void input_file(ifstream& filein);  //Nhap tu file
	void setDate(int day, int month, int year);
	bool checkDateBeforeNow();  //Kiem tra ngay so voi thoi gian thuc te
	bool checkDateAfterNow();
	bool checkLessThanDay(const date& A); //So sanh 2 ngay
	bool checkMoreThanDay(const date& A);

	int getDay();  //Lay thong tin ngay
	int getMonth(); // Lay thong tin thang
	int getYear();  // Lay thong tin nam
};

date getRealTime();  //Lay thoi gian thuc the
