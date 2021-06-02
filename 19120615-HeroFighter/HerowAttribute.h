#pragma once
#include "Hero.h"
#include <vector>
#include <exception>
#include <stdexcept>

/*
* File này khai báo các Hero cụ thể có thuộc tính (Hero with Attribute), kế thừa từ lớp cha Hero.
* Vì số lượng hero là rất nhiều nên em xin bỏ hết vào một file cho tiện quản lý.
* Những hàm này đều là override của các hàm bên Hero (đã có comment rất kỹ) nên em xin phép không ghi
  thêm comment ở bên này nữa.
*/

class HeroMetal : public Hero 
{
public:
	// Kế thừa tất cả constructor
	using Hero::Hero;

	attribute_t thuocTinh() const override;
	result_t batDauDanh(Hero&) override;
	void capNhtThgSoTheoMoiTrg(attribute_t) override;
	void capNhtThgSoTrongTeam(Hero&) override;
};

class HeroWood : public Hero 
{
public:
	using Hero::Hero;
	attribute_t thuocTinh() const override;
	result_t batDauDanh(Hero&) override;
	void capNhtThgSoTheoMoiTrg(attribute_t) override;
	void capNhtThgSoTrongTeam(Hero&) override;
};

class HeroWater : public Hero 
{
public:
	using Hero::Hero;
	attribute_t thuocTinh() const override;
	result_t batDauDanh(Hero&) override;
	void capNhtThgSoTheoMoiTrg(attribute_t) override;
	void capNhtThgSoTrongTeam(Hero&) override;
};

class HeroFire : public Hero 
{
public:
	using Hero::Hero;
	attribute_t thuocTinh() const override;
	result_t batDauDanh(Hero&) override;
	void capNhtThgSoTheoMoiTrg(attribute_t) override;
	void capNhtThgSoTrongTeam(Hero&) override;
};

class HeroEarth : public Hero 
{
public:
	using Hero::Hero;
	attribute_t thuocTinh() const override;
	result_t batDauDanh(Hero&) override;
	void capNhtThgSoTheoMoiTrg(attribute_t) override;
	void capNhtThgSoTrongTeam(Hero&) override;
};

