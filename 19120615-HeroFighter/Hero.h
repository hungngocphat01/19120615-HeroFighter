#pragma once
#include <string>
#include <map>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

/*
* File này khai báo abstract class Hero, chứa các thông tin 
* và hành động cơ bản của tất cả các hero, không phụ thuộc vào ngũ hệ.
* Các hàm có phụ thuộc vào ngũ hệ sẽ là hàm thuần ảo.
*/

enum { TRUNGHOA, TSINH, TKHAC };	// trung hoà, tương sinh, tương khắc
enum { KIM, MOC, THUY, HOA, THO };	// các thuộc tính (hệ)
enum { THUA, THANG, HUE };			// kết quả trận đấu (thua, thắng, huề)

// Thời gian chờ của cả trận đấu
extern float glThoiGianTranDau;

// Một số alias cho kiểu int để dùng ENUM (để code nhìn đẹp hơn)
typedef int attribute_t;
typedef int result_t;

class Hero
{
protected:
	string sTen;
	float fMau;		// máu
	float fCong;	// công
	float fThu;		// thủ
	float fTocDo;	// tốc độ

	// Cho hero này tấn công hero kia
	// Hàm này không thể được gọi bừa bãi mà chỉ có thể được gọi từ hàm public batDauDanh
	void TanCong(Hero&);

	float fThGianCho = 0; // thời gian chờ còn lại khi đánh

public:
	// Danh sách các hero có thể sử dụng
	static vector<string> danhSachHero;

	// Nạp danh sách các hero từ file
	static void napDanhSachHero(ifstream&);

	Hero(string name, float hp, float atk, float def, float spd);
	
	// Phân tích một chuỗi (đọc từ file) và tạo hero thích hợp
	static Hero* taoHeroMoi(string);

	// Bắt đầu một trận đấu cho hero này với 1 hero khác, trả về kết quả (THUA, THANG, HUE)
	virtual result_t batDauDanh(Hero&);

	// Vì mấy hàm này tên muốn đầy đủ ý nghĩa phải viết dài một tí nên em xin phép viết tắt một số từ

	// Cập nhật lại các thông số khi hero 1 khắc hero 2 trong trận đấu
	static void capNhtThgSoKhiDoiPhBiKhac(Hero&, Hero&); // cập nhật thông số khi đối phương bị khắc

	/* Cập nhật lại các thông số cho một cặp hero trong 1 đội (dựa vào tính khắc hay sinh).
	 * Vd như hero this là mộc, hero trong tham số là hoả (mộc sinh hoả) nên điểm của hero tham số
	 * sẽ tăng lên. Còn nếu hero trong tham số là kim (kim khắc mộc) thì điểm của hero this sẽ bị giảm.
	*/
	virtual void capNhtThgSoTrongTeam(Hero&) = 0; // cập nhật thông số trong team

	// Cập nhật thông số khi bị đồng đội khắc
	virtual void capNhtThgSoKhiBiDngDoiKhac();

	// Cập nhật lại các thông số cho bản thân khi được sinh bởi đồng đội
	virtual void capNhtThgSoKhiDcDngDoiSinh();

	// Cập nhật lại các thuộc tính theo môi trường
	virtual void capNhtThgSoTheoMoiTrg(attribute_t) = 0; // cập nhật thông số theo môi trường

	// Trả về thuộc tính của hero hiện tại
	virtual attribute_t thuocTinh() const = 0;

	// Các getter
	
	string getTen() const;
	float getMau() const;
	float getCong() const;
	float getThu() const;
	float getTocDo() const;
	float getThGianCho() const;
};