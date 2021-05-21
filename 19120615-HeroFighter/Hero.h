#pragma once
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

// Các môi trường
enum {KIM, MOC, THUY, HOA, THO};
enum {KHONG, TUONGSINH, TUONGKHAC};
enum {CUNGDOI, KHACDOI};

// Thời gian chờ của cả trận đấu
extern float FightTime;

class Hero
{
protected:
	string Name;
	float HP;	// máu
	float ATK;	// công
	float DEF;	// thủ
	float SPD;	// tốc độ

	// Cho hero này đánh hero kia
	void Attack(Hero&);

	float WAIT = 0; // thời gian chờ còn lại khi đánh

public:
	Hero();
	Hero(string, float, float, float, float);

	// Bảng tra tương sinh - tương khắc
	// Thuộc tính ở hàng tác dụng lên thuộc tính ở cột
	static constexpr int AttributeLookupTbl[5][5] = {
		// KIM      MOC        THUY       HOA        THO
		{KHONG,     TUONGKHAC, TUONGSINH, KHONG,     KHONG},     // KIM
		{KHONG,     KHONG,     KHONG,     TUONGSINH, TUONGKHAC}, // MOC
		{KHONG,     TUONGSINH, KHONG,     TUONGKHAC, KHONG},     // THUY
		{TUONGKHAC, KHONG,     KHONG,     KHONG,     TUONGSINH}, // HOA
		{TUONGSINH, KHONG,     TUONGKHAC, KHONG,     KHONG}      // THO
	};

	// Cho 2 hero đấu với nhau, trả về hero thắng
	static Hero& Fight(Hero&, Hero&);
	
	// Kiểm tra 2 hero là tương sinh hay tương khắc
	// Trả về 1 cặp số. Số đầu tiên là h1 -> h2, số thứ 2 là h2 -> h1
	// Vd: trả về (TUONGKHAC, TUONGSINH) là h1 khắc h2 và h2 sinh h1
	static pair<int, int> CheckAttribute(Hero& h1, Hero& h2);

	// Cập nhật các chỉ số của 2 bên dựa theo tương sinh, tương khắc
	static void UpdateSpecs(Hero&, Hero&, int);

	// Trả về thuộc tính của tướng
	virtual int Attribute() = 0;
};