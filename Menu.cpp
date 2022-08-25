#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#include "Menu.h"
#include "warehouse.h"
#pragma execution_character_set( "utf-8" )


void Menu() {
	SetConsoleOutputCP(65001);
	cout << "\t\tCHƯƠNG TRÌNH THỰC PHẦM C++\t";
	cout << "\n========================MENU======================\n";
	cout << "         1.Nhập thông tin từ bàn phím               \n";
	cout << "         2.Nhập thông tin từ file                   \n";
	cout << "         3.Sắp xếp lại kho theo ngày nhập kho       \n";
	cout << "         4.Xem toàn bộ hàng đã nhập                 \n";
	cout << "         5.Xem toàn bộ hàng đã xuất bán             \n";
	cout << "         6.Hiển thị hàng tồn kho                    \n";
	cout << "         7.Kiếm tra hàng hết hạn                    \n";
	cout << "         8.Tổng tiền hàng đã xuất bán trong ngày    \n";
	cout << "         9.Tổng tiền hàng đã xuất bán trong tháng   \n";
	cout << "        10.Tổng tiền hàng đã xuất bán trong năm     \n";
	cout << "        11.Hướng dẫn                                \n";
	cout << "         0.Thoát                                    \n";
	cout << "====================================================\n";
}
int ChonMenu() {
	int n = 0;
	cout << "\n\nMời cả nhà chọn menu: ";
	cin >> n;
	if (n >= 0 || n < 10)
		return n;
	else return ChonMenu();
}

bool XuLyMenu(warehouse &A) {
	SetConsoleOutputCP(65001);
	int chon;
	chon = ChonMenu();
	switch (chon) {
	case 1:
		system("cls");
		A.input();
		cout << "\n\nNHẤN PHÍM BẤT KÌ ĐỂ TIẾP TỤC NHẬP LỆNH !\n\n";
		system("pause");
		break;
	case 2:
		system("cls");
		A.input_file();
		cout << "\nĐã nhập hàng từ file rồi nhé !\n";
		cout << "\n\nNHẤN PHÍM BẤT KÌ ĐỂ TIẾP TỤC NHẬP LỆNH !\n\n";
		system("pause");
		break;
	case 3:
		system("cls");
		A.sortWarehouse();
		cout << "\nĐã sắp xếp lại kho rồi nhé !\n" << endl;
		cout << "\n\nNHẤN PHÍM BẤT KÌ ĐỂ TIẾP TỤC NHẬP LỆNH !\n\n";
		system("pause");
		break;
	case 4:
		system("cls");
		A.output();
		cout << "\n\nNHẤN PHÍM BẤT KÌ ĐỂ TIẾP TỤC NHẬP LỆNH !\n\n";
		system("pause");
		break;
	case 5:
		system("cls");
		A.outputAllSold();
		cout << "\n\nNHẤN PHÍM BẤT KÌ ĐỂ TIẾP TỤC NHẬP LỆNH !\n\n";
		system("pause");
		break;
	case 6:
		system("cls");
		A.outputAllInventory();
		cout << "\n\nNHẤN PHÍM BẤT KÌ ĐỂ TIẾP TỤC NHẬP LỆNH !\n\n";
		system("pause");
		break;
	case 7:
		system("cls");
		A.outputGoodsOutOfDate();
		cout << "\n\nNHẤN PHÍM BẤT KÌ ĐỂ TIẾP TỤC NHẬP LỆNH !\n\n";
		system("pause");
		break;
	case 8:
		system("cls");
		A.revenueDay();
		cout << "\n\nNHẤN PHÍM BẤT KÌ ĐỂ TIẾP TỤC NHẬP LỆNH !\n\n";
		system("pause");
		break;
	case 9:
		system("cls");
		A.revenueMonth();
		cout << "\n\nNHẤN PHÍM BẤT KÌ ĐỂ TIẾP TỤC NHẬP LỆNH !\n\n";
		system("pause");
		break;
	case 10:
		system("cls");
		A.revenueYear();
		cout << "\n\nNHẤN PHÍM BẤT KÌ ĐỂ TIẾP TỤC NHẬP LỆNH !\n\n";
		system("pause");
		break;
	case 11:
		system("cls");
		cout << "                                 BẢNG HƯỚNG DẪN\n";
		cout << "- Chương trình được tạo trên hệ điều hành windows 11 và dùng phần mềm visual studio\n";
		cout << "- Lập trình bằng ngôn ngữ C++\n";
		cout << "- Các thao tác đã được chú thích khi chạy chương trình, nhưng cụ thể:\n";
		cout << "    + Chọn menu: nhập số tự nhiên theo đúng từng yêu cầu\n";
		cout << "    + Nhập thông tin từ bàn phím:\n";
		cout << "          .Nhập tên hàng hóa: Nhập bình thường không dấu(chữ, số, có dấu cách, có kí tự...) - vd: sua tuoi 1412\n";
		cout << "          .Nhập mã sản phẩm: Nhập bình thường không dấu(chữ, số, có dấu cách, có kí tự...) - vd suoituoi_1\n";
		cout << "          .Nhập loại hàng: 0 hoặc 1\n";
		cout << "          .Nhập giá bán: số nguyên - vd 12000\n";
		cout << "          .Nhập mã kho: Nhập bình thường không dấu(chữ, số, có dấu cách, có kí tự...) - vd: 123\n";
		cout << "          .Nhập ngày tháng năm: ngày(dấu cách)tháng(dấu cách)năm với định dạng là số nguyên - vd:14 2 2003\n";
		cout << "          .Nhập tháng năm: tháng(dấu cách)năm với định dạng là số nguyên - vd:2 2003\n";
		cout << "          .Nhập năm: Nhập số nguyên - vd:2003\n";
		cout << "    + Nhập thông tin từ file:\n";
		cout << "          .Mỗi thông tin của một sản phẩm không chứa dấu phẩy\n";
		cout << "          .Dấu phẩy được dùng để phân biệt các thông tin của một sản phẩm(không thêm khoảng cách để phân biệt giữa 2 thông tin)\n";
		cout << "          .Nhập thông tin của 1 sản phẩm, xuống dòng nhập tiếp thông tin của sản phẩm tiếp theo\n";
		cout << "          .Còn lại tương tự như nhập thông tin từ bàn phím theo thứ tự: tên sản phẩm,mã sản phẩm,loại hàng,giá,mã kho,ngày sản xuất,ngày hết hạn,ngày nhập kho,ngày xuất kho.\n";
		cout << "- Ví dụ nhập từ file:\nkem chocolate,k1_2,2,20000,k001,25 5 2022,25 11 2022,30 5 2022,1 8 2022\nkem oc que,k2,2,10000,k001,15 4 2022, 15 10 2022,20 4 2022, 5 5 2022\n";
		cout << "\n\nNHẤN PHÍM BẤT KÌ ĐỂ TIẾP TỤC NHẬP LỆNH !\n\n";
		system("pause");
		break;
	case 0:
		cout <<"\nThoát chương trình rồi đó các bạn! Quay lại thao tác tiếp không được đâu nhé !\n";
		exit(0);
		break;
	}
	return true;
}