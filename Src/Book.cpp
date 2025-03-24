#include "Book.h"

void displayBookInfo(int index, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantites[])
{
    cout << index + 1 << ". " << bookISBN[index] << " - " << bookTitles[index] << " - " << bookAuthor[index] << " - " << bookPublisher[index] << " - " << bookGenres[index]
         << " - " << bookPublishedYear[index] << " - " << bookPrices[index] << " - " << bookQuantites[index] << "\n";
}
// a. Xem danh sach cac sach trong thu vien
void viewBook(int count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuatites[])
{
    system("cls");
    cout << "\nDanh sach cac sach: \n";
    for (int i = 0; i < count; i++)
        displayBookInfo(i, bookISBN, bookTitles, bookAuthor, bookPublisher, bookGenres, bookPublishedYear, bookPrices, bookQuatites);
    system("pause");
    system("cls");
}
// b. Them sach
void addBook(int &count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuatites[], int &totalBooks, int &remainBooks)
{
    system("cls");
    if (count >= MAX_BOOKS)
    {
        cout << "\nKhong the nhap them sach moi, danh sach day day.\n";
        system("pause");
        system("cls");
        return;
    }
    cout << "\nNhap thong tin cua sach moi:\n";
    cout << "ISBN: ";
    cin.ignore();
    cin.getline(bookISBN[count], 20);
    cout << "Tua de: ";
    cin.getline(bookTitles[count], 100);
    cout << "Tac gia: ";
    cin.getline(bookAuthor[count], 100);
    cout << "Nha xuat ban: ";
    cin.getline(bookPublisher[count], 100);
    cout << "The loai: ";
    cin.getline(bookGenres[count], 50);
    cout << "Nam xuat ban: ";
    cin >> bookPublishedYear[count];
    cout << "Gia sach: ";
    cin >> bookPrices[count];
    cout << "So luong: ";
    cin >> bookQuatites[count];
    totalBooks += bookQuatites[count];
    remainBooks = totalBooks;
    count++;
    cout << "Sach moi da duoc them vao kho.\n";
    system("pause");
    system("cls");
}
// c. Chinh sua thong tin cua mot quyen sach
void editBook(int count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantites[], int &totalBooks, int &remainBooks)
{
    system("cls");
    char isbn[100];
    cout << "\nNhap ISBN cua sach can duoc chinh sua: ";
    cin.ignore();
    cin.getline(isbn, 100);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(bookISBN[i], isbn) == 0)
        {
            cout << "Da tim thay sach.\n";
            displayBookInfo(i, bookISBN, bookTitles, bookAuthor, bookPublisher, bookGenres, bookPublishedYear, bookPrices, bookQuantites);
            int choice;
            do
            {
                cout << "Chon thong tin can thay doi:\n";
                cout << "1. ISBN.\n";
                cout << "2. Tua de sach.\n";
                cout << "3. Tac gia.\n";
                cout << "4. Nha xuat ban.\n";
                cout << "5. The loai.\n";
                cout << "6. Nam xuat ban.\n";
                cout << "7. Gia sach.\n";
                cout << "8. So luong.\n";
                cout << "0. Ve lai cua so quan ly sach.\n";
                cin >> choice;
                cin.ignore();
                switch (choice)
                {
                case 1:
                    cout << "ISBN moi: ";
                    cin.getline(bookISBN[i], 20);
                    break;
                case 2:
                    cout << "Tua de sach moi: ";
                    cin.getline(bookTitles[i], 100);
                    break;
                case 3:
                    cout << "Ten tac gia: ";
                    cin.getline(bookAuthor[i], 100);
                    break;
                case 4:
                    cout << "Nha xuat ban: ";
                    cin.getline(bookPublisher[i], 100);
                    break;
                case 5:
                    cout << "The loai: ";
                    cin.getline(bookGenres[i], 100);
                    break;
                case 6:
                    cout << "Nam xuat ban: ";
                    cin >> bookPublishedYear[i];
                    break;
                case 7:
                    cout << "Gia sach: ";
                    cin >> bookPrices[i];
                    break;
                case 8:
                    totalBooks -= bookQuantites[i];
                    remainBooks -= bookQuantites[i];
                    cout << "So luong sach: ";
                    cin >> bookQuantites[i];
                    totalBooks += bookQuantites[i];
                    remainBooks += bookQuantites[i];
                    break;
                case 0:
                    cout << "Thoat chinh sua.\n";
                    system("pause");
                    system("cls");
                    break;
                default:
                    cout << "Lua chon nhap vao khong hop le.\n";
                    break;
                }
                if (choice != 0)
                {
                    system("cls");
                    cout << "Thong tin sau khi chinh sua.\n";
                    displayBookInfo(i, bookISBN, bookTitles, bookAuthor, bookPublisher, bookGenres, bookPublishedYear, bookPrices, bookQuantites);
                    system("pause");
                }
            } while (choice != 0);

            return;
        }
    }
    cout << "Khong tim thay sach can tim.\n";
    system("pause");
    system("cls");
}
// d. Xoa thong tin sach
void removeBook(int &count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuatites[], int &totalBooks, int &remainBooks)
{
    system("cls");
    char isbn[100];
    cout << "\nNhap vao ISBN cua sach can duoc xoa: \n";
    cin.ignore();
    cin.getline(isbn, 100);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(bookISBN[i], isbn) == 0)
        {
            cout << "Da tim thay sach.\n";
            displayBookInfo(i, bookISBN, bookTitles, bookAuthor, bookPublisher, bookGenres, bookPublishedYear, bookPrices, bookQuatites);
            cout << "Ban co muon xoa sach nay khong ? (y/n)";
            char c;
            cin >> c;
            if (c == 'n' || c == 'N')
            {
                cout << "Khong xoa sach, ve lai menu chinh.\n";
                system("pause");
                system("cls");
                return;
            }
            else if (c == 'y' || c == 'Y')
            {
                for (int j = i; j < count - 1; j++)
                {
                    strcpy(bookISBN[j], bookISBN[j + 1]);
                    strcpy(bookTitles[j], bookTitles[j + 1]);
                    strcpy(bookAuthor[j], bookAuthor[j + 1]);
                    strcpy(bookPublisher[j], bookPublisher[j + 1]);
                    strcpy(bookGenres[j], bookGenres[j + 1]);
                    bookPublishedYear[j] = bookPublishedYear[j + 1];
                    bookPrices[j] = bookPrices[j + 1];
                    bookQuatites[j] = bookQuatites[j + 1];
                }
                count--;
                cout << "Sach da duoc xoa thanh cong.\n";
                totalBooks = countTotalBooks(bookQuatites, count);
                remainBooks = totalBooks;
                system("pause");
                system("cls");
                return;
            }
        }
    }
    cout << "Khong tim thay sach can tim.\n";
    system("pause");
    system("cls");
}
// e. Tim kiem sach theo ISBN
void FindBookBaseOnISBN(int count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantites[])
{
    system("cls");
    char isbn[100];
    cout << "\nNhap ISBN sach can tim:\n";
    cin.ignore();
    cin.getline(isbn, 100);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(bookISBN[i], isbn) == 0)
        {
            // cout << "Tim thay: \n";
            // cout << "ISBN sach: " << bookISBN[i] << "\n";
            // cout << "Tua de sach: " << bookTitles[i] << "\n";
            // cout << "Tac gia sach: " << bookAuthor[i] << "\n";
            displayBookInfo(i, bookISBN, bookTitles, bookAuthor, bookPublisher, bookGenres, bookPublishedYear, bookPrices, bookQuantites);
            system("pause");
            system("cls");
            return;
        }
    }
    cout << "Khong tim thay sach can tim.\n";
    system("pause");
    system("cls");
}
// f. Tim kiem theo ten sach
void FindBookBaseOnName(int count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantites[])
{
    system("cls");
    char booktiles[100];
    cout << "\nNhap vao tua de sach can tim kiem:\n";
    cin.ignore();
    cin.getline(booktiles, 100);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(bookTitles[i], booktiles) == 0)
        {
            // cout << "Tim thay tac gia: " << bookAuthor[i] << "\n";
            // cout << "Sach: " << bookTitles[i] << "\n";
            displayBookInfo(i, bookISBN, bookTitles, bookAuthor, bookPublisher, bookGenres, bookPublishedYear, bookPrices, bookQuantites);
            system("pause");
            system("cls");
            return;
        }
    }
    cout << "Khong tim thay ten sach can tim\n";
    system("pause");
    system("cls");
}
int FindBookBasedOnISBN(int count, char bookISBN[][20], char input[])
{
    int index = -1;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(bookISBN[i], input))
        {
            index = i;
            break;
        }
    }
    return index;
}

int FindBookBasesOnName(int count, char bookTitiles[][100], char input[])
{
    int index = -1;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(bookTitiles[i], input))
        {
            index = i;
            break;
        }
    }
    return index;
}