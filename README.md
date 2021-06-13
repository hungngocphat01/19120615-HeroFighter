<!--GITHUB LINK: https://github.com/hungngocphat01/19120615-HeroFighter-->
<!--Private repo, em sẽ public sau khi thầy khoá deadline-->

<div align="center">
<h2>ĐỒ ÁN CUỐI KỲ</h2>
<h1>THỰC HÀNH PHƯƠNG PHÁP LẬP TRÌNH HƯỚNG ĐỐI TƯỢNG</h1>
LỚP 19_1, HỌC KỲ 2 NĂM HỌC 2020 - 2021 
</div>
 
# 1. Thông tin chung
- Mô phỏng game HeroFighter trên console.
- Sinh viên thực hiện: HÙNG NGỌC PHÁT -- 19120615.
- Môi trường phát triển: 
  - Microsoft Visual Studio 2019, 
  - Microsoft Windows 10 21H1.
- Trình biên dịch: Microsoft Visual C++ Compiler (MSCV).
- Chuẩn ngôn ngữ: MSVC C++14.
- Ngày bắt đầu: 20/05/2021.
- Ngày kết thúc: 13/06/2021.
- Hoàn tất debug: --
- Số lượng dòng code (báo cáo từ lệnh `cloc`):
  ```
  -------------------------------------------------------------------------------
  Language                     files          blank        comment           code
  -------------------------------------------------------------------------------
  C++                              8            176            154           1001
  C/C++ Header                     7             75            106            239
  -------------------------------------------------------------------------------
  SUM:                            15            251            260           1240
  -------------------------------------------------------------------------------
  ```

- Sơ đồ lớp: 
<div align="center">
 <img src="19120615 - Class Diagram.png">
</div>

# 2. Về quy tắc đặt tên biến
- Hầu hết tên biến đều được đặt bằng tiếng Việt, đôi khi sẽ phải viết tắt để tiết kiệm không gian.<br>
  Một số vị trí mà dùng tiếng Việt không được phù hợp lắm thì em xin phép được ghi tiếng Anh.
- Tất cả các biến toàn cục được đặt theo camelCase nhưng có thêm tiền tố `gl~` (global). <br>Vd: `glExample`.
- Tất cả các hằng số (const) đều được viết HOA TOÀN BỘ, hoặc camelCase nhưng có thêm tiền tố `HeSo~`.
- Tất cả class sẽ được đặt tên dạng PascalCase (ViếtHoaCácChữCáiĐầu).
- Tất cả các tên tham số hình thức sẽ được viết bằng toàn bộ chữ cái thường.
- Các biến phát sinh bên trong hàm/phương thức sẽ được viết thường hoặc camelCase tuỳ trường hợp.
- Các phương thức/hàm sẽ được đặt tên dạng camelCase (chữĐầuViếtThường).
- Các thuộc tính lớp cũng sẽ được đặt theo camelCase nhưng có thêm kiểu dữ liệu ở trước để phân biệt.<br>
  Một số ví dụ:<br>
  ```c++
  float     fExample;
  int       iExample;
  char*     strAnotherExample; (or std::string)
  vector<T> arrYetAnotherExample;
  ```
- Các alias cho các kiểu dữ liệu có sẵn (để cho có thêm một tí xíuu syntax sugar) thì được viết bằng chữ cái viết thường, kèm thêm hậu tố `_t`.<br>
  Vd: `attribute_t, result_t, vfuncptr_t, ...`
- Một số quy tắc khác, vd như tên hàm là entry được gọi từ 1 menu khác luôn bắt đầu bằng `entry`, còn tên hàm bên trong có chứa menu thì bắt đầu bằng `menu`, ...<br>

# 3. Danh sách các module/class được implement
Ở đây em chỉ liệt kê và ghi vắn tắt công dụng của các module/class được nêu. Cụ thể hơn thì thầy vui lòng đọc comment được ghi ở đầu mỗi module.
- `class Hero`: lớp trừu tượng biểu diễn các thông tin chung nhất của các hero.
- `class HeroFire, HeroMetal, ...`: các lớp cụ thể cho từng hệ hero. (IS-A Hero).
- `class Team`: lớp để quản lí một đội chơi (HAS-A Hero).
- `class Logging`: lớp phát sinh thêm để quản lý logging.
- `class Menu`: một thư viện menu tự chế với khả năng tuỳ biến cao, sử dụng lambda expression và con trỏ hàm thay vì 1 dãy các if-else như truyền thống.
- `class MatchManager`: tập hợp các hàm static liên quan tới tạo trận đấu.
- `Module Utils`: chứa các hàm tiện ích riêng lẻ.

# 4. Build và chạy
- Import project vào Visual Studio và build như bình thường.
