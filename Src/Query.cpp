#include "Query.h"

int countTotalBooks(int bookQuantites[], int countBook)
{
    int totalBooks = 0;
    for (int i = 0; i < countBook; i++)
    {
        totalBooks += bookQuantites[i];
    }
    return totalBooks;
}
// B. Thong ke sach theo the loai
void countBookByGenres(char bookGenres[][50], int BookQuantites[], int countBook)
{
    int genreCount[MAX_BOOKS] = {0};
    int uniqueGenres = 0;
    char checkedGenres[MAX_BOOKS][50];

    for (int i = 0; i < countBook; i++)
    {
        bool found = false; // Cờ đánh dấu là chưa tìm được thể loại đó trong dữ liệu
        for (int j = 0; j < uniqueGenres; j++)
        {
            if (strcmp(bookGenres[i], checkedGenres[j]) == 0)
            {
                // Kiểm tra từng sách có tương ứng thể loại ko.
                // Nếu tương ứng thì tăng số lượng sách của thể loại đó lên
                genreCount[j] += BookQuantites[i];
                // Đặt cờ found về true và break vòng lặp con
                found = true;
                break;
            }
        }
        if (!found)
        {
            // Nếu chưa có thể loại này, thêm vào mảng checkGenres (đại diện cho thể loại riêng biệt)
            // Đồng thời tăng số lượng sách của thể loại đó
            strcpy(checkedGenres[uniqueGenres], bookGenres[i]);
            genreCount[uniqueGenres] = BookQuantites[i];
            uniqueGenres++; // Số lượng thể loại tăng lên
        }
    }
    cout << "Thong ke so luong sach the loai.\n";
    for (int i = 0; i < uniqueGenres; i++)
    {
        cout << "The loai " << checkedGenres[i] << ": " << genreCount[i] << "\n";
    }
}
// C. Thong ke co bao nhieu doc gia
int countTotalReaders(int countReader)
{
    return countReader;
}
// D. Thong ke co bao nhieu doc gia theo gioi tinh
void countReaderByGenders(char readerGender[][100], int countReader)
{
    int male = 0, female = 0;
    for (int i = 0; i < countReader; i++)
    {
        if (strcmp(readerGender[i], "Nam") == 0)
            male++;
        if (strcmp(readerGender[i], "Nu") == 0)
            female++;
    }
    cout << "So luong doc gia theo gioi tinh.\n";
    cout << "Nam: " << male << "\n";
    cout << "Nu: " << female << "\n";
}

// E. Thong ke so sach dang muon
int countBorrowedBooks(int countLoan, int loanBookQuantites[][MAX_BORROWED_BOOKS], int loanBookCount[])
{
    int totalBorrowedBooks = 0;
    for (int i = 0; i < countLoan; i++)
    {
        for (int j = 0; j < loanBookCount[i]; j++)
        {
            totalBorrowedBooks += loanBookQuantites[i][j];
        }
    }
    return totalBorrowedBooks;
}
// F. Thong ke danh sach doc gia bi tre hen
void listOverduedReaders(int countLoan, char loanReaderIDs[][20], int returnDates[][3], int returnDatesActual[][3])
{
    cout << "Danh sach doc gia bi tre hen: \n";
    for (int i = 0; i < countLoan; i++)
    {
        int overdueDays = (returnDatesActual[i][0] - returnDates[i][0]) +
                          (returnDatesActual[i][1] - returnDates[i][1]) * 30 +
                          (returnDatesActual[i][2] - returnDates[i][2]) * 365;
        if (overdueDays > 0)
        {
            cout << loanReaderIDs[i] << " bi tre hen " << overdueDays << " ngay.\n";
        }
    }
}