#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "date.h"
#include "goods.h"
#include "warehouse.h"
#include "Menu.h"
#pragma execution_character_set( "utf-8" )

using namespace std;

void SetColor(int backgound_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}

void SetWindowSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT WindowSize;
	WindowSize.Top = 0;
	WindowSize.Left = 0;
	WindowSize.Right = width;
	WindowSize.Bottom = height;

	SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

int main()
{
	warehouse A;
	SetWindowSize(200, 150);
	SetConsoleOutputCP(65001);
	SetConsoleTitle(L"NHOM_4");
	while (true) {
		system("cls");
		Menu();
		XuLyMenu(A);
	}
	system("pause");
	return 0;
}