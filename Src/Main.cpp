#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

// Định nghĩa các hằng số giới hạn số lượng
#define MAX_READER 100
#define MAX_BOOKS 100
#define MAX_LOANS 100

// Đường kẻ vạch để trang trí cho chương trình
void header1(){
    cout << "---------------------------------------------------------\n";
}

void header2(){
    cout << "=========================================================\n";
}


// 1. Quản lý độc giả
// a. Xem danh sách độc giả ở trong thư viện
void viewReader();
// b. Thêm độc giả
void addReader();
// c. Chỉnh sửa thông tin của một độc giả
void editReader();
// d. Xóa thông tin của một độc giả
void removeReader();
// e. Tìm kiếm độc giả theo CCCD
void FindReaderBaseOnCCCD();
// f. Tìm kiếm độc giả theo họ tên
void FindReaderBaseOnName();

int main()
{
    // Khai báo các kiểu dữ liệu cần thiết để có thể thực hiện chương trình
    // Các kiểu dữ liệu cho việc quản lý độc giả
    char readerName[MAX_READER][100]; // Tên độc giả
    char readerId[MAX_READER][100]; // Mã độc giả
    char readerCCCD[MAX_READER][100]; // CCCD
    char readerMail[MAX_READER][100]; // Email độc giả
    char readerAddress[MAX_READER][100]; // Địa chỉ độc giả
    char readerGender[MAX_READER][100]; // Giới tính độc giả (Nam, nữ, Khác)
    int readerBirthday[MAX_READER][3]; // Ngày sinh của độc giả
    int readerCardDates[MAX_READER][2]; // Ngày lập thẻ (ngày, tháng)
    int readerExpiryDate[MAX_READER][2]; // Ngày hết hạn (ngày, tháng)

    // Các kiểu dữ liệu cho việc quản lý sách
    char bookISBN[MAX_BOOKS][20]; // ISBN của sách
    char bookTitles[MAX_BOOKS][100]; // Tiêu đề của sách
    char bookAuthor[MAX_BOOKS][100]; // Tác giả của sách
    char bookPublisher[MAX_BOOKS][100]; // Nhà xuất bản của sách
    int bookPublishedYear[MAX_BOOKS]; // Năm Xuất bản
    char bookGenres[MAX_BOOKS][50]; // Thể loại của sách
    int bookPrices[MAX_BOOKS]; // Giá của sách
    int bookQuantities[MAX_BOOKS]; // Số lượng của sách

    // Khái báo dữ liệu về phiếu mượn sách
    char loanReaderIDs[MAX_LOANS][20];   // Mã độc giả
    int loanDates[MAX_LOANS][3];         // Ngày mượn (ngày, tháng, năm)
    int returnDates[MAX_LOANS][3];       // Ngày trả dự kiến (ngày, tháng, năm)
    int returnDatesActual[MAX_LOANS][3]; // Ngày trả thực tế (ngày, tháng, năm)
    char loanBooks[MAX_LOANS][10][20];   // ISBN các sách được mượn
    int loanBookCount[MAX_LOANS];    // Số lượng sách mượn trong mỗi phiếu
    // Nhập vào lựa chọn của người dùng
    int choice;
    cout << "Hay nhap vao lua chon yeu cau cua ban: \n";
    do
    {
        header1();
        cout << "1. Quan ly doc gia.\n";
        cout << "2. Quan ly sach.\n";
        cout << "3. Quan ly phieu muon sach.\n";
        cout << "4. Thong ke.\n";
        cout << "0. Thoat chuong trinh.\n";
        cin >> choice;
        header1();
        switch(choice){
            case 1:
            {
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            default:
            {
                cout << "Lua chon khong hop le, xin hay nhap lai.\n";
                break;
            }
        }
    } while (choice != 0);
    return 0;
}