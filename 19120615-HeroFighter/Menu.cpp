#include "Menu.h"

void Menu::themEntryMoi(string description, vfuncptr_t callback)
{
	this->arrEntries.push_back(description);
	this->arrActions.push_back(callback);
}

void Menu::hienThi(bool clrscr)
{
	if (clrscr) 
	{
		system("cls");
	}

	// Lambda expression
	vfuncptr_t printLine = []()
	{
		cout << "--------------------------" << endl;
	};

	while (true)
	{
		cout << header << endl;
		printLine();
		cout << menu_title << endl;
		printLine();

		// In ra các arrEntries
		for (int i = 0; i < arrEntries.size(); i++) {
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
