#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

/*
* Đây là class em thiết kế thêm để tự động hoá việc tạo và xử lí các menu
*/

// Alias cho delegate kiểu void() -> void
using vfuncptr_t = function<void()>;

class Menu
{
private:
	// Mấy cái tên này em xin dùng tiếng Anh vì dịch ra tiếng Việt nhìn hơi kì
	vector<string> arrEntries;
	vector<vfuncptr_t> arrActions;
public:
	string header = "HERO FIGHTER SIMULATOR\n(c) 2021 HUNG NGOC PHAT 19120615";
	string menu_title;

	// Constructor có cả header và title
	Menu(string, string);
	// Constructor chỉ có title
	Menu(string);

	// Hàm thêm 1 entry mới vào menu, gồm tên entry 
	// và con trỏ hàm trỏ tới code cần thực thi khi chọn entry đó
	void themEntryMoi(string, vfuncptr_t);

	// Hiển thị một menu, lặp mãi mãi đến khi user chọn thoát
	// Nếu có exception thì throw về menu trước, đến main menu thì throw ra hàm main
	// Tham số đầu: phần code custom cần chạy trước khi hiển thị menu (mặc định là không)
	// Tham số sau: có cần clear screen hay không (mặc định là có)
	void hienThi(vfuncptr_t custom = nullptr, bool clrscr = true);

	// Chạy menu nhưng không hiển thị nội dung menu mà chỉ hiện tiêu đề menu,
	// nội dung tuỳ chỉnh được truyền vào dưới dạng lambda expression
	void customMenu(vfuncptr_t);
};

