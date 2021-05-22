#include "HerowAttribute.h"

/*************** KHU VỰC IMPLEMENT HÀM Fight ***************/

// Các hàm Fight được override này sẽ thực hiện việc trừ điểm 
// của đối phương nếu tương khắc sau đó sẽ gọi lại hàm đánh của lớp cha

result_t HeroMetal::Fight(Hero& enemy)
{
    // Kim khắc mộc
    if (enemy.Attribute() == WOOD) {
        UpdtPntsForCnqrdOppnt(*this, enemy);
    }
    // Gọi lại hàm đánh của lớp cha
    return Hero::Fight(enemy);
}

result_t HeroWood::Fight(Hero& enemy)
{
    // Mộc khắc thổ
    if (enemy.Attribute() == EARTH) {
        UpdtPntsForCnqrdOppnt(*this, enemy);
    }
    // Gọi lại hàm đánh của lớp cha
    return Hero::Fight(enemy);
}

result_t HeroEarth::Fight(Hero& enemy)
{
    // Thổ khắc thuỷ
    if (enemy.Attribute() == WATER) {
        UpdtPntsForCnqrdOppnt(*this, enemy);
    }
    // Gọi lại hàm đánh của lớp cha
    return Hero::Fight(enemy);
}

result_t HeroWater::Fight(Hero& enemy)
{
    // Thuỷ khắc hoả
    if (enemy.Attribute() == FIRE) {
        UpdtPntsForCnqrdOppnt(*this, enemy);
    }
    // Gọi lại hàm đánh của lớp cha
    return Hero::Fight(enemy);
}   

result_t HeroFire::Fight(Hero& enemy)
{
    // Hoả khắc kim
    if (enemy.Attribute() == METAL) {
        UpdtPntsForCnqrdOppnt(*this, enemy);
    }
    // Gọi lại hàm đánh của lớp cha
    return Hero::Fight(enemy);
}

/*************** KHU VỰC IMPLEMENT HÀM CreateNewHero ***************/

Hero* Hero::CreateNewHero(string inp) {
    vector<string> info = SplitString(inp, ';');
    if (info.size() != 6) {
        throw invalid_argument("Khong the tao hero do thieu hoac du tham so: " + inp);
    }

    Hero* h;
    enum { NAME, ATTRIBUTE, HP, ATK, DEF, SPD };

    try 
    {
        string name = info[NAME];
        attribute_t attr = stoi(info[ATTRIBUTE]);
        float hp = stof(info[HP]);
        float atk = stof(info[ATK]);
        float def = stof(info[DEF]);
        float spd = stof(info[SPD]);

        switch (attr)
        {
        case METAL:
            h = new HeroMetal(name, hp, atk, def, spd);
            break;
        case WOOD:
            h = new HeroWood(name, hp, atk, def, spd);
            break;
        case WATER:
            h = new HeroWater(name, hp, atk, def, spd);
            break;
        case FIRE:
            h = new HeroFire(name, hp, atk, def, spd);
            break;
        case EARTH:
            h = new HeroEarth(name, hp, atk, def, spd);
            break;
        default:
            throw invalid_argument("Thuoc tinh khong hop le: " + attr);
        }
        return h;
    }
    catch (exception& e)
    {
        throw e;
    }
}

/*************** KHU VỰC IMPLEMENT HÀM UpdtPntsBsdOnEnvrnmnt ***************/

// Hệ số tăng HP và giảm SPD nếu hợp môi trường
constexpr float GnrtvEnvHPFctr = 1.05;
constexpr float GnrtvEnvSPDFctr = 0.9;
// Hệ số giảm HP nếu trái môi trường
constexpr float DstrctvEnvHPFctr = 0.97;

void HeroMetal::UpdtPntsBsdOnEnvrnmnt(attribute_t envrnmnt)
{
    // Thổ sinh kim
    if (envrnmnt == EARTH) {
        this->HP *= GnrtvEnvHPFctr;
    }
    // Hoả khắc kim
    else if (envrnmnt == FIRE) {
        this->HP *= DstrctvEnvHPFctr;
    }
}

void HeroWater::UpdtPntsBsdOnEnvrnmnt(attribute_t envrnmnt)
{
    // Kim sinh thuỷ
    if (envrnmnt == METAL) {
        this->HP *= GnrtvEnvHPFctr;
    }
    // Thổ khắc thuỷ
    else if (envrnmnt == EARTH) {
        this->HP *= DstrctvEnvHPFctr;
    }
}

void HeroWood::UpdtPntsBsdOnEnvrnmnt(attribute_t envrnmnt)
{
    // Thuỷ sinh mộc
    if (envrnmnt == WATER) {
        this->HP *= GnrtvEnvHPFctr;
    }
    // Kim khắc mộc
    else if (envrnmnt == METAL) {
        this->HP *= DstrctvEnvHPFctr;
    }
}

