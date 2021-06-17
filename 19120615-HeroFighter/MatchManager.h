#pragma once
#include "Logging.h"
#include "Team.h"
#include "Menu.h"

/*
* File khai báo các đoạn code sẽ được thực thi trong 
* các menu khi entry tương ứng được chọn.
*/

extern string glUsername;

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

/*
-Lập trình viên khi sử dụng module này sẽ thao tác với menu tạo trận đấu qua interface menuTaoTranDau()
- Hàm này sẽ hỏi user chọn đấu với NPC hay User, và sẽ gọi các hàm tương ứng entryDauVoiNPC(), entryDauVoiUser()
  2 hàm này có các đoạn code khác nhau để tạo team cho user 2 (NPC hoặc user).
- Sau khi tạo xong team cho user 2 và nhập các thông tin cần thiết, cả 2 hàm này sẽ gọi hàm batDauTranDau()
  Hàm batDauTranDau() sẽ chứa những đoạn code chung cho tạo trận đấu (giống nhau ở cả đấu với NPC hay user),
  vd như random ra hệ, hiển thị kết quả sau khi kết thúc trận đấu, ghi dữ liệu ra file log, ...
*/