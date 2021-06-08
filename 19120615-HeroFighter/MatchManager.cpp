#include "MatchManager.h"

constexpr int HeSoDonViThoiGian = 600;

void MatchManager::menuTaoTranDau()
{
	Menu menu = Menu("Bat dau tran dau");
	// Chơi xong thoát ra main menu luôn
	menu.blHienThiLai = false;

	menu.themEntryMoi("Dau voi may tinh", entryDauVoiNPC);
	menu.themEntryMoi("Dau voi nguoi choi", entryDauVoiUser);

	try
	{
		glTeam1.xoa();
		glTeam2.xoa();
		menu.hienThi();
	}
	catch (exception& e)
	{
		throw e;
	}
}
void MatchManager::entryDauVoiUser()
{
	Menu menu = Menu("Dau voi user!");

	try
	{
		menu.inHeader();

		cout << "Nhap ten cho user 2: ";
		getline(cin, glTeam2.strTenDoiChoi);

		// Cho user chọn team
		glTeam1.luaChon();
		glTeam2.luaChon();

		// Cho user chọn thời gian
		cout << "Nhap thoi gian [1/2/5] don vi tran dau: ";
		cin >> glThoiGianTranDau;
		stdinBufferClear();

		if (glThoiGianTranDau != 1 && glThoiGianTranDau != 2 && glThoiGianTranDau != 5)
		{
			cout << "Ban dau chon sai! Chuong trinh se thoat ra menu chinh." << endl;
			system("pause");
			return;
		}
		glThoiGianTranDau *= HeSoDonViThoiGian; // đổi ra đơn vị thời gian tự chọn

		// Bắt đầu đấu
		batDauTranDau();
	}
	catch (exception& e)
	{
		throw e;
	}
}
void MatchManager::entryDauVoiNPC()
{
	Menu menu = Menu("Dau voi NPC");

	try
	{
		menu.inHeader();
		// Cho user chọn team
		glTeam1.luaChon();
		// Tạo ngẫu nhiên một team cho NPC
		glTeam2.taoNgauNhien();

		// Tạo ngẫu nhiên một tên cho NPC
		vector<string> randomNPCNames = { "Stupid", "Noob", "Loser", "Boring" };

		glTeam2.strTenDoiChoi = randomNPCNames[rand() % (randomNPCNames.size() - 1)] + " AI";

		glThoiGianTranDau = 1 * HeSoDonViThoiGian;

		system("cls");
		menu.inHeader();

		// Bắt đầu đấu
		batDauTranDau();

	}
	catch (exception& e)
	{
		throw e;
	}
}
void MatchManager::batDauTranDau()
{
	try
	{
		Menu menu("Bat dau tran dau");
		menu.inHeader();

		attribute_t moitruong = glBangTraThuocTinh[rand() % 5];
		glTeam1.capNhatMoiTruong(moitruong);
		glTeam2.capNhatMoiTruong(moitruong);

		cout << "Moi truong: " << moitruong << endl << endl;
		cout << "Thoi gian: " << glThoiGianTranDau << "ms" << endl;

		cout << "Tuong quan 2 doi choi: " << endl;
		glTeam1.hienThiLucLuong();
		cout << endl;
		glTeam2.hienThiLucLuong();
		cout << endl;
		system("pause");

		if (glTeam1.soLuongThanhVien() < 3 || glTeam2.soLuongThanhVien() < 3)
		{
			throw length_error("So luong thanh vien cua mot trong 2 doi khong du. Day la loi chuong trinh, hay lien he nha phat trien.");
		}

		system("cls");
		menu.inHeader();

		result_t kq = glTeam1.batDauDauVoi(glTeam2);

		system("cls");
		menu.inHeader();
		if (kq == THANG)
		{
			cout << glTeam1.strTenDoiChoi;
		}
		else if (kq == THUA)
		{
			cout << glTeam2.strTenDoiChoi;
		}
		if (kq != HUE)
		{
			cout << " da danh chien thang chung cuoc!" << endl;
		}
		else
		{
			cout << "Vay la ca 2 doi hoa nhau!" << endl;
		}

		cout << "\nCac thong so con lai nhu sau:" << endl;
		glTeam1.hienThiKetQua();
		glTeam2.hienThiKetQua();

		if (glThoiGianTranDau > 0)
		{
			cout << "\nTran dau ket thuc som.\nThoi gian tran dau con lai: "
				<< glThoiGianTranDau << "." << endl;
		}
		system("pause");
	}
	catch (exception& e)
	{
		throw e;
	}
}
