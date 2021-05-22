#pragma once

#include <string>
#include <vector>
#include <sstream>
using namespace std;

// Hàm cắt một chuỗi thành nhiều chuỗi con
static vector<string> SplitString(string str, char dlmtr) 
{
	stringstream ss;
	vector<string> result;
	ss << str;

	while (!ss.eof()) {
		string elem;
		getline(ss, elem);
		// Bỏ qua các chuỗi bị rỗng nếu có
		if (elem.length() == 0) {
			continue;
		}
		result.push_back(elem);
	}
	return result;
}