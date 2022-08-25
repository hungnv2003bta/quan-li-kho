#pragma once
#include "date.h"
#include "goods.h"
#include <iostream>
#include <vector>
#include<fstream>
using namespace std;

class warehouse
{
private:
	vector<goods*> list;
	vector<date> manageInByDate;
	vector<unsigned int> managePrice;
public:
	warehouse();
	~warehouse();
	void input();   //Luu thong tin nhap tu ban phim vao danh sach quan li
	void input_file(); // Luu thong tin nhap tu file vao danh sach quan li
	void output();  // Xuat danh sach quan li
	void outputAllSold(); //Xuat danh sach hang toan bo hang da ban
	void outputAllInventory();  //XUat danh sach toan bo hang ton kho
	void sortWarehouse();   //Sap xep lai danh sach
	
	void outputGoodsOutOfDate(); //Xuat danh sach san pham het han
	void revenueDay(); //Tinh tong tien ngay can kiem tra
	void revenueMonth(); //Tinh tong tien thang can kiem tra
	void revenueYear(); //Tinh tong tien nam can kiem tra
};

bool compare(goods* A, goods* B);
bool checkEXP(goods* A);