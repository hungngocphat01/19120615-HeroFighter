#pragma once
#include "Logging.h"
#include "Team.h"
#include "Menu.h"

/*
* File khai báo các đoạn code sẽ được thực thi trong 
* các menu khi entry tương ứng được chọn.
*/


class MatchManager
{
private:
	// Entry đấu với npc trong menu trận đấu
	static void entryDauVoiNPC();
	// Entry đấu với user trong menu trận đấu
	static void entryDauVoiUser();
	// Bắt đầu đấu
	static void batDauTranDau();
public:
	// Khi user chọn bắt đầu trận đấu từ main menu
	// Các hàm trên không được gọi tuỳ tiện mà phải thông qua interface là menu này
	static void menuTaoTranDau();
};
