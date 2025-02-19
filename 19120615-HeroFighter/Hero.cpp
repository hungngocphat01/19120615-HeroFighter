﻿#include "Hero.h"

/*
* File này implement các hàm trong abstract class Hero, chứa các thông tin
* và hành động cơ bản của tất cả các hero, không phụ thuộc vào ngũ hệ.
*/

vector<string> Hero::arrDanhSachHero;
const string glBangTraThuocTinh[] = { KIM, MOC, THUY, HOA, THO };

// Hệ số thủ của đối phương bị giảm khi đối thủ bị khắc (conquered enemy def factor)
constexpr float HeSoThuKhiDthBiKhac = 0.5F;
// Hệ số công của hero đánh được tăng khi đối thủ bị khắc (conquered enemy my atk factor)
constexpr float HeSoCngKhiDthBiKhac = 1.1F; 
// Hệ số thời gian ra đòn của hero bị khắc tăng (conquered by teammate speed factor)
constexpr float HeSoTdoKhiBiDgDoiKhac = 1.1F;
// Hệ số máu được tăng của hero được tương sinh (generated by teammate hp factor)
constexpr float HeSoMauKhiDcDgDoiSinh = 1.15F;

float glThoiGianTranDau = 0;

// Nạp danh sách hero từ file (chỉ nạp và lưu trữ chuỗi, không phân tích)
void Hero::napDanhSachHero(string filename)
{
	ifstream fin;
	fin.open(filename);

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			string line;
			getline(fin, line);
			// Nếu dòng có ít hơn 11 kí tự thì không hợp lệ, bỏ qua (5 dấu ; và ít nhất 6 kí tự cho các trường thông tin)
			if (line.size() <= 10) {
				continue;
			}
			arrDanhSachHero.push_back(line);
		}
		fin.close();
	}
	else {
		throw invalid_argument("Tap tin danh sach hero khong ton tai: " + filename);
	}
}

// Constructor
Hero::Hero(string name, float hp, float atk, float def, float spd)
{
	sTen = name;
	fMau = hp;
	fCong = atk;
	fThu = def;
	fTocDo = spd;
}

// Bắt đầu trận đấu giữa this và 1 hero khác.
// Trả về: THANG, THUA, HUE
result_t Hero::batDauDanh(Hero* enemy)
{
	/*
		- Ai có thời gian chờ = 0 được đánh trước.
		- Giả sử A đánh B.
		- A đánh B xong thì A phải chờ 1 khoảng thời gian. Do đó gán A.fThoiGianCho = A.fTocDo
		- Giảm thời gian chờ trận đấu và của cả 2 xuống 1 ms.
		- Tiếp tục lặp đến khi 1 trong 2 chết hoặc hết giờ.
	*/

	// Thực hiện đánh tới khi nào một trong 2 thua (máu <= 0)
	while (this->fMau * enemy->fMau > 0 && glThoiGianTranDau > 0) {
		// Ai có thời gian chờ = 0 được đánh trước
		// Bằng nhau thì pick random
		
		if (this->fThGianCho == 0 && enemy->fThGianCho == 0) {
			int r = rand() % 2 + 1;
			if (r == 1) {
				this->TanCong(enemy);
			}
			else {
				enemy->TanCong(this);
			}
		}
		else if (this->fThGianCho <= 0) {
			this->TanCong(enemy);
		}
		else if (enemy->fThGianCho <= 0) {
			enemy->TanCong(this);
		}

		glThoiGianTranDau--;
		this->fThGianCho--;
		enemy->fThGianCho--;
	}

	// Nếu máu <= 0 thì xem là thua (máu được phép âm để người dùng thấy được mình bị hụt bao nhiêu máu)
	if (this->fMau <= 0) {
		return THUA;
	}
	else if (enemy->fMau <= 0) {
		return THANG;
	}
	else
	{
		return HUE;
	}
}

// Cập nhật thông số khi đối phương bị khắc
void Hero::capNhtThgSoKhiDoiPhBiKhac(Hero* h1, Hero* h2)
{
	h2->fThu *= HeSoThuKhiDthBiKhac;
	h1->fCong *= HeSoCngKhiDthBiKhac;
}

// Cập nhật thông số khi bị đồng đội khắc
void Hero::capNhtThgSoKhiBiDngDoiKhac()
{
	this->fTocDo *= HeSoTdoKhiBiDgDoiKhac;
}

// Cập nhật thông số khi được đồng đội sinh
void Hero::capNhtThgSoKhiDcDngDoiSinh()
{
	this->fMau *= HeSoMauKhiDcDgDoiSinh;
}

// Tấn công (private, chỉ có thể được gọi từ interface là batDauDanh)
void Hero::TanCong(Hero* enemy)
{
	enemy->fMau -= (this->fCong - enemy->fThu);
	this->fThGianCho = this->fTocDo;
	this->iSoDonDanh++;
}

// Các getter 

string Hero::getTen() const
{
	return this->sTen;
}

float Hero::getMau() const
{
	return this->fMau;
}

float Hero::getCong() const
{
	return this->fCong;
}

float Hero::getThu() const
{
	return this->fThu;
}

float Hero::getTocDo() const
{
	return this->fTocDo;
}

float Hero::getThGianCho() const
{
	return this->fThGianCho;
}
