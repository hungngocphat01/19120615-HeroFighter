#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>
#include "HerowAttribute.h"
#include "Menu.h"
#include "Utils.h"
/*
* Đây là class để quản lý các đội chơi
*/

class Team
{
	friend class Logger;
protected:
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

	// Hiển thị lực lượng
	void hienThiLucLuong();

	// Hiển thị kết quả (lực lượng sau khi đập nhau te tua)
	void hienThiKetQua();

	// Số thành viên
	int soLuongThanhVien();

	// Lựa chọn thành viên cho đội (phương thức tạo tuỳ vào loại đội Human hay NPC)
	virtual void luaChonThanhVien() = 0;

	// Cho team bắt đầu đấu với team khác
	result_t batDauDauVoi(Team*);

	virtual ~Team();
};

// Do team khi đấu với user và team khi đấu với npc khác nhau ở chỗ chọn thành viên nên em tách ra làm 2 class con

class TeamNPC : public Team
{
public:
	void luaChonThanhVien() override;
};

class TeamHuman : public Team
{
public:
	void luaChonThanhVien() override;
};

// Em đặt 2 biến Team toàn cục để dễ chia nhỏ chương trình thành nhiều module khác nhau
// Xuyên suốt chương trình, 2 con trỏ này sẽ luôn được giải phóng trước khi cấp phát lại 
// (double check) nên khó xảy ra tình trạng rò rỉ bộ nhớ.
extern Team* glTeam1;
extern Team* glTeam2;


