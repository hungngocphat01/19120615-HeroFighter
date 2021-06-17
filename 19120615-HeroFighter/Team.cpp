#include "Team.h"

// Constructor
Team::Team(string ten)
{
	this->strTenDoiChoi = ten;
}

Team::Team()
{
	strTenDoiChoi = "";
}

// Thêm thành viên mới vào đội (phân tích chuỗi nạp từ file và tạo hero tương ứng)
void Team::themThanhVienMoi(string hero)
{
	Hero* newhero = Hero::taoHeroMoi(hero);

	// Cập nhật lại điểm số cho từng cặp hero mỗi khi thêm vào
	for (Hero*& member : arrThanhVien) {
		newhero->capNhtThgSoTrongTeam(member);
	}
	arrThanhVien.push_back(newhero);
}

// Cập nhật thông số dựa theo môi trường cho các thành viên của đội
void Team::capNhatMoiTruong(attribute_t mtr)
{
	for (Hero*& member : arrThanhVien) {
		member->capNhtThgSoTheoMoiTrg(mtr);
	}
}

// Hiển thị toàn bộ lực lượng của đội dưới dạng bảng
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
			<< setw(6) << (int)hero->getMau()
			<< setw(6) << hero->getCong()
			<< setw(6) << hero->getThu()
			<< setw(6) << hero->getTocDo() 
			<< endl;
	}
}

// Hiển thị kết quả sau khi đánh
void Team::hienThiKetQua()
{
	cout << "Luc luong cua " << this->strTenDoiChoi << ":" << endl;
	cout << setw(20) << "Ten"
		<< setw(6) << "Mau"
		<< setw(5) << "  So don danh da ra"
		<< endl;

	for (Hero* hero : arrThanhVien)
	{
		cout << setw(20) << hero->getTen()
			<< setw(6) << (int)hero->getMau()
			<< setw(5) << hero->iSoDonDanh
			<< endl;
	}
}

// Lấy số lượng thành viên của đội
int Team::soLuongThanhVien()
{
	return this->arrThanhVien.size();
}

// Hàm chứa menu để chọn thành viên cho đội người chơi
void TeamHuman::luaChonThanhVien()
{
	Menu menu("Lua chon thanh vien cho " + this->strTenDoiChoi);
	bool valid = false;
	while (!valid)
	{
		menu.hienthiHeader();
		for (int i = 0; i < Hero::arrDanhSachHero.size(); i++)
		{
			cout << i + 1 << ". " << Hero::arrDanhSachHero.at(i) << endl;
		}
		cout << "Hay nhap 3 con so lien tiep (cach nhau boi 01 dau cach) de chon dong doi cho " << strTenDoiChoi << "!" << endl;
		cout << "Nhap: ";

		int x, y, z;
		cin >> x >> y >> z;
		stdinBufferClear();

		if (max({ x, y, z }) > Hero::arrDanhSachHero.size() || min({ x, y, z }) <= 0)
		{
			cout << "Ban da nhap mot so khong hop le. Vui long kiem tra lai!" << endl;
			valid = false;
			system("pause");
		}
		else {
			valid = true;
			for (int i : {x, y, z})
			{
				this->themThanhVienMoi(Hero::arrDanhSachHero[i - 1]);
			}
		}
	}
}

