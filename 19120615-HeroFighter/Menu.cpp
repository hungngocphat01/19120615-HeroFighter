#include "Menu.h"

// Lambda expression
void printLine()
{
	cout << "-------------------------------" << endl;
};

Menu::Menu(string strHeader, string title)
{
	this->strHeader = strHeader;
	this->strTieuDe = title;
}

Menu::Menu(string title)
{
	this->strTieuDe = title;
}

void Menu::themEntryMoi(string description, vfuncptr_t callback)
{
	this->arrEntries.push_back(description);
	this->arrActions.push_back(callback);
}

void Menu::hienThi(vfuncptr_t customfunc)
{
	try 
	{
		while (true)
		{
			inHeader();

			if (customfunc != nullptr) 
			{
				customfunc();
			}

			// In ra các arrEntries
			for (unsigned i = 0; i < arrEntries.size(); i++) 
			{
				cout << i + 1 << ". " << arrEntries[i] << "." << endl;
			}
			cout << "0. Quay lai menu truoc" << endl;
			printLine();
			cout << "Lua chon: ";
			short choice;
			cin >> choice;
			cin.ignore();

			if (choice == 0) 
			{
				break;
			}

			vfuncptr_t action = arrActions[choice - 1];
			action();

			if (!blHienThiLai) 
			{
				break;
			}
		}
	}
	catch (exception& e) {
		throw e;
	}
}

void Menu::inHeader()
{
	if (blXoaManHinh)
	{
		system("cls");
	}
	cout << strHeader << endl;
	printLine();
	cout << strTieuDe << endl;
	printLine();
}
