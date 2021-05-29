#include "MenuEntries.h"

void xemLog()
{
}

void taoTranDau()
{
	Menu menu = Menu("Bat dau tran dau");
	// Chơi xong thoát ra main menu luôn
	menu.blHienThiLai = false;
	
	menu.themEntryMoi("Dau voi may tinh", dauVoiNPC);
	menu.themEntryMoi("Dau voi nguoi choi", dauVoiUser);

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

void dauVoiNPC()
{
	Menu menu = Menu("Dau voi NPC");
	
	try 
	{
		menu.inHeader();
		// Cho user chọn team
		glTeam1.luaChon();
		// Tạo ngẫu nhiên một team cho NPC
		glTeam2.taoNgauNhien();
		glTeam2.strTenDoiChoi = "Stupid AI";

		// Cho user chọn thời gian
		cout << "Nhap thoi gian [1/2/5] phut: ";
		cin >> glThoiGianTranDau;

		cin.ignore();

		//if (glThoiGianTranDau != 1 && glThoiGianTranDau != 2 && glThoiGianTranDau != 5) 
		//{
		//	cout << "Ban dau chon sai! Chuong trinh se thoat ra menu chinh." << endl;
		//	system("pause");
		//	return;
		//}
		glThoiGianTranDau *= 60; // đổi ra giây

		system("cls");
		menu.inHeader();

		attribute_t moitruong = glBangTraThuocTinh[rand() % 5];
		glTeam1.capNhatMoiTruong(moitruong);
		glTeam2.capNhatMoiTruong(moitruong);

		cout << "Moi truong: " << moitruong << endl;

		cout << "Tuong quan 2 doi choi: " << endl;
		glTeam1.hienThiLucLuong();
		cout << endl;
		glTeam2.hienThiLucLuong();
		cout << endl;
		system("pause");

		// Bắt đầu đấu
		batDauTranDau();

	}
	catch (exception& e)
	{
		throw e;
	}
}

void dauVoiUser()
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
		cout << "Nhap thoi gian [1/2/5] phut: ";
		cin >> glThoiGianTranDau;
		glThoiGianTranDau *= 60; // đổi ra giây
		cin.ignore();

		//if (glThoiGianTranDau != 1 && glThoiGianTranDau != 2 && glThoiGianTranDau != 5)
		//{
		//	cout << "Ban dau chon sai! Chuong trinh se thoat ra menu chinh." << endl;
		//	system("pause");
		//	return;
		//}

		system("cls");
		menu.inHeader();

		cout << "Tuong quan 2 doi choi: " << endl;
		glTeam1.hienThiLucLuong();
		cout << endl;
		glTeam1.hienThiLucLuong();
		cout << endl;
		system("pause");

		// Bắt đầu đấu
		batDauTranDau();

	}
	catch (exception& e)
	{
		throw e;
	}
}

void batDauTranDau()
{
	try
	{
		Menu match("Dau voi NPC");
		match.inHeader();
		
		if (glTeam1.soLuongThanhVien() < 3 || glTeam2.soLuongThanhVien() < 3)
		{
			cout << "So luong thanh vien cua 1 trong 2 doi khong du! Vui long kiem tra lai." << endl;
			system("pause");
		}

		result_t kq = glTeam1.batDauDauVoi(glTeam2);
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
			cout << "Da danh chien thang chung cuoc!" << endl;
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
			cout << "\nThoi gian con lai: " << glThoiGianTranDau << " giay!" << endl;
		}
		system("pause");
	}
	catch (exception& e) 
	{
		throw e;
	}
}
