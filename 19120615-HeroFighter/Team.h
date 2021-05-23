#pragma once
#include "HerowAttribute.h"
#include <vector>

/*
* Đây là class để quản lý các đội chơi
*/

class Team
{
private:
	vector<Hero*> arrThanhVien;
public:
	Team(string ten);
	Team();

	string strTenDoiChoi;
	// Chèn một member mới vào team
	// Mỗi khi chèn sẽ kiểm tra và trừ/tăng điểm các thành viên còn lại tương ứng
	void themThanhVienMoi(string);

	// Cập nhật môi trường cho các thành viên team
	// Hàm này phải được gọi sau khi thêm đủ các thành viên team vào
	void capNhatMoiTruong(attribute_t);

	// Đọc team từ file
	void docTuFile(const ifstream&);

	virtual ~Team();
};

// Em đặt 2 biến Team toàn cục để dễ chia nhỏ chương trình thành nhiều module khác nhau
extern Team glTeam1;
extern Team glTeam2;


