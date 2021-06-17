#include "MatchManager.h"

constexpr int HeSoDonViThoiGian = 600;

// Interface để giao tiếp, tạo trận đấu
void MatchManager::menuTaoTranDau()
{
	Menu menu = Menu("Bat dau tran dau");
	// Chơi xong thoát ra main menu luôn
	menu.blHienThiLai = false;

	menu.themEntryMoi("Dau voi may tinh", entryDauVoiNPC);
	menu.themEntryMoi("Dau voi nguoi choi", entryDauVoiUser);

	try
	{
		// Tạo team cho người chơi và hiển thị menu
		mfree(glTeam1);
		glTeam1 = new TeamHuman();
		glTeam1->strTenDoiChoi = glUsername;
		menu.hienThi();
	}
	catch (exception& e)
	{
		throw e;
	}
}

// Hàm xử lý các đoạn code riêng cho trận đấu với user
void MatchManager::entryDauVoiUser()
{
	Menu menu = Menu("Dau voi user!");

	try
	{
		menu.hienthiHeader();

		// Tạo team cho user 2
		mfree(glTeam2);
		glTeam2 = new TeamHuman();
		cout << "Nhap ten cho user 2: ";
		getline(cin, glTeam2->strTenDoiChoi);

		// Cho user chọn team
		glTeam1->luaChonThanhVien();
		glTeam2->luaChonThanhVien();

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
// Hàm xử lý các đoạn code riêng cho trận đấu với NPC
void MatchManager::entryDauVoiNPC()
{
	Menu menu = Menu("Dau voi NPC");

	try
	{
		menu.hienthiHeader();
		// Tạo team cho NPC
		glTeam2 = new TeamNPC();
		// Cho user chọn team
		glTeam1->luaChonThanhVien();
		// Tạo ngẫu nhiên một team cho NPC
		glTeam2->luaChonThanhVien();

		// Tạo ngẫu nhiên một tên cho NPC
		vector<string> randomNPCNames = { "Stupid", "Noob", "Loser", "Boring" };

		glTeam2->strTenDoiChoi = randomNPCNames[rand() % (randomNPCNames.size() - 1)] + " AI";

		// Mặc định: thời gian là 1 phút
		glThoiGianTranDau = 1 * HeSoDonViThoiGian;

		system("cls");
		menu.hienthiHeader();

		// Bắt đầu đấu
		batDauTranDau();

	}
	catch (exception& e)
	{
		throw e;
	}
}

// Hàm xử lý các đoạn code chung cho tạo trận đấu
void MatchManager::batDauTranDau()
{
	try
	{
		// Ghi thông tin trận đấu xuống log
		Logger::ghiThoiGian();
		Logger::ghiTenDoiChoi(glTeam1->strTenDoiChoi, glTeam2->strTenDoiChoi);
		Logger::ghiLucLuong(1, glTeam1);
		Logger::ghiLucLuong(2, glTeam2);

		Menu menu("Tran dau: " + glTeam1->strTenDoiChoi + " vs. " + glTeam2->strTenDoiChoi + "!");
		menu.hienthiHeader();

		attribute_t moitruong = glBangTraThuocTinh[rand() % 5];
		glTeam1->capNhatMoiTruong(moitruong);
		glTeam2->capNhatMoiTruong(moitruong);

		cout << "Moi truong: " << moitruong << endl << endl;
		cout << "Thoi gian: " << glThoiGianTranDau << "ms" << endl;

		cout << "Tuong quan 2 doi choi: " << endl;
		glTeam1->hienThiLucLuong();
		cout << endl;
		glTeam2->hienThiLucLuong();
		cout << endl;
		system("pause");

		if (glTeam1->soLuongThanhVien() < 3 || glTeam2->soLuongThanhVien() < 3)
		{
			throw length_error("So luong thanh vien cua mot trong 2 doi khong du. Day la loi chuong trinh, hay lien he nha phat trien.");
		}

		system("cls");
		menu.hienthiHeader();

		result_t kq = glTeam1->batDauDauVoi(glTeam2);

		system("cls");
		menu.hienthiHeader();
		if (kq == THANG)
		{
			cout << glTeam1->strTenDoiChoi;
			Logger::ghiKetQua(1);
		}
		else if (kq == THUA)
		{
			cout << glTeam2->strTenDoiChoi;
			Logger::ghiKetQua(2);
		}
		if (kq != HUE)
		{
			cout << " da danh chien thang chung cuoc!" << endl;
		}
		else
		{
			cout << "Vay la ca 2 doi hoa nhau!" << endl;
			Logger::ghiKetQua(0);
		}

		cout << "\nCac thong so con lai nhu sau:" << endl;
		glTeam1->hienThiKetQua();
		glTeam2->hienThiKetQua();
		Logger::commit();

		if (glThoiGianTranDau > 0)
		{
			cout << "\nTran dau ket thuc som.\nThoi gian tran dau con lai: "
				<< glThoiGianTranDau << "." << endl;
		}
		mfree(glTeam1);
		mfree(glTeam2);
		system("pause");
	}
	catch (exception& e)
	{
		throw e;
	}
}
