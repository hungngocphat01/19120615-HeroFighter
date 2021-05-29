// Dưới đây là một số thông tin chung về đồ án này. 
// Thầy có thể nhấn vào dấu (+) ở đầu hàng CHUTHICH để xem qua nội dung ạ.
#pragma region CHUTHICH
/*
 										ĐỒ ÁN CUỐI KỲ
 						THỰC HÀNH PHƯƠNG PHÁP LẬP TRÌNH HƯỚNG ĐỐI TƯỢNG
						     LỚP 19_1, HỌC KỲ 2 NĂM HỌC 2020 - 2021 
  
                                     1. THÔNG TIN CHUNG
* Mô phỏng game HeroFighter trên console.
* Sinh viên thực hiện: HÙNG NGỌC PHÁT -- 19120615.

* Môi trường phát triển: Microsoft Visual Studio 2019, 
                         Microsoft Windows 10 21H1.
* Trình biên dịch: Microsoft Visual C++ Compiler (MSCV).
* Chuẩn ngôn ngữ: MSVC C++14.

* Ngày bắt đầu: 20/05/2021.
* Ngày kết thúc: --
* Hoàn tất debug: --
 
                                    2. VỀ QUY TẮC ĐẶT TÊN
* Hầu hết các trường hợp em xin thuân thủ theo quy tắc mà thầy đã nêu trong file docx. 
  Tuy nhiên, em xin bổ sung thêm một số thay đổi tí xíuuu để phù hợp hơn với thói quen code của mình.
  Em cũng xin phép được CÓ một vài dòng trống để code của mình dễ đọc hơn (vd: giữa 2 phần logic khác nhau),
  nhưng không quá 2 dòng trống liên tiếp.

* Hầu hết tên biến đều được đặt bằng tiếng Việt, đôi khi sẽ phải viết tắt để tiết kiệm không gian.
  Một số vị trí mà dùng tiếng Việt không được phù hợp lắm thì em xin phép được ghi tiếng Anh.
* Tất cả các biến toàn cục được đặt theo camelCase nhưng có thêm tiền tố "gl~" (global).
* Tất cả các hằng số (const) đều được viết HOA TOÀN BỘ, hoặc camelCase nhưng có thêm tiền tố "HeSo~".
* Tất cả class sẽ được đặt tên dạng PascalCase (ViếtHoaCácChữCáiĐầu).
* Tất cả các tên tham số hình thức sẽ được viết bằng toàn bộ chữ cái thường.
* Các biến phát sinh bên trong hàm/phương thức sẽ được viết thường hoặc camelCase tuỳ trường hợp.
* Các phương thức/hàm sẽ được đặt tên dạng camelCase (chữĐầuViếtThường).
* Các thuộc tính lớp cũng sẽ được đặt theo camelCase nhưng có thêm kiểu dữ liệu ở trước để phân biệt
  Một số ví dụ:
	* float     fExample;
	* int       iExample;
	* char*     strAnotherExample; (or std::string)
	* vector<T> arrYetAnotherExample;
* Các alias cho các kiểu có sẵn (để cho có thêm một tí xíuu syntax sugar) thì được viết bằng chữ cái viết
  thường, kèm thêm hậu tố "_t"
  Vd: attribute_t, result_t, vfuncptr_t, ...

	                  3. CÁC MODULE/CLASS ĐƯỢC IMPLEMENT TRONG PROJECT NÀY
* Ở đây em chỉ liệt kê và ghi vắn tắt công dụng của các module/class được nêu. Cụ thể hơn thì
  thầy vui lòng đọc comment được ghi ở đầu mỗi module.
	* class Hero: lớp trừu tượng biểu diễn các thông tin chung nhất của các hero.
	* class HeroFire, HeroMetal, ...: các lớp cụ thể cho từng hệ hero.
	* class Team: lớp để quản lí một đội chơi.
	* class Logging: lớp phát sinh thêm để quản lý logging.
	* class Menu: một thư viện menu tự chế với khả năng tuỳ biến cao bằng lambda expression.
	* Module Utils: chứa các hàm tiện ích riêng lẻ.
*/
#pragma endregion 

#include "MenuEntries.h"

Team glTeam1;
Team glTeam2;
ifstream Logger::strmLogFile;

int main() 
{
	srand(time(NULL));
	// Tạo layout cho menu chính
	Menu mainmenu = Menu("Menu chinh");
	// Hiển thị layout và hỏi tên người chơi
	mainmenu.inHeader();
	cout << "Nhap ten user 1: ";
	getline(cin, glTeam1.strTenDoiChoi);
	system("cls");
	
	// Thêm các trường cho menu chính
	mainmenu.themEntryMoi("Xem log", xemLog);
	mainmenu.themEntryMoi("Bat dau tran dau", taoTranDau);

	// Show ra màn hình
	try 
	{
		Hero::napDanhSachHero("ListHero.txt");
		Logger::strmLogFile.open("HeroFighterLog.txt");
		mainmenu.hienThi([] () 
		{
			cout << "Xin chao, " << glTeam1.strTenDoiChoi << endl << endl;
		});
	}
	catch (exception& e) 
	{
		cout << "\n\n";
		Logger::themLog("Da co loi xay ra khi chay chuong trinh: " + string(e.what()));

		system("pause");
		if (Logger::strmLogFile.is_open()) 
		{
			Logger::strmLogFile.close();
		}
	}
	
	return 0;
}