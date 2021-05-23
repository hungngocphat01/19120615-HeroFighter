#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
* Đây là class em thiết kế thêm để tự động hoá việc tạo và xử lí các menu
*/

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

	// Hàm thêm 1 entry mới vào menu, gồm tên entry 
	// và con trỏ hàm trỏ tới code cần thực thi khi chọn entry đó
	void themEntryMoi(string, vfuncptr_t);

	// Hiển thị một menu, lặp mãi mãi đến khi user chọn thoát
	// Nếu có exception thì throw về menu trước, đến main menu thì throw ra hàm main
	void hienThi(bool clrscr = true);
};

