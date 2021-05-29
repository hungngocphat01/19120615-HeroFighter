#include "Team.h"

Team::Team(string ten)
{
	this->strTenDoiChoi = ten;
}

Team::Team()
{
	strTenDoiChoi = "";
}

void Team::themThanhVienMoi(string hero)
{
	Hero* newhero = Hero::taoHeroMoi(hero);

	// Cập nhật lại điểm số cho từng cặp hero mỗi khi thêm vào
	for (Hero*& member : arrThanhVien) {
		newhero->capNhtThgSoTrongTeam(*member);
	}
	arrThanhVien.push_back(newhero);
}

void Team::capNhatMoiTruong(attribute_t mtr)
{
	for (Hero*& member : arrThanhVien) {
		member->capNhtThgSoTheoMoiTrg(mtr);
	}
}

void Team::hienThiLucLuong()
{
	cout << "Luc luong cua " << this->strTenDoiChoi << ":" << endl;
	cout << setw(20) << "Ten"
		<< setw(6) << "Mau"
		<< setw(6) << "Cong"
		<< setw(6) << "Thu"
		<< setw(6) << "T.do"
		<< endl;

	for (Hero* hero : arrThanhVien)
	{
		cout << setw(20) << hero->getTen()
			<< setw(6) << hero->getMau()
			<< setw(6) << hero->getCong()
			<< setw(6) << hero->getThu()
			<< setw(6) << hero->getTocDo() 
			<< endl;
	}
}

void Team::hienThiKetQua()
{
	cout << "Luc luong cua " << this->strTenDoiChoi << ":" << endl;
	cout << setw(20) << "Ten"
		<< setw(6) << "Mau"
		<< "So don danh da ra"
		<< endl;

	for (Hero* hero : arrThanhVien)
	{
		cout << setw(20) << hero->getTen()
			<< setw(6) << hero->getMau()
			<< hero->iSoDonDanh
			<< endl;
	}
}

int Team::soLuongThanhVien()
{
	return this->arrThanhVien.size();
}

void Team::luaChon()
{
	Menu menu("Lua chon thanh vien cho " + this->strTenDoiChoi);
	bool valid = false;
	while (!valid)
	{
		menu.inHeader();
		cout << "Hay nhap 3 con so lien tiep (cach nhau boi dau cach) de chon 3 dong doi cua minh!" << endl;
		for (int i = 0; i < Hero::danhSachHero.size(); i++)
		{
			cout << i + 1 << ". " << Hero::danhSachHero.at(i) << endl;
		}
		cout << "Nhap 3 so: ";
		int x, y, z;
		cin >> x >> y >> z;
		cin.ignore();

		if (max({ x, y, z }) > Hero::danhSachHero.size())
		{
			cout << "Ban da nhap mot so khong hop le. Vui long kiem tra lai!" << endl;
			valid = false;
			system("pause");
		}
		else {
			valid = true;
			for (int i : {x, y, z})
			{
				this->themThanhVienMoi(Hero::danhSachHero[i - 1]);
			}
		}
	}
}

void Team::taoNgauNhien()
{
	// Những số đã random rồi, không random lại
	vector<int> daRandomRoi;

	int i = 0;
	while (i < 3)
	{
		int r = rand() % Hero::danhSachHero.size();

		// Nếu chọn rồi thì không chọn lại nữa
		if (find(daRandomRoi.begin(), daRandomRoi.end(), r) != daRandomRoi.end())
		{
			continue;
		}
		else
		{
			string herodata = Hero::danhSachHero.at(i);
			Hero* hero = Hero::taoHeroMoi(herodata);
			this->arrThanhVien.push_back(hero);
			i++;
		}
	}
}

void Team::xoa()
{
	this->arrThanhVien.clear();
}

result_t Team::batDauDauVoi(Team& doithu)
{
	// Bắt đầu cho đấu theo từng cặp
	int thangCount = 0;
	int thuaCount = 0;

	for (int i = 0; i < 3; i++)
	{
		Hero* h1 = this->arrThanhVien[i];
		Hero* h2 = doithu.arrThanhVien[i];
		cout << "Cap thu " << i + 1 << ": " << h1->getTen() << " vs " << h2->getTen() << "!" << endl;
		result_t kq = h1->batDauDanh(*h2);

		switch (kq)
		{
		case THANG:
			cout << h1->getTen() << " cua team 1 da thang!" << endl << endl;
			thangCount++;
			break;
		case THUA:
			cout << h2->getTen() << " cua team 2 da thang!" << endl << endl;
			thuaCount++;
			break;
		case HUE:
			cout << "2 ben hoa nhau!" << endl << endl;
			break;
		}
	}

	system("pause");

	if (thangCount == thuaCount)
	{
		return HUE;
	}
	return (thangCount > thuaCount);
}

Team::~Team()
{
	for (Hero*& thanhvien : arrThanhVien) {
		delete thanhvien;
	}
}
