#pragma once
#include "Hero.h"
#include "Utils.h"
#include <vector>
#include <exception>
#include <stdexcept>

class HeroMetal : public Hero {
public:
	// Kế thừa tất cả constructor
	using Hero::Hero;

	virtual attribute_t Attribute() const override { return METAL; }
	virtual result_t Fight(Hero&) override;
	virtual void UpdtPntsBsdOnEnvrnmnt(attribute_t) override;
	virtual void UpdtPntsInTeam(Hero&) override;
};

class HeroWood : public Hero {
public:
	using Hero::Hero;
	virtual attribute_t Attribute() const override { return WOOD; }
	virtual result_t Fight(Hero&) override;
	virtual void UpdtPntsBsdOnEnvrnmnt(attribute_t) override;
	virtual void UpdtPntsInTeam(Hero&) override;
};

class HeroWater : public Hero {
public:
	using Hero::Hero;
	virtual attribute_t Attribute() const override { return WATER; }
	virtual result_t Fight(Hero&) override;
	virtual void UpdtPntsBsdOnEnvrnmnt(attribute_t) override;
	virtual void UpdtPntsInTeam(Hero&) override;
};

class HeroFire : public Hero {
public:
	using Hero::Hero;
	virtual attribute_t Attribute() const override { return FIRE; }
	virtual result_t Fight(Hero&) override;
	virtual void UpdtPntsBsdOnEnvrnmnt(attribute_t) override;
	virtual void UpdtPntsInTeam(Hero&) override;
};

class HeroEarth : public Hero {
public:
	using Hero::Hero;
	virtual attribute_t Attribute() const override { return EARTH; }
	virtual result_t Fight(Hero&) override;
	virtual void UpdtPntsBsdOnEnvrnmnt(attribute_t) override;
	virtual void UpdtPntsInTeam(Hero&) override;
};

