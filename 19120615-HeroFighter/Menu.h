#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Kiểu con trỏ trỏ tới 1 hàm void
typedef void (*vfuncptr_t)();

class Menu
{
private:
	// Mấy cái tên này em xin dùng tiếng Anh vì dịch ra tiếng Việt nhìn hơi kì
	vector<string> arrEntries;
	vector<vfuncptr_t> arrActions;
public:
	string header;
	string menu_title;
	void themEntryMoi(string, vfuncptr_t);
	void hienThi(bool clrscr = true);
};

