#pragma once
#include "HerowAttribute.h"
#include <vector>

class Team
{
private:
	vector<Hero*> arrThanhVien;
public:
	// Chèn một member mới vào team
	// Mỗi khi chèn sẽ kiểm tra và trừ/tăng điểm các thành viên còn lại tương ứng
	void themThanhVienMoi(string);

	// Cập nhật môi trường cho các thành viên team
	void capNhatMoiTruong(attribute_t);
};

