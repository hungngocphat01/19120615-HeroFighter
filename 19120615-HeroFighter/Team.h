#pragma once
#include "HerowAttribute.h"
#include <vector>

/*
* Đây là class để quản lý các đội chơi
*/

// 2 biến toàn cục để chứa tên các user 
// Em đặt làm biến toàn cục để dễ chia nhỏ chương trình thành nhiều module khác nhau
extern string glUsername1;
extern string glUsername2;

class Team
{
private:
	vector<Hero*> arrThanhVien;
public:
	Team(string ten);
	string strTenDoiChoi;
	// Chèn một member mới vào team
	// Mỗi khi chèn sẽ kiểm tra và trừ/tăng điểm các thành viên còn lại tương ứng
	void themThanhVienMoi(string);

	// Cập nhật môi trường cho các thành viên team
	// Hàm này phải được gọi sau khi thêm đủ các thành viên team vào
	void capNhatMoiTruong(attribute_t);

	virtual ~Team();
};

