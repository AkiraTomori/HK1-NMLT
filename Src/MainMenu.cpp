#include "MainMenu.h"
#include <iomanip>
/**
 * @brief Hiển thị thông tin về độc giả, sách và phiếu mượn/trả sách và thống kê.
 *
 * @param countReader Số lượng độc giả.
 * @param readerName Mảng chứa tên độc giả.
 * @param readerId Mảng chứa mã độc giả.
 * @param readerCCCD Mảng chứa CCCD của độc giả.
 * @param readerMail Mảng chứa email của độc giả.
 * @param readerAddress Mảng chứa địa chỉ của độc giả.
 * @param readerGender Mảng chứa giới tính của độc giả.
 * @param readerBirthday Mảng chứa ngày sinh của độc giả.
 * @param readerCardDates Mảng chứa ngày lập thẻ của độc giả.
 * @param readerExpiryDate Mảng chứa ngày hết hạn thẻ của độc giả.
 * @param countBook Số lượng sách.
 * @param totalBooks Tổng số sách.
 * @param remainBooks Số sách còn lại.
 * @param bookISBN Mảng chứa ISBN của sách.
 * @param bookTitles Mảng chứa tiêu đề của sách.
 * @param bookAuthor Mảng chứa tác giả của sách.
 * @param bookPublisher Mảng chứa nhà xuất bản của sách.
 * @param bookGenres Mảng chứa thể loại của sách.
 * @param bookPublishedYear Mảng chứa năm xuất bản của sách.
 * @param bookPrices Mảng chứa giá của sách.
 * @param bookQuantities Mảng chứa số lượng của sách.
 * @param countLoan Số lượng phiếu mượn.
 * @param loanReaderIDs Mảng chứa mã độc giả của các phiếu mượn.
 * @param loanBooks Mảng chứa ISBN các sách được mượn.
 * @param loanBookQuantites Mảng chứa số lượng sách mà độc giả mượn trong mỗi cuốn sách.
 * @param loanDates Mảng chứa ngày mượn sách.
 * @param returnDates Mảng chứa ngày trả dự kiến.
 * @param returnDatesActual Mảng chứa ngày trả thực tế.
 * @param loanBookCount Mảng chứa số lượng sách mượn trong mỗi phiếu.
 */

void Showtime(int &countReader, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3],
              int &countBook, int &totalBooks, int &remainBooks, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantities[],
              int &countLoan, char loanReaderIDs[][20], char loanBooks[][MAX_BORROWED_BOOKS][20], int loanBookQuantities[MAX_LOANS][MAX_BORROWED_BOOKS], int loanDates[MAX_LOANS][3], int returnDates[][3], int returnDatesActual[][3], int loanBookCount[])
{
    while (1)
    {
        printf("\t\tQUAN LY THU VIEN.\n");
        header2();
        cout << "1. Quan ly doc gia.\n";
        cout << "2. Quan ly sach.\n";
        cout << "3. Lap phieu muon sach.\n";
        cout << "4. Lap phieu tra sach.\n";
        cout << "5. Thong ke.\n";
        cout << "0. Thoat chuong trinh.\n";
        header2();
        int choice;
        cout << "Nhap vao lua chon yeu cau cua ban: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            ReaderMenu(countReader, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate);
            break;
        }
        case 2:
        {
            system("cls");
            BookMenu(countBook, totalBooks, remainBooks, bookISBN, bookTitles, bookAuthor, bookPublisher, bookGenres, bookPublishedYear, bookPrices, bookQuantities);
            break;
        }
        case 3:
        {
            system("cls");
            borrowBooksMenu(countReader, readerId, readerName, countLoan, loanReaderIDs, loanBooks, loanBookQuantities, loanDates, returnDates, loanBookCount, countBook, bookISBN, bookTitles, bookQuantities, remainBooks);
            break;
        }
        case 4:
        {
            system("cls");
            returnBookMenu(countLoan, loanReaderIDs, loanBooks, loanBookQuantities, loanDates, returnDates, returnDatesActual, loanBookCount, countBook, bookISBN, bookQuantities, bookPrices, remainBooks);
            break;
        }
        case 5:
        {
            system("cls");
            QueryMenu(countReader, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate, countBook, totalBooks, remainBooks, bookISBN, bookTitles, bookAuthor, bookPublisher, bookGenres, bookPublishedYear, bookPrices, bookQuantities, countLoan, loanReaderIDs, loanBooks, loanBookQuantities, loanDates, returnDates, returnDatesActual, loanBookCount);
            break;
        }
        case 0:
        {
            cout << "Thoat chuong trinh";
            return;
        }
        default:
        {
            cout << "Lua chon khong hop le.\n";
            break;
        }
        }
    }
}

