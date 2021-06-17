#include "Logging.h"

LogEntry Logger::logbuffer;

// Ghi thời gian ra log
void Logger::ghiThoiGian()
{
	time_t t = time(0);
	tm* now = new tm;
	localtime_s(now, &t);

	logbuffer.iday = now->tm_mday;
	logbuffer.imonth = now->tm_mon + 1;
	logbuffer.iyear = now->tm_year + 1900;
	logbuffer.ihour = now->tm_hour;
	logbuffer.iminute = now->tm_min;

	delete now;
}

// Ghi tên đội chơi ra log
void Logger::ghiTenDoiChoi(string team1, string team2)
{
	logbuffer.strTen1 = team1;
	logbuffer.strTen2 = team2;
}

// Ghi lực lượng của 2 đội ra log
void Logger::ghiLucLuong(int teamnum, Team* team)
{
	vector<string> lucluong;

	for (Hero* h : team->arrThanhVien)
	{
		string hs;
		hs += h->getTen() + ";";
		hs += h->thuocTinh() + ";";
		hs += to_string((int)h->getMau()) + ";";
		hs += to_string((int)h->getCong()) + ";";
		hs += to_string((int)h->getThu()) + ";";
		hs += to_string((int)h->getTocDo());

		lucluong.push_back(hs);
	}

	if (teamnum == 1)
	{
		logbuffer.arrLucLuongTeam1.clear();
		logbuffer.arrLucLuongTeam1 = vector<string>(lucluong);
	}
	else {
		logbuffer.arrLucLuongTeam2.clear();
		logbuffer.arrLucLuongTeam2 = vector<string>(lucluong);
	}
}

void Logger::ghiKetQua(int x)
{
	logbuffer.iNguoiThangCuoc = x;
}

// Ghi dữ liệu đệm xuống file
void Logger::commit()
{
	ofstream fout = ofstream(strLogFileName, ios::app);

	if (fout.fail())
	{
		cout << "\nCanh bao: Khong the mo log file de ghi ket qua" << endl;
		return;
	}

	fout << logbuffer.to_string() << endl;
	fout.close();
}

// Đọc log từ file và hiển thị ra màn hình
void Logger::entryHienThiLog()
{
	// Đọc log từ file lên
	ifstream fin = ifstream(strLogFileName);
	if (fin.fail())
	{
		throw runtime_error("Ten file log khong hop le.");
	}
	vector<LogEntry> readEntries;
	while (!fin.eof())
	{
		string temp;
		getline(fin, temp);
		// Nếu mỗi thông tin chỉ chứa 1 kí tự thì 1 chuỗi log hợp lệ cần có ít nhất 42 kí tự
		if (temp.size() < 42)
		{
			continue;
		}
		readEntries.push_back(LogEntry::parse(temp));
	}
	fin.close();

	// Hiển thị log ra màn hình

	int d, m, y;
	cout << "Nhap 3 thong tin ngay, thang, nam cach nhau boi khoang trang: ";
	cin >> d >> m >> y;
	stdinBufferClear();

	bool found = false;
	for (LogEntry lg : readEntries)
	{
		if (lg.iday == d && lg.imonth == m && lg.iyear == y)
		{
			cout << "-----------------------------" << endl;
			lg.print();
			found = true;
		}
	}

	if (!found)
	{
		cout << "Khong tim thay log vao ngay da nhap." << endl;
	}

	system("pause");
}

void LogEntry::print()
{
	cout << "\nThoi gian: ";
	printf_s("%d/%d/%d %d:%d\n", iday, imonth, iyear, ihour, iminute);

	cout << "Team 1: " << strTen1 << endl;
	cout << "Ten;He;Mau;Cong;Thu;T.do" << endl;
	for (string s : arrLucLuongTeam1)
	{
		cout << s << endl;
	}
	cout << "\nTeam 2: " << strTen2 << endl;
	cout << "Ten;He;Mau;Cong;Thu;T.do" << endl;
	for (string s : arrLucLuongTeam2)
	{
		cout << s << endl;
	}
	cout << endl;
	if (iNguoiThangCuoc == 0)
	{
		cout << "2 ben hoa nhau" << endl;
	}
	else
	{
		cout << "Nguoi thang cuoc: " << iNguoiThangCuoc << endl;
	}
}

// DD/MM/YYYY hh:mm\tTenDoiChoi1\tSoLuongTV\t<CacThanhVien>\tTenDoiChoi2\tSoLuongTV\t<CacThanhVien>\tNguoiThangCuoc
string LogEntry::to_string()
{
	// Thông tin thời gian
	string result = std::to_string(iday) + "/"
		+ std::to_string(imonth) + "/"
		+ std::to_string(iyear) + "\t"
		+ std::to_string(ihour) + ":"
		+ std::to_string(iminute) + "\t";
	// Thông tin team 1
	result += strTen1 + "\t" + std::to_string(arrLucLuongTeam1.size()) + "\t";
	for (string s : arrLucLuongTeam1)
	{
		result += s + "\t";
	}
	// Thông tin team 2
	result += strTen2 + "\t" + std::to_string(arrLucLuongTeam2.size()) + "\t";
	for (string s : arrLucLuongTeam2)
	{
		result += s + "\t";
	}
	// Ai thắng?
	result += std::to_string(iNguoiThangCuoc);

	return result;
}

LogEntry LogEntry::parse(string inp)
{
	LogEntry log;
	stringstream ss;
	ss << inp;

	try
	{
		// Các thông tin về thời gian
		ss >> log.iday;
		ss.ignore(1, '/');
		ss >> log.imonth;
		ss.ignore(1, '/');
		ss >> log.iyear;
		ss >> log.ihour;
		ss.ignore(1, ':');
		ss >> log.iminute;
		ss.ignore(1, '\t');

		// Thông tin về đội chơi 1
		getline(ss, log.strTen1, '\t');
		int n;
		ss >> n;
		ss.ignore(1, '\t');
		for (int i = 0; i < n; i++)
		{
			string temp;
			getline(ss, temp, '\t');
			log.arrLucLuongTeam1.push_back(temp);
		}
		// Thông tin về đội chơi 2
		getline(ss, log.strTen2, '\t');
		ss >> n;
		ss.ignore(1, '\t');
		for (int i = 0; i < n; i++)
		{
			string temp;
			getline(ss, temp, '\t');
			log.arrLucLuongTeam2.push_back(temp);
		}

		ss >> log.iNguoiThangCuoc;
	}
	catch (exception& e)
	{
		throw runtime_error("Khong the phan tich dong log do loi: " 
			+ string(e.what()) + "\n" 
			+ inp.substr(0, 20) + "...");
	}
	return log;
}
