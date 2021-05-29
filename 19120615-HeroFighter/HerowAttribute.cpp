#include "HerowAttribute.h"

/*
* File này implement hàm cho các Hero cụ thể có thuộc tính (Hero with Attribute), 
* kế thừa từ lớp cha Hero. Vì số lượng hero là rất nhiều nên em xin bỏ hết vào 
* một file cho tiện quản lý.
*/

/*************** KHU VỰC IMPLEMENT HÀM batDauDanh ***************/

// Các hàm batDauDanh được override này sẽ thực hiện việc trừ điểm 
// của đối phương nếu tương khắc sau đó sẽ gọi lại hàm đánh của lớp cha

result_t HeroMetal::batDauDanh(Hero& doithu)
{
    // Kim khắc mộc
    if (doithu.thuocTinh() == MOC) {
        capNhtThgSoKhiDoiPhBiKhac(*this, doithu);
    }
    // Gọi lại hàm đánh của lớp cha
    return Hero::batDauDanh(doithu);
}

result_t HeroWood::batDauDanh(Hero& doithu)
{
    // Mộc khắc thổ
    if (doithu.thuocTinh() == THO) {
        capNhtThgSoKhiDoiPhBiKhac(*this, doithu);
    }
    // Gọi lại hàm đánh của lớp cha
    return Hero::batDauDanh(doithu);
}

result_t HeroEarth::batDauDanh(Hero& doithu)
{
    // Thổ khắc thuỷ
    if (doithu.thuocTinh() == THUY) {
        capNhtThgSoKhiDoiPhBiKhac(*this, doithu);
    }
    // Gọi lại hàm đánh của lớp cha
    return Hero::batDauDanh(doithu);
}

result_t HeroWater::batDauDanh(Hero& doithu)
{
    // Thuỷ khắc hoả
    if (doithu.thuocTinh() == HOA) {
        capNhtThgSoKhiDoiPhBiKhac(*this, doithu);
    }
    // Gọi lại hàm đánh của lớp cha
    return Hero::batDauDanh(doithu);
}   

result_t HeroFire::batDauDanh(Hero& doithu)
{
    // Hoả khắc kim
    if (doithu.thuocTinh() == KIM) {
        capNhtThgSoKhiDoiPhBiKhac(*this, doithu);
    }
    // Gọi lại hàm đánh của lớp cha
    return Hero::batDauDanh(doithu);
}

/*************** KHU VỰC IMPLEMENT HÀM TaoHeroMoi ***************/

Hero* Hero::taoHeroMoi(string inp) {
    vector<string> info = splitString(inp, ';');
    if (info.size() != 6) {
        throw invalid_argument("Khong the tao hero do thieu hoac du tham so: " + inp);
    }

    Hero* h;
    enum { TEN, TTINH, MAU, CONG, THU, TDO };

    try 
    {
        string name = info[TEN];
        attribute_t ttinh = info[TTINH];
        float mau = stof(info[MAU]);
        float cong = stof(info[CONG]);
        float thu = stof(info[THU]);
        float tdo = stof(info[TDO]);

        if (info[TTINH] == KIM)
            h = new HeroMetal(name, mau, cong, thu, tdo);
        else if (info[TTINH] == MOC)
            h = new HeroWood(name, mau, cong, thu, tdo);
        else if (info[TTINH] == THUY)
            h = new HeroWater(name, mau, cong, thu, tdo);
        else if (info[TTINH] == HOA)
            h = new HeroFire(name, mau, cong, thu, tdo);
        else if (info[TTINH] == THO)
            h = new HeroEarth(name, mau, cong, thu, tdo);
        else
            throw invalid_argument("Thuoc tinh khong hop le: " + ttinh);

        return h;
    }
    catch (exception& e)
    {
        throw e;
    }
}

/*************** KHU VỰC IMPLEMENT HÀM capNhtThgSoTheoMoiTrg ***************/

// Hệ số tăng máu và giảm tốc độ nếu hợp môi trường
constexpr float HeSoMauSinhMtr = 1.05F;
constexpr float HeSoTdoSinhMtr = 0.9F;
// Hệ số giảm máu nếu trái môi trường
constexpr float HeSoMauKhacMtr = 0.97F;

void HeroMetal::capNhtThgSoTheoMoiTrg(attribute_t moitruong)
{
    // Thổ sinh kim
    if (moitruong == THO) {
        this->fMau *= HeSoMauSinhMtr;
    }
    // Hoả khắc kim
    else if (moitruong == HOA) {
        this->fMau *= HeSoMauKhacMtr;
    }
}

void HeroWater::capNhtThgSoTheoMoiTrg(attribute_t moitruong)
{
    // Kim sinh thuỷ
    if (moitruong == KIM) {
        this->fMau *= HeSoMauSinhMtr;
    }
    // Thổ khắc thuỷ
    else if (moitruong == THO) {
        this->fMau *= HeSoMauKhacMtr;
    }
}

void HeroWood::capNhtThgSoTheoMoiTrg(attribute_t moitruong)
{
    // Thuỷ sinh mộc
    if (moitruong == THUY) {
        this->fMau *= HeSoMauSinhMtr;
    }
    // Kim khắc mộc
    else if (moitruong == KIM) {
        this->fMau *= HeSoMauKhacMtr;
    }
}

