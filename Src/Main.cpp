#include "Reader.h"
#include "Book.h"
#include "BookLoan.h"
#include "Query.h"

int main()
{
    // Khai báo các kiểu dữ liệu cần thiết để có thể thực hiện chương trình
    // Các kiểu dữ liệu cho việc quản lý độc giả
    char readerName[MAX_READER][100]; // Tên độc giả
    char readerId[MAX_READER][20]; // Mã độc giả
    char readerCCCD[MAX_READER][100]; // CCCD
    char readerMail[MAX_READER][100]; // Email độc giả
    char readerAddress[MAX_READER][100]; // Địa chỉ độc giả
    char readerGender[MAX_READER][100]; // Giới tính độc giả (Nam, nữ, Khác)
    int readerBirthday[MAX_READER][3] = {0}; // Ngày sinh của độc giả
    int readerCardDates[MAX_READER][3] = {0}; // Ngày lập thẻ (ngày, tháng, nam)
    int readerExpiryDate[MAX_READER][3] = {0}; // Ngày hết hạn (ngày, tháng, nam)
    int countReader = 0;

    // Các kiểu dữ liệu cho việc quản lý sách
    char bookISBN[MAX_BOOKS][20]; // ISBN của sách
    char bookTitles[MAX_BOOKS][100]; // Tiêu đề của sách
    char bookAuthor[MAX_BOOKS][100]; // Tác giả của sách
    char bookPublisher[MAX_BOOKS][100]; // Nhà xuất bản của sách
    char bookGenres[MAX_BOOKS][50]; // Thể loại của sách
    int bookPublishedYear[MAX_BOOKS] = {0}; // Năm Xuất bản
    int bookPrices[MAX_BOOKS] = {0}; // Giá của sách
    int bookQuantities[MAX_BOOKS] = {0}; // Số lượng của sách
    int countBook = 0;
    int totalBooks = 0;
    int remainBooks = 0;

    // Khái báo dữ liệu về phiếu mượn sách
    char loanReaderIDs[MAX_LOANS][20];   // Mã độc giả
    char loanBooks[MAX_LOANS][MAX_BORROWED_BOOKS][20];   // ISBN các sách được mượn
    int loanBookQuantites[MAX_LOANS][MAX_BORROWED_BOOKS] = {0}; // Số lượng sách mà độc giả mượn trong 1 cuốn sách
    int loanDates[MAX_LOANS][3] = {0};         // Ngày mượn (ngày, tháng, năm)
    int returnDates[MAX_LOANS][3] = {0};       // Ngày trả dự kiến (ngày, tháng, năm)
    int returnDatesActual[MAX_LOANS][3] = {0}; // Ngày trả thực tế (ngày, tháng, năm)
    int loanBookCount[MAX_LOANS];    // Số lượng sách mượn trong mỗi phiếu
    int countLoan = 0;
    
    while (1)
    {
        header2();
        cout << "1. Quan ly doc gia.\n";
        cout << "2. Quan ly sach.\n";
        cout << "3. Lap phieu muon sach.\n";
        cout << "4. Lap phieu tra sach.\n";
        cout << "5. Thong ke.\n";
        cout << "0. Thoat chuong trinh.\n";
        header2();
        int choice;
        cout << "Hay nhap vao lua chon yeu cau cua ban: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                while (true)
                {
                    header2();
                    cout << "1. Xem danh sach doc gia.\n";
                    cout << "2. Them doc gia.\n";
                    cout << "3. Chinh sua thong tin cua doc gia.\n";
                    cout << "4. Xoa doc gia.\n";
                    cout << "5. Tim doc gia theo CCCD.\n";
                    cout << "6. Tim doc gia theo ten.\n";
                    cout << "0. Quay lai menu chinh.\n";
                    header2();

                    int readerChoice;
                    cout << "Nhap lua chon ve doc gia: ";
                    cin >> readerChoice;
                    switch (readerChoice)
                    {
                        case 1:
                            viewReader(readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate, countReader);
                            break;
                        case 2:
                            addReader(countReader, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate);
                            break;
                        case 3:
                            editReader(countReader, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate);
                            break;
                        case 4:
                            removeReader(countReader, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate);
                            break;
                        case 5:
                            FindReaderBaseOnCCCD(countReader, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate);
                            break;
                        case 6:
                            FindReaderBaseOnName(countReader, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate);
                            break;
                        case 0:
                            cout << "Quay lai menu chinh.\n";
                            break;
                        default:
                            cout << "Lua chon khong hop le.\n";
                            break;
                    }
                    if (readerChoice == 0)
                        break;
                }
                break;
            }
            case 2:
            {
                while (1)
                {
                    header2();
                    cout << "1. Xem danh sach cac sach trong thu vien.\n";
                    cout << "2. Them sach vao thu vien.\n";
                    cout << "3. Chinh sua thong tin cua mot quyen sach\n";
                    cout << "4. Xoa thong tin sach.\n";
                    cout << "5. Tim kiem sach theo ISBN.\n";
                    cout << "6. Tim kiem sach theo tua de.\n";
                    cout << "0. Quay lai menu chinh.\n";
                    header2();
                    cout << "Nhap vao lua chon voi sach: ";
                    int bookChoice;
                    cin >> bookChoice;
                    switch (bookChoice)
                    {
                        case 1:
                            viewBook(countBook, bookISBN, bookTitles, bookAuthor, bookPublisher, bookGenres, bookPublishedYear, bookPrices, bookQuantities);
                            break;
                        case 2:
                            addBook(countBook, bookISBN, bookTitles, bookAuthor, bookPublisher, bookGenres, bookPublishedYear, bookPrices, bookQuantities, totalBooks, remainBooks);
                            break;
                        case 3:
                            editBook(countBook, bookISBN, bookTitles, bookAuthor, bookPublisher, bookGenres, bookPublishedYear, bookPrices, bookQuantities, totalBooks, remainBooks);
                            break;
                        case 4:
                            removeBook(countBook, bookISBN, bookTitles, bookAuthor, bookPublisher, bookGenres, bookPublishedYear, bookPrices, bookQuantities, totalBooks, remainBooks);
                            break;
                        case 5:
                            FindBookBaseOnISBN(countBook, bookISBN, bookTitles, bookAuthor, bookPublisher, bookGenres, bookPublishedYear, bookPrices, bookQuantities);
                            break;
                        case 6:
                            FindBookBaseOnName(countBook, bookISBN, bookTitles, bookAuthor, bookPublisher, bookGenres, bookPublishedYear, bookPrices, bookQuantities);
                            break;
                        case 0:
                            cout << "Quay lai menu chinh.\n";
                            break;
                        default:
                            cout << "Lua chon khong hop le.\n";
                            break;
                    }
                    if (bookChoice == 0)
                        break;
                }
                break;
            }
            case 3:
            {
                borrowBooks(countReader, readerId, readerName, countLoan, loanReaderIDs, loanBooks, loanBookQuantites, loanDates, returnDates, loanBookCount, countBook, bookISBN, bookTitles, bookQuantities, remainBooks);
                break;
            }
            case 4:
            {
                returnBooks(countLoan, loanReaderIDs, loanBooks, loanBookQuantites, loanDates, returnDates, returnDatesActual, loanBookCount, countBook, bookISBN, bookQuantities, bookPrices, remainBooks);
                break;
            }
            case 5:
            {
                while (1)
                {
                    header2();
                    cout << "1. Thong ke so luong sach trong thu vien.\n";
                    cout << "2. Thong ke so luong sach theo the loai.\n";
                    cout << "3. Thong ke so luong doc gia.\n";
                    cout << "4. Thong ke so luong doc gia theo gioi tinh.\n";
                    cout << "5. Thong ke so sach dang duoc muon.\n";
                    cout << "6. Thong ke danh sach doc gia bi tre han.\n";
                    cout << "0. Quay lai menu chinh.\n";
                    header2();

                    int queryChoice;
                    cout << "Nhap lua chon de thong ke: ";
                    cin >> queryChoice;
                    switch (queryChoice)
                    {
                        case 1:
                        {
                            cout << "So luong sach trong thu vien: " << countTotalBooks(bookQuantities, countBook) << "\n";
                            break;
                        }
                        case 2:
                            countBookByGenres(bookGenres, bookQuantities, countBook);
                            break;
                        case 3:
                            cout << "So luong doc gia hien tai: " << countTotalReaders(countReader) << "\n";
                            break;
                        case 4:
                            countReaderByGenders(readerGender, countReader);
                            break;
                        case 5:
                            cout << "So luong sach dang duoc muon: " << countBorrowedBooks(countLoan, loanBookCount) << "\n";
                            break;
                        case 6:
                            listOverduedReaders(countLoan, loanReaderIDs, returnDates, returnDatesActual);
                            break;
                        case 0:
                            cout << "Quay lai menu chinh.\n";
                            break;
                        default:
                            cout << "Lua chon khong hop le.\n";
                            break;
                    }
                    if (queryChoice == 0)
                    {
                        break;
                    }
                }
                break;
            }
            case 0:
            {
                cout << "Thoat chuong trinh.\n";
                return 0;
            }
        }
    }
    return 0;
}