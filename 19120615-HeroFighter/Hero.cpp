#include "Hero.h"

Hero::Hero()
{
	// Không làm gì cả
}

Hero::Hero(string name, float hp, float atk, float def, float spd)
{
	Name = name;
	HP = hp;
	ATK = atk;
	DEF = def;
	SPD = spd;
}

Hero& Hero::Fight(Hero& h1, Hero& h2)
{
	/*
		- Ai có thời gian chờ = 0 được đánh trước.
		- Giả sử A đánh B.
		- A đánh B xong thì A phải chờ 1 khoảng thời gian. Do đó gán A.WAIT = A.SPD
		- Đồng thời giảm thời gian chờ của đối phương xuống 1 ms.
		- Giảm thời gian chờ trận đấu xuống 1 ms.
		- Tiếp tục lặp đến khi 1 trong 2 chết hoặc hết giờ.
	*/

	UpdateSpecs(h1, h2, KHACDOI);

	// Thực hiện đánh tới khi nào một trong 2 thua (máu <= 0)
	while (h1.HP * h2.HP > 0 && FightTime > 0) {
		// Ai có thời gian chờ = 0 được đánh trước
		// Bằng nhau thì pick random
		
		if (h1.WAIT == 0 && h2.WAIT == 0) {
			int r = rand() % 2 + 1;
			if (r == 1) {
				h1.Attack(h2);
			}
			else {
				h2.Attack(h1);
			}
		}
		else if (h1.WAIT == 0) {
			h1.Attack(h2);
		}
		else if (h2.WAIT == 0) {
			h2.Attack(h1);
		}

		FightTime--;
	}
}

pair<int, int> Hero::CheckAttribute(Hero& h1, Hero& h2)
{
	return pair<int, int>(0, 0);
}

void Hero::Attack(Hero& o)
{
	o.HP -= (this->ATK - o.DEF);
	this->WAIT = this->SPD;

	if (o.WAIT > 0) {
		o.WAIT--;
	}
}

void Hero::UpdateSpecs(Hero& h1, Hero& h2, int team)
{
	pair<int, int> r = CheckAttribute(h1, h2);
	
	if (team == CUNGDOI) {
		// h1 sinh h2
		if (r.first == TUONGSINH) {
			h2.HP *= 1.15;
		}
		// h1 khắc h2
		else if (r.first == TUONGKHAC) {
			h2.SPD *= 1.1;
		}
		// h2 sinh h1
		if (r.second == TUONGSINH) {
			h1.HP *= 1.15;
		}
		// h2 khắc h1
		else if (r.second == TUONGKHAC) {
			h1.SPD *= 1.1;
		}
	}
	else {
		// h1 khắc h2
		if (r.first == TUONGKHAC) {
			h2.DEF *= 0.5;
			h1.ATK *= 1.1;
		}
		// h2 khắc h1
		else if (r.second == TUONGKHAC) {
			h1.DEF *= 0.5;
			h2.ATK *= 1.1;
		}
	}
}