void HeroFire::capNhtThgSoTheoMoiTrg(attribute_t moitruong)
{
    // Mộc sinh hoả
    if (moitruong == MOC) {
        this->fMau *= HeSoMauSinhMtr;
    }
    // Thuỷ khắc hoả
    else if (moitruong == THUY) {
        this->fMau *= HeSoMauKhacMtr;
    }
}

void HeroEarth::capNhtThgSoTheoMoiTrg(attribute_t moitruong)
{
    // Hoả sinh thổ
    if (moitruong == HOA) {
        this->fMau *= HeSoMauSinhMtr;
    }
    // Mộc khắc thổ
    else if (moitruong == MOC) {
        this->fMau *= HeSoMauKhacMtr;
    }
}

/*************** KHU VỰC IMPLEMENT HÀM capNhtThgSoTrongTeam ***************/

void HeroMetal::capNhtThgSoTrongTeam(Hero& dgdoi)
{
    // Kim sinh thuỷ
    if (dgdoi.thuocTinh() == THUY) {
        dgdoi.capNhtThgSoKhiDcDngDoiSinh();
    }
    // Kim khắc mộc
    else if (dgdoi.thuocTinh() == MOC) {
        dgdoi.capNhtThgSoKhiBiDngDoiKhac();
    }

    // Thổ sinh kim
    if (dgdoi.thuocTinh() == THO) {
        this->capNhtThgSoKhiDcDngDoiSinh();
    }
    // Hoả khắc kim
    else if (dgdoi.thuocTinh() == HOA) {
        this->capNhtThgSoKhiBiDngDoiKhac();
    }
}

void HeroWater::capNhtThgSoTrongTeam(Hero& dgdoi)
{
    // Thuỷ sinh mộc
    if (dgdoi.thuocTinh() == MOC) {
        dgdoi.capNhtThgSoKhiDcDngDoiSinh();
    }
    // Thuỷ khắc hoả
    else if (dgdoi.thuocTinh() == HOA) {
        dgdoi.capNhtThgSoKhiBiDngDoiKhac();
    }

    // Kim sinh thuỷ
    if (dgdoi.thuocTinh() == KIM) {
        this->capNhtThgSoKhiDcDngDoiSinh();
    }
    // Thổ khắc thuỷ
    else if (dgdoi.thuocTinh() == THO) {
        this->capNhtThgSoKhiBiDngDoiKhac();
    }
}

void HeroWood::capNhtThgSoTrongTeam(Hero& dgdoi)
{
    // Mộc sinh hoả
    if (dgdoi.thuocTinh() == HOA) {
        dgdoi.capNhtThgSoKhiDcDngDoiSinh();
    }
    // Mộc khắc thổ
    else if (dgdoi.thuocTinh() == THO) {
        dgdoi.capNhtThgSoKhiBiDngDoiKhac();
    }

    // thuỷ sinh Mộc
    if (dgdoi.thuocTinh() == THUY) {
        this->capNhtThgSoKhiDcDngDoiSinh();
    }
    // Kim khắc Mộc
    else if (dgdoi.thuocTinh() == KIM) {
        this->capNhtThgSoKhiBiDngDoiKhac();
    }
}

void HeroFire::capNhtThgSoTrongTeam(Hero& dgdoi)
{
    // Hoả sinh thổ
    if (dgdoi.thuocTinh() == THO) {
        dgdoi.capNhtThgSoKhiDcDngDoiSinh();
    }
    // Hoả khắc kim
    else if (dgdoi.thuocTinh() == KIM) {
        dgdoi.capNhtThgSoKhiBiDngDoiKhac();
    }

    // Mộc sinh hoả
    if (dgdoi.thuocTinh() == MOC) {
        this->capNhtThgSoKhiDcDngDoiSinh();
    }
    // Thuỷ khắc hoả
    else if (dgdoi.thuocTinh() == THUY) {
        this->capNhtThgSoKhiBiDngDoiKhac();
    }
}

void HeroEarth::capNhtThgSoTrongTeam(Hero& dgdoi)
{
    // Thổ sinh kim
    if (dgdoi.thuocTinh() == KIM) {
        dgdoi.capNhtThgSoKhiDcDngDoiSinh();
    }
    // Thổ khắc thuỷ
    else if (dgdoi.thuocTinh() == THUY) {
        dgdoi.capNhtThgSoKhiBiDngDoiKhac();
    }

    // Hoả sinh thổ
    if (dgdoi.thuocTinh() == HOA) {
        this->capNhtThgSoKhiDcDngDoiSinh();
    }
    // Mộc khắc thổ
    else if (dgdoi.thuocTinh() == MOC) {
        this->capNhtThgSoKhiBiDngDoiKhac();
    }
}

/*************** KHU VỰC IMPLEMENT HÀM thuocTinh ***************/

attribute_t HeroMetal::thuocTinh() const
{
    return KIM;
}
attribute_t HeroWood::thuocTinh() const
{
    return MOC;
}
attribute_t HeroEarth::thuocTinh() const
{
    return THO;
}
attribute_t HeroWater::thuocTinh() const
{
    return THUY;
}
attribute_t HeroFire::thuocTinh() const
{
    return HOA;
}