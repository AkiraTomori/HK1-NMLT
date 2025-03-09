#include "Reader.h"

void displayReaderInfo(int index, char readerName[][100], char readerId[][100], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3])
{
    // cout << "Thong tin cua doc gia.\n";
    cout << index + 1 << " - " << readerName[index] << " - " << readerId[index] << " - " << readerCCCD[index] << " - " << readerMail[index] << " - " << readerAddress[index] << " - " << readerGender[index]
         << " - " << readerBirthday[index][0] << "/" << readerBirthday[index][1] << "/" << readerBirthday[index][2] << " - "
         << readerCardDates[index][0] << "/" << readerCardDates[index][1] << "/" << readerCardDates[index][2] << " - "
         << readerExpiryDate[index][0] << "/" << readerExpiryDate[index][1] << "/" << readerExpiryDate[index][2] << "\n"; 
}
// Xem danh sach va thong tin cua doc gia
void viewReader(char readerName[][100], char readerId[][100], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3], int count)
{
    cout << "\nDanh sach doc gia:\n";
    for (int i = 0; i < count; i++)
        displayReaderInfo(i, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate);
}
// b. Thêm độc giả
void addReader(int &count, char readerName[][100], char readerId[][100], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3])
{
    if (count >= MAX_READER)
    {
        cout << "\nKhong the them doc gia moi, danh sach da day.\n";
        return;
    }
    cout << "\nNhap thong tin cua doc gia moi:\n";
    cout << "Ten: "; cin.ignore(); cin.getline(readerName[count], 100);
    cout << "Ma doc gia: "; cin.getline(readerId[count], 100);
    cout << "CCCD: "; cin.getline(readerCCCD[count], 100);
    cout << "Email: "; cin.getline(readerMail[count], 100);
    cout << "Dia chi: "; cin.getline(readerAddress[count], 100);
    cout << "Gioi tinh: "; cin.getline(readerGender[count], 100);
    
    cout << "Ngay sinh (ngay/thang/nam): \n";
    cout << "Ngay: "; cin >> readerBirthday[count][0];
    cout << "Thang: "; cin >> readerBirthday[count][1];
    cout << "Nam: "; cin >> readerBirthday[count][2];
    
    cout << "Ngay lap the (ngay/thang/nam): \n";
    cout << "Ngay: "; cin >> readerCardDates[count][0];
    cout << "Thang: "; cin >> readerCardDates[count][1];
    cout << "Nam: "; cin >> readerCardDates[count][2];
    
    // cout << "Ngay het han: (ngay/thang/nam): ";
    
    int day = readerCardDates[count][0];
    int month = readerCardDates[count][1] + 48;
    int year = readerCardDates[count][2];

    while (month > 12)
    {
        month -= 12;
        year++;
    }

    int maxDays = getDaysInMonth(month, year);
    if (day > maxDays)
        day = maxDays;
    
    readerExpiryDate[count][0] = day;
    readerExpiryDate[count][1] = month;
    readerExpiryDate[count][2] = year;
    count++;
    cout << "Doc gia moi da duoc them thanh cong.\n";
}
// c. Chỉnh sửa thông tin của một độc giả
void editReader(int count, char readerName[][100], char readerId[][100], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3])
{
    char id[100];
    cout << "\nNhap id cua doc gia can chinh sua: ";
    cin.ignore();
    cin.getline(id, 100);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(readerCCCD[i], id) == 0)
        {
            cout << "Da tim thay doc gia.\n";
            displayReaderInfo(i, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate);
            int choice;
            do{
                cout << "Chon thong tin can thay doi:\n";
                cout << "1. Ho ten.\n";
                cout << "2. Ma doc gia.\n";
                cout << "3. CCCD.\n";
                cout << "4. Email.\n";
                cout << "5. Dia chi.\n";
                cout << "6. Gioi tinh.\n";
                cout << "7. Ngay sinh.\n";
                // cout << "8. Ngay lap the.\n";
                cout << "0. Ve lai cua so quan ly doc gia.\n";
                cin >> choice;
                cin.ignore();

                switch (choice)
                {
                    case 1:
                        cout << "Nhap ten moi: ";
                        cin.getline(readerName[i], 100);
                        break;
                    case 2:
                        cout << "Nhap ma doc gia moi: ";
                        cin.getline(readerId[i], 100);
                        break;
                    case 3:
                        cout << "Nhap cccd moi: ";
                        cin.getline(readerCCCD[i], 100);
                        break;
                    case 4:
                        cout << "Email moi: ";
                        cin.getline(readerMail[i], 100);
                        break;
                    case 5:
                        cout << "Dia chi moi: ";
                        cin.getline(readerAddress[i], 100);
                        break;
                    case 6:
                        cout << "Gioi tinh: ";
                        cin.getline(readerGender[i], 100);
                        break;
                    case 7:
                        cout << "Ngay thang nam sinh moi: ";
                        cout << "Ngay: "; cin >> readerBirthday[i][0];
                        cout << "Thang: "; cin >> readerBirthday[i][1];
                        cout << "Nam: "; cin >> readerBirthday[i][2];
                        break;
                    case 0:
                        cout << "Thoat chinh sua\n";
                        break;
                    default:
                        cout << "Lua chon khong hop le.\n";
                        break;
                }
                if (choice != 0)
                {
                    cout << "Thong tin sau khi chinh sua.\n";
                    displayReaderInfo(i, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate);
                }
            } while (choice != 0);

            return;
        }
    }
    cout << "Khong tim thay doc gia can tim de thay doi.\n";
}
// d. Xóa thông tin của một độc giả
void removeReader(int &count, char readerName[][100], char readerId[][100], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3])
{
    char id[100];
    cout << "\nNhap id cua doc gia can xoa: ";
    cin.ignore();
    cin.getline(id, 100);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(readerCCCD[i], id) == 0)
        {
            cout << "Da tim thay doc gia can tim.\n";
            displayReaderInfo(i, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate);
            cout << "Ban co muon xoa doc gia nay khong ? (y/n)\n";
            char c;
            cin >> c;
            if (c == 'n' || c == 'N')
            {
                return;
            }
            else if (c == 'y' || c == 'Y')
            {
                for (int j = i; j < count - 1; j++)
                {
                    strcpy(readerName[j], readerName[j + 1]);
                    strcpy(readerId[j], readerId[j + 1]);
                    strcpy(readerCCCD[j], readerCCCD[j + 1]);
                    strcpy(readerMail[j], readerMail[j + 1]);
                    strcpy(readerAddress[j], readerAddress[j + 1]);
                    strcpy(readerGender[j], readerGender[j + 1]);
                    memcpy(readerBirthday[j], readerBirthday[j + 1], 3 * sizeof(int));
                    memcpy(readerCardDates[j], readerCardDates[j + 1], 2 * sizeof(int));
                    memcpy(readerExpiryDate[j], readerExpiryDate[j + 1], 2 * sizeof(int));
                }
                count--;
                cout << "Xoa doc gia thanh cong!\n";
                return;
            }
            
        }
    }
    cout << "Khong tim thay ten doc gia.\n";
}
// e. Tìm kiếm độc giả theo CCCD
void FindReaderBaseOnCCCD(int count, char readerName[][100], char readerId[][100], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3])
{
    char cccd[100];
    cout << "\nNhap CCCD cua doc gia can tim: ";
    cin.ignore();
    cin.getline(cccd, 100);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(readerCCCD[i], cccd) == 0)
        {
            displayReaderInfo(i, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate);
            return;
        }
    }
    cout << "Khong tim thay doc gia.\n";
}
// f. Tìm kiếm độc giả theo họ tên
void FindReaderBaseOnName(int count, char readerName[][100], char readerId[][100], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3])
{
    char name[100];
    cout << "\nNhap ten doc gia can tim kiem: ";
    cin.ignore();
    cin.getline(name, 100);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(readerName[i], name) == 0)
        {
            displayReaderInfo(i, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate);
            return;
        }
    }
    cout << "Khong tim thay doc gia.\n";
}