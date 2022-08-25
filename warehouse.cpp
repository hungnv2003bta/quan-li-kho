#include "warehouse.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<iomanip>
#include<fstream>
#include "goods.h"
#include "foodsgoods.h"
#include<windows.h>
#pragma execution_character_set( "utf-8" )
using namespace std;

warehouse::warehouse()
{
}

warehouse::~warehouse()
{
}

void warehouse::input()
{
	goods* t = new foodGoods;
	t->input();
	list.push_back(t);
}

void warehouse::input_file() {

	ifstream filein;
	filein.open("text.txt");
	int i = 0;
	while (i < 12) {
		goods* t = new foodGoods;
		t->input_file(filein);
		list.push_back(t);
		i++;
	}
	filein.close();
};

void warehouse::output()
{
	int listSize = list.size();
	cout << setw(5) << left << "STT";
	cout << setw(10) << left << "MA HANG";
	cout << setw(25) << left << "TEN HANG";
	cout << setw(20) << left << "LOAI HANG";
	cout << setw(10) << left << "MA KHO";
	cout << setw(20) << left << "GIA BAN";
	cout << setw(20) << left << "NGAY SAN XUAT";
	cout << setw(20) << left << "NGAY HET HAN";
	cout << setw(20) << left << "NGAY NHAP KHO";
	cout << setw(20) << left << "NGAY XUAT KHO" << endl;
	cout << setfill('-');
	cout << setw(165) << "-";
	cout << endl;
	cout << setfill(' ');
	for (int i = 0; i < listSize; i++)
	{
		cout << setw(5) << i + 1;
		list[i]->output();
	}
	cout << endl << endl;
}

void warehouse::outputAllSold()
{
	int listSize = list.size();
	cout << "-----------------------------------------------------------" << endl;
	cout << "DANH SACH HANG DA BAN:" << endl;
	for (int i = 0; i < listSize; i++)
	{
		date inDate = list[i]->getOutDay();
		if (inDate.checkDateBeforeNow())
		{
			list[i]->output();
		}
	}
}

void warehouse::outputAllInventory()
{
	SetConsoleOutputCP(65001);
	int listSize = list.size();
	cout << "-----------------------------------------------------------" << endl;
	cout << "DANH SACH HANG TON KHO: " << endl;
	for (int i = 0; i < listSize; i++)
	{
		date inDate = list[i]->getOutDay();
		if (inDate.checkDateAfterNow())
		{
			list[i]->output();
		}
	}
}

void warehouse::sortWarehouse()
{
	SetConsoleOutputCP(65001);
	if (!list.empty())
		sort(list.begin(), list.end(), compare);
	else
		cout << "Ây chết tiệt! Kho rỗng @.@" << endl;

}

bool compare(goods* A, goods* B)
{
	if (A->getInDay().checkLessThanDay(B->getInDay()))
		return true;
	return false;
}
 
bool checkEXP(goods* A) {
	date currentDate = getRealTime();
	if (currentDate.checkMoreThanDay(A->getEXP())) {
		return false;
	}
	return true;
}

void warehouse::outputGoodsOutOfDate()
{
	SetConsoleOutputCP(65001);
	string goodsCode;
	cout << "Nhập mã hàng cần kiểm tra: ";
	cin >> goodsCode;
	bool exist = false;
	for (int i = 0; i < list.size(); i++)
	{
		if (goodsCode == list[i]->getCode())
		{
			if (checkEXP(list[i]))
				cout << "Hàng chưa hết hạn nha ^.^" << endl;
			else
				cout << "Hàng đã hết hạn sử dụng T.T" << endl;
		}
		exist = true;
	}
	if (!true)
		cout << "Không tìm thấy mặt hàng này @.@" << endl;
}

void warehouse::revenueDay()
{
	SetConsoleOutputCP(65001);
	cout << "Nhập ngày cần tính tiền!";
	cout << "Cách nhập: ngày tháng năm";
	cout << "Nhập nè: ";
	int day, month, year;
	cin >> day >> month >> year;
	double sum = 0;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->getOutDay().getDay() == day && list[i]->getOutDay().getMonth() == month && list[i]->getOutDay().getYear() == year)
			sum += list[i]->getPrice();
	}
	cout << "Tổng doanh thu ngày: " << day << "/" << month << "/" << year << " là: " << sum << endl;
}

void warehouse::revenueMonth()
{
	SetConsoleOutputCP(65001);
	cout << "Nhập tháng cần tính tiền!";
	cout << "Cách nhập: tháng năm";
	cout << "Nhập nè: ";
	int month, year;
	cin >> month >> year;
	double sum = 0;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->getOutDay().getMonth() == month && list[i]->getOutDay().getYear() == year)
			sum += list[i]->getPrice();
	}
	cout << "Tổng doanh thu tháng " << month << "/" << year << " là: " << sum << endl;
}

void warehouse::revenueYear()
{
	SetConsoleOutputCP(65001);
	cout << "Nhập ngày cần tính tiền!";
	cout << "Cách nhập: năm";
	cout << "Nhập nè: ";
	int year;
	cin >> year;
	double sum = 0;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->getOutDay().getYear() == year)
			sum += list[i]->getPrice();
	}
	cout << "Tổng doanh thu năm " << year << " là: " << sum << endl;
}