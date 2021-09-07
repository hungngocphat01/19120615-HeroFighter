#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <ctime>
#include "Menu.h"
#include "Team.h"
#include "Utils.h"
using namespace std;
/*
* Đây là module em xây dựng thêm để handle logging dễ dàng hơn
*/

// Cấu trúc để biểu diễn thông tin của một dòng trong file log
struct LogEntry
{
	// Thời gian diễn ra trận đấu
	int iday;
	int imonth;
	int iyear;
	int ihour;
	int iminute;

	// Các thông tin của 2 đội chơi
	string strTen1;
	string strTen2;
	vector<string> arrLucLuongTeam1;
	vector<string> arrLucLuongTeam2;
	// Người thắng cuộc (1 hoặc 2)
	int iNguoiThangCuoc;

	void print();
	string to_string();
	static LogEntry parse(string inp);
};

// Static class chứa các hàm để quản lí file log
/* Cách sử dụng
- Trong khi thực hiện chương trình, lập trình viên sẽ gọi các hàm "ghi...()" để record lại thông tin 
  cho trận đấu hiện tại vào bộ nhớ tạm.
- Khi trận đấu kết thúc, lập trình viên phải gọi hàm commit() để ghi dữ liệu tạm đó xuống file
*/

// Một dòng log sau khi ghi xuống file sẽ có cấu trúc:
// DD \t MM \t YYYY \t hh \t mm \t TenDoiChoi1 \t SoLuongTV \t <CacThanhVien> \t TenDoiChoi2 \t SoLuongTV \t <CacThanhVien> \t NguoiThangCuoc
class Logger
{
private:
	static LogEntry logbuffer;
public:	
	// File log cần sử dụng
	static string strLogFileName;

	static void ghiThoiGian();
	static void ghiTenDoiChoi(string, string);
	static void ghiLucLuong(int, Team*);
	static void ghiKetQua(int);

	static void commit();
	static void entryHienThiLog();
};

