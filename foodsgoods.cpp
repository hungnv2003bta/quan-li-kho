#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "foodsgoods.h"
#include "goods.h"
#include "date.h"
#include "Windows.h"
#pragma execution_character_set( "utf-8" )

using namespace std;
foodGoods::foodGoods()
{
	price = 0;
	type = 0;
	warehouseCode = "";
}

foodGoods::~foodGoods()
{
}

void foodGoods::input()
{
	SetConsoleOutputCP(65001);
	cout << "\tNHẬP THÔNG TIN HÀNG HÓA:\t\n";
	cout << "Tên sản phẩm: ";
	cin.ignore();
	getline(cin, this->name);
	cout << "Mã sản phẩm: ";
	getline(cin, this->code);
	cout << "Loại hàng : (1)lưu kho ngắn hạn - (2)lưu kho dài hạn: ";
	cin >> this->type;
	cout << "Giá bán: ";
	cin >> price;
	cout << "Mã kho: ";
	cin.ignore();
	getline(cin, this->warehouseCode);
	cout << "Ngày sản xuất: ";
	MFG.input();
	cout << "Hạn sử dụng: ";
	EXP.input();
	while (EXP.checkLessThanDay(MFG))
	{
		cout << "(Hạn sử dụng phải sau ngày sản xuất !)" << endl;
		cout << "Nhập lại đi má! Hạn sử dụng: ";
		EXP.input();
	}
	cout << "Ngày nhập kho: ";
	inDay.input();
	while (inDay.checkLessThanDay(MFG))
	{
		cout << "(Ngày nhập kho phải sau ngày sản xuất !)" << endl;
		cout << "Nhập lại đi má! Ngày nhập kho: ";
		inDay.input();
	}
	cout << "Ngày xuất kho: ";
	outDay.input();
	while (outDay.checkLessThanDay(inDay))
	{
		cout << "(Ngày xuất kho phải sau ngày nhập kho ! )" << endl;
		cout << "Nhập lại đi má! Ngày xuất kho: ";
		outDay.input();
	}
}

void foodGoods::input_file(ifstream& filein) {
	getline(filein, this->name, ',');
	getline(filein, this->code, ',');
	filein >> this->type;
	filein.seekg(1, 1);
	filein >> this->price;
	filein.ignore();
	filein.seekg(1, 1);
	getline(filein, this->warehouseCode, ',');
	MFG.input_file(filein);
	filein.seekg(1, 1);
	EXP.input_file(filein);
	filein.seekg(1, 1);
	inDay.input_file(filein);
	filein.seekg(1, 1);
	outDay.input_file(filein);
	filein.ignore();
}

void foodGoods::output()
{
	cout << setw(10) << left << code;
	cout << setw(25) << left << name;
	cout << setw(20) << left;
	if (type == 1)
		cout << "ngan han";
	else
		cout << "dai han";
	cout << setw(10) << left << warehouseCode;
	cout << setw(20) << left << price;
	cout << setw(20) << left;
	MFG.output();
	cout << setw(20) << left;
	EXP.output();
	cout << setw(20) << left;
	inDay.output();
	cout << setw(20) << left;
	outDay.output();
	cout << endl;
}

date foodGoods::getInDay()
{
	return inDay;
}

date foodGoods::getOutDay()
{
	return outDay;
}

date foodGoods::getEXP()
{
	return EXP;
}

double foodGoods::getPrice()
{
	return price;
}
