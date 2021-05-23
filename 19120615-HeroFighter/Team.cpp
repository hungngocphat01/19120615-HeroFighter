#include "Team.h"

Team::Team(string ten)
{
	this->strTenDoiChoi = ten;
}

void Team::themThanhVienMoi(string data)
{
	Hero* newhero = Hero::taoHeroMoi(data);
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

Team::~Team()
{
	for (Hero*& thanhvien : arrThanhVien) {
		delete thanhvien;
	}
}
