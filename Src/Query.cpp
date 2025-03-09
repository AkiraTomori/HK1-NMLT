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
        bool found = false;
        for (int j = 0; j < uniqueGenres; j++)
        {
            if (strcmp(bookGenres[i], checkedGenres[j]) == 0)
            {
                genreCount[j] += BookQuantites[i];
                found = true;
                break;
            }
        }
        if (!found)
        {
            strcpy(checkedGenres[uniqueGenres], bookGenres[i]);
            genreCount[uniqueGenres] = BookQuantites[i];
            uniqueGenres++;
        }
    }
    cout << "Thong ke so luong sach the loai.\n";
    for (int i = 0; i < uniqueGenres; i++)
    {
        cout << "The loai " << checkedGenres[i] << ": " << genreCount[i]; 
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
        if (strcmp(readerGender[i], "Nam") == 0) male++;
        if (strcmp(readerGender[i], "Nu") == 0) female++;
    }
    cout << "So luong doc gia theo gioi tinh.\n";
    cout << "Nam: " << male << "\n";
    cout << "Nu: " << female << "\n";
}