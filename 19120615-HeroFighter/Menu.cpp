#include "Menu.h"

// Lambda expression
void printLine()
{
	cout << "--------------------------" << endl;
};

Menu::Menu(string header, string title)
{
	this->header = header;
	this->menu_title = title;
}

Menu::Menu(string title)
{
	this->menu_title = title;
}

void Menu::themEntryMoi(string description, vfuncptr_t callback)
{
	this->arrEntries.push_back(description);
	this->arrActions.push_back(callback);
}

void Menu::hienThi(vfuncptr_t customfunc, bool clrscr)
{
	if (clrscr) 
	{
		system("cls");
	}

	while (true)
	{
		cout << header << endl;
		printLine();
		cout << menu_title << endl;
		printLine();

		if (customfunc != nullptr) {
			customfunc();
		}

		// In ra các arrEntries
		for (unsigned i = 0; i < arrEntries.size(); i++) {
			cout << i + 1 << ". " << arrEntries[i] << "." << endl;
		}
		cout << "0. Quay lai menu truoc" << endl;
		printLine();
		cout << "Lua chon: ";
		short choice;
		cin >> choice;
		cin.ignore();

		if (choice == 0) {
			break;
		}

		vfuncptr_t action = arrActions[choice];
		action();
	}
}

void Menu::customMenu(vfuncptr_t customfunc)
{
	cout << header << endl;
	printLine();
	cout << menu_title << endl;
	printLine();
	customfunc();
}
