#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
/*
* Đây là module em xây dựng thêm để handle logging dễ dàng hơn
*/


// Một "dòng" trong log, không có gì phức tạp nên em dùng kiểu struct
struct LogEntry
{
	int day;
	int month;
	int year;
	int hour;
	int minute;
	int second;
	string content;
};

// Class chứa các hàm để quản lí log
class Logger
{
public:
	// Các "dòng" log
	static vector<LogEntry> arrEntries;
	
	// File log cần sử dụng
	static ifstream strmLogFile;

	// Thêm một dòng vào log
	static void themLog(string content);
	// Đọc log từ file
	static void docTuFile();
	// Ghi log xuống file (ghi đè)
	static void ghiXuongFile();
	// Ghi nối tiếp log xuống file
	static void ghiNoiTiepXuongFile();
	// Entry hiển thị log khi chọn từ main menu
	static void entryHienThiLog();
};