result_t Team::batDauDauVoi(Team* doithu)
{
	// Bắt đầu cho đấu theo từng cặp
	int thangCount = 0;
	int thuaCount = 0;

	for (int i = 0; i < 3; i++)
	{
		Hero* h1 = this->arrThanhVien[i];
		Hero* h2 = doithu->arrThanhVien[i];
		cout << "Cap thu " << i + 1 << ": " << h1->getTen() << " vs " << h2->getTen() << "!" << endl;
		sleep(2000);
		result_t kq = h1->batDauDanh(h2);

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

		sleep(1000);
		if (glThoiGianTranDau <= 0)
		{
			cout << "Tran dau da het gio! Cac cap con lai se khong thi dau nua!" << endl;
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

void Hero::menuQuanLyHero()
{
	Menu menu("Quan ly hero");

	menu.themEntryMoi("Them hero", []() {
		glFlagDSHeroThayDoi = true;
		cout << "\nHay nhap thong tin cho hero moi theo dinh dang sau:" << endl;
		cout << "Ten;Thuoc tinh;Mau;Cong;Thu;Toc do" << endl;
		cout << "Vd: Treant Protector;Wood;700;62;1.5;38" << endl;
		cout << "Luu y: neu ban nhap sai, chuong trinh se khong the tao duoc hero do. Hay kiem tra ky truoc khi ENTER." << endl << endl;
		cout << "Nhap: ";

		string s;
		getline(cin, s);
		if (s.size() <= 10)
		{
			cout << "Khong du thong tin, hay nhap lai." << endl;
			system("pause");
			// Thoát khỏi anonymous function này chứ ko thoát khỏi hàm bên ngoài
			return;
		}
		Hero::arrDanhSachHero.push_back(s);

		cout << "Da them hero vao danh sach." << endl;
		system("pause");
	});

	menu.themEntryMoi("Xoa hero", []() {
		glFlagDSHeroThayDoi = true;
		cout << "Nhap STT cua hero can xoa trong danh sach tren: ";
		int i;
		cin >> i;
		stdinBufferClear();

		if (i > Hero::arrDanhSachHero.size() || i <= 0) {
			cout << "Ban da nhap mot so khong hop le!" << endl;
			system("pause");
			return;
		}

		string deletedhero = Hero::arrDanhSachHero[--i];

		cout << "\nBan co chac chan muon xoa hero " << deletedhero << "?" << endl;
		cout << "Nhap [y/n]: ";
		char c;
		cin >> c;
		stdinBufferClear();

		if (tolower(c) == 'y') {
			Hero::arrDanhSachHero.erase(Hero::arrDanhSachHero.begin() + i);
			cout << "Da xoa hero." << endl;
		}
		else {
			cout << "Yeu cau da duoc huy." << endl;
		}
		system("pause");
	});

	menu.themEntryMoi("Sua hero", []() {
		glFlagDSHeroThayDoi = true;
		cout << "Nhap STT cua hero can sua trong danh sach tren: ";
		int i;
		cin >> i;
		stdinBufferClear();

		if (i > Hero::arrDanhSachHero.size() || i <= 0) {
			cout << "Ban da nhap mot so khong hop le!" << endl;
			system("pause");
			return;
		}

		cout << "\nHay nhap thong tin cho hero moi theo dinh dang sau:" << endl;
		cout << "Ten;Thuoc tinh;Mau;Cong;Thu;Toc do" << endl;
		cout << "Vd: Treant Protector;Wood;700;62;1.5;38" << endl << endl;
		cout << "Luu y: neu ban nhap sai, chuong trinh se khong the tao duoc hero do. Hay kiem tra ky truoc khi ENTER." << endl << endl;
		cout << "Nhap: ";
		string s;
		getline(cin, s);
		if (s.size() <= 10)
		{
			cout << "Khong du thong tin, hay nhap lai." << endl;
			system("pause");
			return;
		}

		cout << "\nBan co chac chan muon sua hero sau\n" << Hero::arrDanhSachHero[--i] << "?" << endl;
		cout << "Nhap [y/n]: ";
		char c;
		cin >> c;
		stdinBufferClear();

		if (tolower(c) == 'y') {
			Hero::arrDanhSachHero[i] = s;
		}
		else {
			cout << "Yeu cau da duoc huy." << endl;
		}
		system("pause");
	});

	menu.hienThi([]() {
		cout << "Danh sach hero:" << endl;
		cout << "Ten;Thuoc tinh;Mau;Cong;Thu;Toc do" << endl << endl;
		for (int i = 0; i < Hero::arrDanhSachHero.size(); i++) {
			cout << i + 1 << ". " << Hero::arrDanhSachHero[i] << endl;
		}
		cout << "----------------------------------" << endl;
		cout << "Hay nhap lua chon trong menu ben duoi:" << endl;
	});
}

// Đối với team của NPC, các thành viên sẽ được lựa chọn một cách ngẫu nhiên
void TeamNPC::luaChonThanhVien()
{
	// Những số đã random rồi, không random lại
	vector<int> daRandomRoi;

	int i = 0;
	while (i < 3)
	{
		int r = rand() % Hero::arrDanhSachHero.size();

		// Nếu chọn rồi thì không chọn lại nữa
		if (find(daRandomRoi.begin(), daRandomRoi.end(), r) != daRandomRoi.end())
		{
			continue;
		}
		else
		{
			string herodata = Hero::arrDanhSachHero.at(i);
			Hero* hero = Hero::taoHeroMoi(herodata);
			this->arrThanhVien.push_back(hero);
			i++;
		}
	}
}
