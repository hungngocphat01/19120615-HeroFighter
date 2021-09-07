#include "MatchManager.h"

Team* glTeam1;
Team* glTeam2;
bool glFlagDSHeroThayDoi = false;
string Logger::strLogFileName;
string glUsername;

int main() 
{
	srand(time(NULL));
	// Tạo layout cho menu chính
	Menu mainmenu = Menu("Menu chinh");
	// Hiển thị layout và hỏi tên người chơi
	mainmenu.hienthiHeader();
	cout << "Hay nhap ten cho nguoi choi 1: ";
	getline(cin, glUsername);
	clearScreen();
	
	// Thêm các trường cho menu chính
	mainmenu.themEntryMoi("Xem log", Logger::entryHienThiLog);
	mainmenu.themEntryMoi("Bat dau tran dau", MatchManager::menuTaoTranDau);
	mainmenu.themEntryMoi("Quan ly hero", Hero::menuQuanLyHero);

	// Show ra màn hình
	try 
	{
		Logger::strLogFileName = "HeroFighterLog.txt";
		Hero::napDanhSachHero("ListHero.txt");
		mainmenu.hienThi([]() {
			cout << "Xin chao, " << glUsername << endl << endl;
		});
	}
	catch (exception& e) 
	{
		cout << "\n\n";
		cout << "Da co loi xay ra khi chay chuong trinh: " + string(e.what()) << endl;
		cout << "Vui long kiem tra lai file input (ListHero.txt) xem thu co gi bat thuong khong truoc khi report cho nha phat trien." << endl;
	}

	pauseProgram();

	// Nếu danh sách hero đã bị thay đổi thì ghi thay đổi đó xuống file (ghi đè toàn bộ danh sách)
	if (glFlagDSHeroThayDoi) 
	{
		ofstream fout = ofstream("ListHero.txt");
		for (string line : Hero::arrDanhSachHero)
		{
			fout << line << endl;
		}
	}

	mfree(glTeam1);
	mfree(glTeam2);

	return 0;
}