void HeroFire::UpdtPntsBsdOnEnvrnmnt(attribute_t envrnmnt)
{
    // Mộc sinh hoả
    if (envrnmnt == WOOD) {
        this->HP *= GnrtvEnvHPFctr;
    }
    // Thuỷ khắc hoả
    else if (envrnmnt == WATER) {
        this->HP *= DstrctvEnvHPFctr;
    }
}

void HeroEarth::UpdtPntsBsdOnEnvrnmnt(attribute_t envrnmnt)
{
    // Hoả sinh thổ
    if (envrnmnt == FIRE) {
        this->HP *= GnrtvEnvHPFctr;
    }
    // Mộc khắc thổ
    else if (envrnmnt == WOOD) {
        this->HP *= DstrctvEnvHPFctr;
    }
}

/*************** KHU VỰC IMPLEMENT HÀM UpdtPntsInTeam ***************/

void HeroMetal::UpdtPntsInTeam(Hero& tmmt)
{
    // Kim sinh thuỷ
    if (tmmt.Attribute() == WATER) {
        tmmt.UpdtPntsWhnGnrtdByTmmt();
    }
    // Kim khắc mộc
    else if (tmmt.Attribute() == WOOD) {
        tmmt.UpdtPntsWhnCnqrdByTmmt();
    }

    // Thổ sinh kim
    if (tmmt.Attribute() == EARTH) {
        this->UpdtPntsWhnGnrtdByTmmt();
    }
    // Hoả khắc kim
    else if (tmmt.Attribute() == FIRE) {
        this->UpdtPntsWhnCnqrdByTmmt();
    }
}

void HeroWater::UpdtPntsInTeam(Hero& tmmt)
{
    // Thuỷ sinh mộc
    if (tmmt.Attribute() == WOOD) {
        tmmt.UpdtPntsWhnGnrtdByTmmt();
    }
    // Thuỷ khắc hoả
    else if (tmmt.Attribute() == FIRE) {
        tmmt.UpdtPntsWhnCnqrdByTmmt();
    }

    // Kim sinh thuỷ
    if (tmmt.Attribute() == METAL) {
        this->UpdtPntsWhnGnrtdByTmmt();
    }
    // Thổ khắc thuỷ
    else if (tmmt.Attribute() == EARTH) {
        this->UpdtPntsWhnCnqrdByTmmt();
    }
}

void HeroWood::UpdtPntsInTeam(Hero& tmmt)
{
    // Mộc sinh hoả
    if (tmmt.Attribute() == FIRE) {
        tmmt.UpdtPntsWhnGnrtdByTmmt();
    }
    // Mộc khắc thổ
    else if (tmmt.Attribute() == EARTH) {
        tmmt.UpdtPntsWhnCnqrdByTmmt();
    }

    // thuỷ sinh Mộc
    if (tmmt.Attribute() == WATER) {
        this->UpdtPntsWhnGnrtdByTmmt();
    }
    // Kim khắc Mộc
    else if (tmmt.Attribute() == METAL) {
        this->UpdtPntsWhnCnqrdByTmmt();
    }
}

void HeroFire::UpdtPntsInTeam(Hero& tmmt)
{
    // Hoả sinh thổ
    if (tmmt.Attribute() == EARTH) {
        tmmt.UpdtPntsWhnGnrtdByTmmt();
    }
    // Hoả khắc kim
    else if (tmmt.Attribute() == METAL) {
        tmmt.UpdtPntsWhnCnqrdByTmmt();
    }

    // Mộc sinh hoả
    if (tmmt.Attribute() == WOOD) {
        this->UpdtPntsWhnGnrtdByTmmt();
    }
    // Thuỷ khắc hoả
    else if (tmmt.Attribute() == WATER) {
        this->UpdtPntsWhnCnqrdByTmmt();
    }
}

void HeroEarth::UpdtPntsInTeam(Hero& tmmt)
{
    // Thổ sinh kim
    if (tmmt.Attribute() == METAL) {
        tmmt.UpdtPntsWhnGnrtdByTmmt();
    }
    // Thổ khắc thuỷ
    else if (tmmt.Attribute() == WATER) {
        tmmt.UpdtPntsWhnCnqrdByTmmt();
    }

    // Hoả sinh thổ
    if (tmmt.Attribute() == FIRE) {
        this->UpdtPntsWhnGnrtdByTmmt();
    }
    // Mộc khắc thổ
    else if (tmmt.Attribute() == WOOD) {
        this->UpdtPntsWhnCnqrdByTmmt();
    }
}