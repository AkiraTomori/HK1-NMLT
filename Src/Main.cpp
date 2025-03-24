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
    
    // Thêm dữ liệu sẵn để test
    strcpy(readerName[0], "Thai Minh Huy");
    strcpy(readerId[0], "23127379");
    strcpy(readerCCCD[0], "079");
    strcpy(readerMail[0], "TMH@gmail.com");
    strcpy(readerAddress[0], "334 TP");
    strcpy(readerGender[0], "Nam");
    readerBirthday[0][0] = 14; readerBirthday[0][1] = 7; readerBirthday[0][2] = 2005;
    readerCardDates[0][0] = 14; readerCardDates[0][1] = 7; readerCardDates[0][2] = 2021;
    readerExpiryDate[0][0] = 14; readerExpiryDate[0][1] = 7; readerExpiryDate[0][2] = 2025;
    countReader = countReader + 1;

    strcpy(readerName[1], "Ta Duy Anh");
    strcpy(readerId[1], "23127380");
    strcpy(readerCCCD[1], "078");
    strcpy(readerMail[1], "TDA@gmail.com");
    strcpy(readerAddress[1], "334 HG");
    strcpy(readerGender[1], "Nam");
    readerBirthday[1][0] = 15; readerBirthday[1][1] = 7; readerBirthday[1][2] = 2005;
    readerCardDates[1][0] = 15; readerCardDates[1][1] = 7; readerCardDates[1][2] = 2021;
    readerExpiryDate[1][0] = 15; readerExpiryDate[1][1] = 7; readerExpiryDate[1][2] = 2025;
    countReader++;

    strcpy(readerName[2], "Nguyen Phuc Huy");
    strcpy(readerId[2], "23127381");
    strcpy(readerCCCD[2], "077");
    strcpy(readerMail[2], "NPH@gmail.com");
    strcpy(readerAddress[2], "334 HN");
    strcpy(readerGender[2], "Nam");
    readerBirthday[2][0] = 16; readerBirthday[2][1] = 7; readerBirthday[2][2] = 2005;
    readerCardDates[2][0] = 16; readerCardDates[2][1] = 7; readerCardDates[2][2] = 2021;
    readerExpiryDate[2][0] = 16; readerExpiryDate[2][1] = 7; readerExpiryDate[2][2] = 2025;
    countReader++;

    strcpy(readerName[3], "Do Hoai Nam");
    strcpy(readerId[3], "23127382");
    strcpy(readerCCCD[3], "076");
    strcpy(readerMail[3], "DHN@gmail.com");
    strcpy(readerAddress[3], "334 KG");
    strcpy(readerGender[3], "Nam");
    readerBirthday[3][0] = 17; readerBirthday[3][1] = 7; readerBirthday[3][2] = 2005;
    readerCardDates[3][0] = 17; readerCardDates[3][1] = 7; readerCardDates[3][2] = 2021;
    readerExpiryDate[3][0] = 17; readerExpiryDate[3][1] = 7; readerExpiryDate[3][2] = 2025;
    countReader++;

    strcpy(readerName[4], "Thai Quoc Vinh");
    strcpy(readerId[4], "23127383");
    strcpy(readerCCCD[4], "075");
    strcpy(readerMail[4], "TQV@gmail.com");
    strcpy(readerAddress[4], "334 V");
    strcpy(readerGender[4], "Nam");
    readerBirthday[4][0] = 18; readerBirthday[4][1] = 7; readerBirthday[4][2] = 2005;
    readerCardDates[4][0] = 18; readerCardDates[4][1] = 7; readerCardDates[4][2] = 2021;
    readerExpiryDate[4][0] = 18; readerExpiryDate[4][1] = 7; readerExpiryDate[4][2] = 2025;
    countReader++;

    // Bộ dữ liệu cho sách
    strcpy(bookISBN[0], "9786043355765");
    strcpy(bookTitles[0], "Suy nghi thong ke trong doi thuong");
    strcpy(bookAuthor[0], "Nguyen Van Tuan");
    strcpy(bookPublisher[0], "NXB Tong hop");
    strcpy(bookGenres[0], "Khoa hoc");
    bookPublishedYear[0] = 2022;
    bookPrices[0] = 150000;
    bookQuantities[0] = 150;
    totalBooks += bookQuantities[0];
    remainBooks += bookQuantities[0];
    countBook++;

    strcpy(bookISBN[1], "9786041185968");
    strcpy(bookTitles[1], "Vu tru trong vo hat de");
    strcpy(bookAuthor[1], "Stephen Hawking");
    strcpy(bookPublisher[1], "NXB Tre");
    strcpy(bookGenres[1], "Khoa hoc");
    bookPublishedYear[1] = 2021;
    bookPrices[1] = 98000;
    bookQuantities[1] = 100;
    totalBooks += bookQuantities[1];
    remainBooks += bookQuantities[1];
    countBook++;

    strcpy(bookISBN[2], "9786046718611");
    strcpy(bookTitles[2], "Nhap mon lap trinh");
    strcpy(bookAuthor[2], "Dinh Ba Tien");
    strcpy(bookPublisher[2], "NXB KH va KT");
    strcpy(bookGenres[2], "Khoa hoc");
    bookPublishedYear[2] = 2021;
    bookPrices[2] = 84000;
    bookQuantities[2] = 150;
    totalBooks += bookQuantities[2];
    remainBooks += bookQuantities[2];
    countBook++;

    strcpy(bookISBN[3], "9786049638176");
    strcpy(bookTitles[3], "Sherlock Homles");
    strcpy(bookAuthor[3], "Conan Doyle");
    strcpy(bookPublisher[3], "NXB Van hoc");
    strcpy(bookGenres[3], "Trinh tham");
    bookPublishedYear[3] = 2019;
    bookPrices[3] = 50000;
    bookQuantities[3] = 50;
    totalBooks += bookQuantities[3];
    remainBooks += bookQuantities[3];
    countBook++;
    
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