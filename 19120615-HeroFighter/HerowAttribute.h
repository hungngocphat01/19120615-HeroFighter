#pragma once
#include "Hero.h"
#include "Utils.h"
#include <vector>
#include <exception>
#include <stdexcept>

class HeroMetal : public Hero 
{
public:
	// Kế thừa tất cả constructor
	using Hero::Hero;

	virtual attribute_t thuocTinh() const override { return KIM; }
	virtual result_t batDauDanh(Hero&) override;
	virtual void capNhtThgSoTheoMoiTrg(attribute_t) override;
	virtual void capNhtThgSoTrongTeam(Hero&) override;
};

class HeroWood : public Hero 
{
public:
	using Hero::Hero;
	virtual attribute_t thuocTinh() const override { return MOC; }
	virtual result_t batDauDanh(Hero&) override;
	virtual void capNhtThgSoTheoMoiTrg(attribute_t) override;
	virtual void capNhtThgSoTrongTeam(Hero&) override;
};

class HeroWater : public Hero 
{
public:
	using Hero::Hero;
	virtual attribute_t thuocTinh() const override { return THUY; }
	virtual result_t batDauDanh(Hero&) override;
	virtual void capNhtThgSoTheoMoiTrg(attribute_t) override;
	virtual void capNhtThgSoTrongTeam(Hero&) override;
};

class HeroFire : public Hero 
{
public:
	using Hero::Hero;
	virtual attribute_t thuocTinh() const override { return HOA; }
	virtual result_t batDauDanh(Hero&) override;
	virtual void capNhtThgSoTheoMoiTrg(attribute_t) override;
	virtual void capNhtThgSoTrongTeam(Hero&) override;
};

class HeroEarth : public Hero 
{
public:
	using Hero::Hero;
	virtual attribute_t thuocTinh() const override { return THO; }
	virtual result_t batDauDanh(Hero&) override;
	virtual void capNhtThgSoTheoMoiTrg(attribute_t) override;
	virtual void capNhtThgSoTrongTeam(Hero&) override;
};