/**
 * @brief Hiển thị thông tin về độc giả
 *
 * @param countReader Số lượng độc giả.
 * @param readerName Mảng chứa tên độc giả.
 * @param readerId Mảng chứa mã độc giả.
 * @param readerCCCD Mảng chứa CCCD của độc giả.
 * @param readerMail Mảng chứa email của độc giả.
 * @param readerAddress Mảng chứa địa chỉ của độc giả.
 * @param readerGender Mảng chứa giới tính của độc giả.
 * @param readerBirthday Mảng chứa ngày sinh của độc giả.
 * @param readerCardDates Mảng chứa ngày lập thẻ của độc giả.
 * @param readerExpiryDate Mảng chứa ngày hết hạn thẻ của độc giả.
 */

void ReaderMenu(int &countReader, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3])
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
        {
            system("cls");
            break;
        }
    }
}

/**
 * @brief Hiển thị thông tin về sách
 *
 * @param countBook Số lượng sách.
 * @param totalBooks Tổng số sách.
 * @param remainBooks Số sách còn lại.
 * @param bookISBN Mảng chứa ISBN của sách.
 * @param bookTitles Mảng chứa tiêu đề của sách.
 * @param bookAuthor Mảng chứa tác giả của sách.
 * @param bookPublisher Mảng chứa nhà xuất bản của sách.
 * @param bookGenres Mảng chứa thể loại của sách.
 * @param bookPublishedYear Mảng chứa năm xuất bản của sách.
 * @param bookPrices Mảng chứa giá của sách.
 * @param bookQuantities Mảng chứa số lượng của sách.
 */

void BookMenu(int &countBook, int &totalBooks, int &remainBooks, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantities[])
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
        if (bookChoice == 0){
            system("cls");
            break;
        }
    }
}

/**
 * @brief Thông tin về phiếu mượn
 * 
 * @param countReader Số lượng độc giả
 * @param readerId Mảng chứa id độc giả
 * @param readerName Mảng chứa tên độc giả
 * @param countLoan Số lượng phiếu mượn.
 * @param loanReaderIDs Mảng chứa mã độc giả của các phiếu mượn.
 * @param loanBooks Mảng chứa ISBN các sách được mượn.
 * @param loanBookQuantites Mảng chứa số lượng sách mà độc giả mượn trong mỗi cuốn sách.
 * @param loanDates Mảng chứa ngày mượn sách.
 * @param returnDates Mảng chứa ngày trả dự kiến.
 * @param loanBookCount Mảng chứa số lượng sách mượn trong mỗi phiếu.
 * @param countBook Số lượng sách
 * @param bookISBN Mảng chứa ISBN của sách
 * @param bookTitles Mảng chứa tiêu đề của sách
 * @param bookQuantites Mảng chứa số lượng của sách
 * @param remainBooks Số sách còn lại.
 */

void borrowBooksMenu(int countReader, char readerId[][20], char readerName[][100], int &countLoan, char loanReaderIDs[][20], char loanBooks[MAX_LOANS][MAX_BORROWED_BOOKS][20], int loanBookQuantites[][MAX_BORROWED_BOOKS], int loanDates[][3], int returnDates[][3],
                     int loanBookCount[], int countBook, char bookISBN[][20], char bookTitles[][100], int bookQuantities[], int &remainBooks)
{
    borrowBooks(countReader, readerId, readerName, countLoan, loanReaderIDs, loanBooks, loanBookQuantites, loanDates, returnDates, loanBookCount, countBook, bookISBN, bookTitles, bookQuantities, remainBooks);
}


/**
 * @brief Quản lý trả phiếu mượn của thư viện
 * 
 * @param countLoan Số lượng phiếu mượn.
 * @param loanReaderIDs Mảng chứa mã độc giả của các phiếu mượn.
 * @param loanBooks Mảng chứa ISBN các sách được mượn.
 * @param loanBookQuantites Mảng chứa số lượng sách mà độc giả mượn trong mỗi cuốn sách.
 * @param loanDates Mảng chứa ngày mượn sách.
 * @param returnDates Mảng chứa ngày trả dự kiến.
 * @param returnDatesActual Mảng chứa ngày trả thực tế.
 * @param loanBookCount Mảng chứa số lượng sách mượn trong mỗi phiếu.
 * @param countBook Số lượng sách
 * @param bookISBN Mảng chứa các ISBN 
 * @param BookQuantites Mảng chứa số lượng của sách
 * @param bookPrices Mảng chứa giá của các sách
 * @param remainBooks Giá trị của số sách còn lại
 */

