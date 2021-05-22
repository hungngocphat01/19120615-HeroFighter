#pragma once
#include<string>
#include<vector>
using namespace std;

// Kiểu con trỏ trỏ tới 1 hàm void
typedef void (*vfuncptr_t)();

class Menu
{
private:
	vector<string> entries;
	vector<vfuncptr_t> actions;
public:
	void AddNewEntry(string, vfuncptr_t);
	void Show();
};

