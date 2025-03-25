#include "BookLoan.h"

void borrowBooks(int countReader, char readerId[][20], char readerName[][100], int &countLoan, char loanReaderIDs[][20], char loanBooks[MAX_LOANS][MAX_BORROWED_BOOKS][20], int loanBookQuantites[][MAX_BORROWED_BOOKS], int loanDates[][3], int returnDates[][3],
                 int loanBookCount[], int countBook, char bookISBN[][20], char bookTitles[][100], int bookQuantities[], int &remainBooks)
{
    cout << "Nhap vao ma doc gia: ";
    cin.ignore();
    char id[20];
    cin.getline(id, 100);
    int idIndex = FindReaderBaseOnId(countReader, readerId, id);
    while (idIndex == -1)
    {
        cout << "Doc gia chua duoc them vao thu vien !\n";
        cout << "Hay nhap lai id de tim lai.\n";
        cout << "1. Nhap lai.\n";
        cout << "2. Khong nhap.\n";
        int choiceType = 0;
        cin >> choiceType;
        if (choiceType == 1)
        {
            cout << "Nhap ma doc gia.\n";
            cin.ignore();
            cin.getline(id, 100);
            idIndex = FindReaderBaseOnId(countReader, readerId, id);
        }
        else
        {
            return;
        }
    }
    if (idIndex != -1)
    {
        cout << "Da tim thay ten doc gia: " << readerName[idIndex] << "\n";
        strcpy(loanReaderIDs[countLoan], readerId[idIndex]);
    }
    if (loanDates[idIndex][0] != 0 && loanDates[idIndex][1] != 0 && loanDates[idIndex][2] != 0)
    {
        cout << "Doc gia nay dang muon sach ! Hay tra sach de co the muon sach moi.\n";
        system("pause");
        system("cls");
        return;
    }
    unsigned int BorrowedBooks = 0;
    cout << "So sach ma doc gia muon muon la: ";
    cin >> BorrowedBooks;

    if (BorrowedBooks > MAX_BORROWED_BOOKS)
    {
        cout << "Doc gia chi co the muon toi da 10 cuon sach\n";
        system("pause");
        system("cls");
        return;
    }
    loanBookCount[countLoan] = BorrowedBooks;
    for (unsigned int j = 0; j < BorrowedBooks; j++)
    {
        int i = -1;
        cout << "Sach ma doc gia muon muon (nhap ISBN hoac tua de): ";
        char isbnOrName[100];
        cin.ignore();
        cin.getline(isbnOrName, 100);

        while (i == -1)
        {
            i = FindBookBasedOnISBN(countBook, bookISBN, isbnOrName);
            if (i == -1)
            {
                i = FindBookBasesOnName(countBook, bookTitles, isbnOrName);
                if (i == -1)
                {
                    cout << "Sach khong ton tai.\n";
                    cout << "Hay nhap lai ISBN hoac ten.\n";
                    cin.getline(isbnOrName, 100);
                }
            }
        }
        cout << "Da tim thay sach: " << bookTitles[i] << "\n";
        cout << "So luong sach muon muon: ";
        int quantity;
        cin >> quantity;
        if (quantity > bookQuantities[i])
        {
            cout << "So luong sach trong kho khong du.\n";
            return;
        }
        strcpy(loanBooks[countLoan][j], bookISBN[i]);
        loanBookQuantites[countLoan][j] = quantity;
        bookQuantities[i] -= quantity;
        remainBooks -= quantity;

        cout << "\n";
    }

    cout << "Ngay tao the (theo dd/mm/yy): \n";
    cout << "Ngay: ";
    cin >> loanDates[countLoan][0];
    cout << "Thang: ";
    cin >> loanDates[countLoan][1];
    cout << "Nam: ";
    cin >> loanDates[countLoan][2];

    int day = loanDates[countLoan][0] + 7;
    int month = loanDates[countLoan][1];
    int year = loanDates[countLoan][2];
    int maxDays = getDaysInMonth(month, year);
    if (day > maxDays)
    {
        day -= maxDays;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
    returnDates[idIndex][0] = day;
    returnDates[idIndex][1] = month;
    returnDates[idIndex][2] = year;

    cout << "Muon sach thanh cong.\n";
    countLoan++;
    system("pause");
    system("cls");
}
void returnBooks(int countLoan, char loanReaderIDs[][20], char loanBooks[MAX_LOANS][MAX_BORROWED_BOOKS][20], int loanBookQuanties[][MAX_BORROWED_BOOKS],
                 int loanDates[][3], int returnDates[][3], int returnDatesActual[][3], int loanBookCount[],
                 int countBook, char bookISBN[][20], int BookQuantites[], int bookPrices[], int &remainBooks)
{
    cout << "Nhap id cua doc gia: ";
    cin.ignore();
    char id[100];
    cin.getline(id, 100);
    int LoanIndex = FindReaderBaseOnId(countLoan, loanReaderIDs, id);
    if (LoanIndex == -1)
    {
        cout << "Khong tim thay doc gia nay trong danh sach phieu muon sach.\n";
        system("pause");
        system("cls");
        return;
    }
    cout << "Da tim thay ma cua doc gia: " << loanReaderIDs[LoanIndex] << "\n";
    cout << "Nhap ngay tra thuc te (theo dd/mm/yyyy): \n";
    cout << "Ngay: ";
    cin >> returnDatesActual[LoanIndex][0];
    cout << "Thang: ";
    cin >> returnDatesActual[LoanIndex][1];
    cout << "Nam: ";
    cin >> returnDatesActual[LoanIndex][2];

    int overdueDays = (returnDatesActual[LoanIndex][0] - returnDates[LoanIndex][0]) +
                      (returnDatesActual[LoanIndex][1] - returnDates[LoanIndex][1]) * 30 +
                      (returnDatesActual[LoanIndex][2] - returnDates[LoanIndex][2]) * 365;
    int totalFine = 0;
    int fine = 0;
    if (overdueDays > 0)
    {
        fine = overdueDays * 5000;
        totalFine += fine;
        cout << "Doc gia bi phat " << fine << " dong vi tra sach qua han " << overdueDays << " ngay.\n";
    }

    for (int j = 0; j < loanBookCount[LoanIndex]; j++)
    {
        cout << "Sach " << loanBooks[LoanIndex][j] << " co bi mat khong ? (1: co, 0: khong): ";
        int lost;
        cin >> lost;
        if (lost == 1)
        {
            int bookIndex = FindBookBasedOnISBN(countBook, bookISBN, loanBooks[LoanIndex][j]);
            cout << "So luong sach bi mat la: ";
            int lostBook;
            cin >> lostBook;
            int fine = bookPrices[bookIndex] * 2 * lostBook;
            totalFine += fine;
            cout << "Doc gia bi phat: " << fine << " dong vi mat sach.\n";
            loanBookQuanties[LoanIndex][j] -= lostBook;
            remainBooks += loanBookQuanties[LoanIndex][j];
            BookQuantites[bookIndex] += loanBookQuanties[LoanIndex][j];
        }
        else
        {
            int bookIndex = FindBookBasedOnISBN(countBook, bookISBN, loanBooks[LoanIndex][j]);
            remainBooks += loanBookQuanties[LoanIndex][j];
            BookQuantites[bookIndex] += loanBookQuanties[LoanIndex][j];
        }
    }
    cout << "Tong tien phat: " << totalFine << " dong.\n";
    loanDates[LoanIndex][0] = 0;
    loanDates[LoanIndex][1] = 0;
    loanDates[LoanIndex][2] = 0;

    for (int j = 0; j < loanBookCount[LoanIndex]; j++)
    {
        loanBookQuanties[LoanIndex][j] = 0;
        // strcpy(loanBooks[LoanIndex][j], "");
    }
    // loanBookCount[LoanIndex] = 0;

    // returnDates[LoanIndex][0] = 0;
    // returnDates[LoanIndex][1] = 0;
    // returnDates[LoanIndex][2] = 0;

    // returnDatesActual[LoanIndex][0] = 0;
    // returnDatesActual[LoanIndex][1] = 0;
    // returnDatesActual[LoanIndex][2] = 0;

    cout << "Tra sach thanh cong.\n";
    system("pause");
    system("cls");
}