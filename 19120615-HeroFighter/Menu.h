#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include "Utils.h"
using namespace std;

/*
* Đây là class em thiết kế thêm để tự động hoá việc tạo và xử lí các menu
* Khả năng tuỳ biến đủ nhiều để implement các menu trong game này
*/

// Delegate kiểu () -> void
using vfuncptr_t = function<void()>; // vfuncptr_t = void function pointer type

class Menu
{
private:
	// Mấy cái tên này em xin dùng tiếng Anh vì dịch ra tiếng Việt nhìn hơi kì
	vector<string> arrEntries;
	vector<vfuncptr_t> arrActions;
public:
	string strHeader = "DO AN CUOI KY THUC HANH OOP\nHERO FIGHTER SIMULATOR\n(c) 2021 HUNG NGOC PHAT 19120615";
	string strTieuDe;

	// Có xoá màn hình trước khi hiện menu này không?
	bool blXoaManHinh = true;

	// Có hiển thị lại menu này sau khi chạy xong entry đã chọn không?
	bool blHienThiLai = true;

	// Constructor có cả strHeader và title
	Menu(string, string);
	// Constructor chỉ có title
	Menu(string);

	// Hàm thêm 1 entry mới vào menu, gồm tên entry 
	// và con trỏ hàm trỏ tới code cần thực thi khi chọn entry đó
	void themEntryMoi(string, vfuncptr_t);

	// Hiển thị một menu, lặp mãi mãi đến khi user chọn thoát.
	// Nếu có exception thì throw về menu trước, đến main menu thì throw ra hàm main.
	// Tham số: phần code custom cần chạy trước khi hiển thị menu dưới dạng.
	//              con trỏ hàm hoặc lambda expression (mặc định là không có).
	void hienThi(vfuncptr_t custom = nullptr);

	// In ra header của menu
	void hienthiHeader();
};
