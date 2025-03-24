#include "MainMenu.h"

void Showtime(int &countReader, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3],
              int &countBook, int &totalBooks, int &remainBooks, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantities[],
              int &countLoan, char loanReaderIDs[][20], char loanBooks[][MAX_BORROWED_BOOKS][20], int loanBookQuantities[MAX_LOANS][MAX_BORROWED_BOOKS], int loanDates[MAX_LOANS][3], int returnDates[][3], int returnDatesActual[][3], int loanBookCount[])
{
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
        cout << "Nhap vao lua chon yeu cau cua ban: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            ReaderMenu(countReader, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate);
            break;
        }
        case 2:
        {
            BookMenu(countBook, totalBooks, remainBooks, bookISBN, bookTitles, bookAuthor, bookPublisher, bookGenres, bookPublishedYear, bookPrices, bookQuantities);
            break;
        }
        case 3:
        {
            borrowBooksMenu(countReader, readerId, readerName, countLoan, loanReaderIDs, loanBooks, loanBookQuantities, loanDates, returnDates, loanBookCount, countBook, bookISBN, bookTitles, bookQuantities, remainBooks);
            break;
        }
        case 4:
        {
            returnBookMenu(countLoan, loanReaderIDs, loanBooks, loanBookQuantities, loanDates, returnDates, returnDatesActual, loanBookCount, countBook, bookISBN, bookQuantities, bookPrices, remainBooks);
            break;
        }
        case 5:
        {
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
        case 0:
            cout << "Quay lai menu chinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le.\n";
            break;
        }
        if (readerChoice == 0)
        {
            break;
        }
    }
}
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
        if (bookChoice == 0)
            break;
    }
}

void borrowBooksMenu(int countReader, char readerId[][20], char readerName[][100], int countLoan, char loanReaderIDs[][20], char loanBooks[MAX_LOANS][MAX_BORROWED_BOOKS][20], int loanBookQuantites[][MAX_BORROWED_BOOKS], int loanDates[][3], int returnDates[][3],
                     int loanBookCount[], int countBook, char bookISBN[][20], char bookTitles[][100], int bookQuantities[], int &remainBooks)
{
    borrowBooks(countReader, readerId, readerName, countLoan, loanReaderIDs, loanBooks, loanBookQuantites, loanDates, returnDates, loanBookCount, countBook, bookISBN, bookTitles, bookQuantities, remainBooks);
}
void returnBookMenu(int countLoan, char loanReaderIDs[][20], char loanBooks[MAX_LOANS][MAX_BORROWED_BOOKS][20], int loanBookQuanties[][MAX_BORROWED_BOOKS],
                    int loanDates[][3], int returnDates[][3], int returnDatesActual[][3], int loanBookCount[],
                    int countBook, char bookISBN[][20], int BookQuantites[], int bookPrices[], int &remainBooks)
{
    returnBooks(countLoan, loanReaderIDs, loanBooks, loanBookQuanties, loanDates, returnDates, returnDatesActual, loanBookCount, countBook, bookISBN, BookQuantites, bookPrices, remainBooks);
}
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
}