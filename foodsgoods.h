#pragma once
#include <string>
#include "goods.h"
#include "date.h"

class foodGoods :public goods
{
private:
	double price;
	int type;
	string warehouseCode;
	date MFG;
	date EXP;
	date inDay;
	date outDay;
public:
	foodGoods();
	~foodGoods();
	void input();   // Nhap tu ban phim
	void input_file(ifstream& filein); //Nhap tu file
	void output();  //Xuat danh sach toan bo thong tin
	date getInDay();  //Lay thong tin nhap kho
	date getOutDay();  //Lay thong tin xuat kho
	date getEXP();  //Lay thong tin han su dung
	double getPrice(); //Lay thong tin gia san pham
};