void returnBookMenu(int countLoan, char loanReaderIDs[][20], char loanBooks[MAX_LOANS][MAX_BORROWED_BOOKS][20], int loanBookQuanties[][MAX_BORROWED_BOOKS],
                    int loanDates[][3], int returnDates[][3], int returnDatesActual[][3], int loanBookCount[],
                    int countBook, char bookISBN[][20], int BookQuantites[], int bookPrices[], int &remainBooks)
{
    returnBooks(countLoan, loanReaderIDs, loanBooks, loanBookQuanties, loanDates, returnDates, returnDatesActual, loanBookCount, countBook, bookISBN, BookQuantites, bookPrices, remainBooks);
}

/**
 * @brief Sử dụng những thông tin của tất cả để thống kê
 *
 * @param countReader Số lượng độc giả.
 * @param readerName Mảng chứa tên độc giả.
 * @param readerId Mảng chứa mã độc giả.
 * @param readerCCCD Mảng chứa CCCD của độc giả.
 * @param readerMail Mảng chứa email của độc giả.
 * @param readerAddress Mảng chứa địa chỉ của độc giả.
 * @param readerGender Mảng chứa giới tính của độc giả.
 * @param readerBirthday Mảng chứa ngày sinh của độc giả.
 * @param readerCardDates Mảng chứa ngày lập thẻ của độc giả.
 * @param readerExpiryDate Mảng chứa ngày hết hạn thẻ của độc giả.
 * @param countBook Số lượng sách.
 * @param totalBooks Tổng số sách.
 * @param remainBooks Số sách còn lại.
 * @param bookISBN Mảng chứa ISBN của sách.
 * @param bookTitles Mảng chứa tiêu đề của sách.
 * @param bookAuthor Mảng chứa tác giả của sách.
 * @param bookPublisher Mảng chứa nhà xuất bản của sách.
 * @param bookGenres Mảng chứa thể loại của sách.
 * @param bookPublishedYear Mảng chứa năm xuất bản của sách.
 * @param bookPrices Mảng chứa giá của sách.
 * @param bookQuantities Mảng chứa số lượng của sách.
 * @param countLoan Số lượng phiếu mượn.
 * @param loanReaderIDs Mảng chứa mã độc giả của các phiếu mượn.
 * @param loanBooks Mảng chứa ISBN các sách được mượn.
 * @param loanBookQuantites Mảng chứa số lượng sách mà độc giả mượn trong mỗi cuốn sách.
 * @param loanDates Mảng chứa ngày mượn sách.
 * @param returnDates Mảng chứa ngày trả dự kiến.
 * @param returnDatesActual Mảng chứa ngày trả thực tế.
 * @param loanBookCount Mảng chứa số lượng sách mượn trong mỗi phiếu.
 */


void QueryMenu(int &countReader, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3],
               int &countBook, int &totalBooks, int &remainBooks, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantities[],
               int &countLoan, char loanReaderIDs[][20], char loanBooks[][MAX_BORROWED_BOOKS][20], int loanBookQuantities[MAX_LOANS][MAX_BORROWED_BOOKS], int loanDates[MAX_LOANS][3], int returnDates[][3], int returnDatesActual[][3], int loanBookCount[])
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
            system("cls");
            cout << "So luong sach trong thu vien: " << countTotalBooks(bookQuantities, countBook) << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 2:
            system("cls");
            countBookByGenres(bookGenres, bookQuantities, countBook);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            cout << "So luong doc gia hien tai: " << countTotalReaders(countReader) << "\n";
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            countReaderByGenders(readerGender, countReader);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            cout << "So luong sach dang duoc muon: " << countBorrowedBooks(countLoan, loanBookQuantities,loanBookCount) << "\n";
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            listOverduedReaders(countLoan, loanReaderIDs, returnDates, returnDatesActual);
            system("pause");
            system("cls");
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
            system("cls");
            break;
        }
    }
}