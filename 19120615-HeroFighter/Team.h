#pragma once
#include "HerowAttribute.h"
#include <vector>

class Team
{
private:
	vector<Hero*> members;
public:
	// Chèn một member mới vào team
	// Mỗi khi chèn sẽ kiểm tra và trừ/tăng điểm các thành viên còn lại tương ứng
	void InsertNewMember(string);

	// Cập nhật môi trường cho các thành viên team
	void UpdateEnvironment(attribute_t);
};

