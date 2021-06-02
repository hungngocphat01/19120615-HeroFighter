#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <iostream>
#include <sstream>
using namespace std;

/*
* File này khai báo và định nghĩa các hàm tiện ích lẻ tẻ không thuộc 
* một lĩnh vực cụ thể nào (nên em không nhét mấy hàm này vào chung 1 class)
*/

// Hàm cắt một chuỗi thành nhiều chuỗi con
static vector<string> splitString(string str, char dlmtr) 
{
	stringstream ss;
	vector<string> result;
	ss << str;

	while (!ss.eof()) {
		string elem;
		getline(ss, elem, dlmtr);
		// Bỏ qua các chuỗi bị rỗng nếu có
		if (elem.length() == 0) {
			continue;
		}
		result.push_back(elem);
	}
	return result;
}

inline void sleep(int milisec)
{
	this_thread::sleep_for(std::chrono::milliseconds(milisec));
}

inline void stdinBufferClear()
{
	cin.ignore(INT_MAX, '\n');
}