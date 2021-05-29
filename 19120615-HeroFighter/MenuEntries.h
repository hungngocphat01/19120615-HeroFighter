#pragma once
#include "Logging.h"
#include "Team.h"
#include "Menu.h"
#include "Logging.h"

/*
* File khai báo các đoạn code sẽ được thực thi trong 
* các menu khi entry tương ứng được chọn.
*/

// Khi user chọn xem log từ main menu
void xemLog();
// Khi user chọn bắt đầu trận đấu từ main menu
void taoTranDau();
// Entry đấu với npc trong menu trận đấu
void dauVoiNPC();
// Entry đấu với user trong menu trận đấu
void dauVoiUser();

// Bắt đầu đấu
void batDauTranDau();
