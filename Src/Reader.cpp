#include "Reader.h"
// Xem thông tin của từng độc giả
void displayReaderInfo(int index, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3])
{
    // cout << "Thong tin cua doc gia.\n";
    cout << index + 1 << " - " << readerName[index] << " - " << readerId[index] << " - " << readerCCCD[index] << " - " << readerMail[index] << " - " << readerAddress[index] << " - " << readerGender[index]
         << " - " << readerBirthday[index][0] << "/" << readerBirthday[index][1] << "/" << readerBirthday[index][2] << " - "
         << readerCardDates[index][0] << "/" << readerCardDates[index][1] << "/" << readerCardDates[index][2] << " - "
         << readerExpiryDate[index][0] << "/" << readerExpiryDate[index][1] << "/" << readerExpiryDate[index][2] << "\n";
}
// Xem danh sach va thong tin cua doc gia
void viewReader(char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3], int count)
{
    system("cls");
    cout << "\nDanh sach doc gia:\n";
    for (int i = 0; i < count; i++)
        displayReaderInfo(i, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate);
    system("pause");
    system("cls");
}
// b. Thêm độc giả
void addReader(int &count, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3])
{
    system("cls");
    if (count >= MAX_READER)
    {
        // Nếu như quá số lượng thì không thể thêm mới
        cout << "\nKhong the them doc gia moi, danh sach da day.\n";
        system("pause");
        system("cls");
        return;
    }
    // Nhập từng thông tin thuộc tính cho độc giả
    cout << "\nNhap thong tin cua doc gia moi:\n";
    cout << "Ten: ";
    cin.ignore();
    cin.getline(readerName[count], 100);
    cout << "Ma doc gia: ";
    cin.getline(readerId[count], 100);
    cout << "CCCD: ";
    cin.getline(readerCCCD[count], 100);
    cout << "Email: ";
    cin.getline(readerMail[count], 100);
    cout << "Dia chi: ";
    cin.getline(readerAddress[count], 100);
    cout << "Gioi tinh: ";
    cin.getline(readerGender[count], 100);

    cout << "Ngay sinh (ngay/thang/nam): \n";
    cout << "Ngay: ";
    cin >> readerBirthday[count][0];
    cout << "Thang: ";
    cin >> readerBirthday[count][1];
    cout << "Nam: ";
    cin >> readerBirthday[count][2];

    cout << "Ngay lap the (ngay/thang/nam): \n";
    cout << "Ngay: ";
    cin >> readerCardDates[count][0];
    cout << "Thang: ";
    cin >> readerCardDates[count][1];
    cout << "Nam: ";
    cin >> readerCardDates[count][2];

    // Xử lý toán học cho số ngày hết hạn của thẻ độc giả
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
    system("pause");
    system("cls");
}
// c. Chỉnh sửa thông tin của một độc giả
void editReader(int count, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3])
{
    system("cls");
    char readerid[100];
    cout << "\nNhap id cua doc gia can chinh sua: ";
    cin.ignore();
    cin.getline(readerid, 100);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(readerId[i], readerid) == 0)
        {
            // Nếu tìm ra được thì tiếp tục thực hiện các công việc
            cout << "Da tim thay doc gia.\n";
            displayReaderInfo(i, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate);
            int choice;
            do
            {
                // Menu phụ để thực hiện công việc chỉnh sửa 
                cout << "Chon thong tin can thay doi:\n";
                cout << "1. Ho ten.\n";
                cout << "2. Ma doc gia.\n";
                cout << "3. CCCD.\n";
                cout << "4. Email.\n";
                cout << "5. Dia chi.\n";
                cout << "6. Gioi tinh.\n";
                cout << "7. Ngay sinh.\n";
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
                    cout << "Ngay thang nam sinh moi: \n";
                    cout << "Ngay: ";
                    cin >> readerBirthday[i][0];
                    cout << "Thang: ";
                    cin >> readerBirthday[i][1];
                    cout << "Nam: ";
                    cin >> readerBirthday[i][2];
                    break;
                case 0:
                    cout << "Thoat chinh sua\n";
                    system("pause");
                    system("cls");
                    break;
                default:
                    cout << "Lua chon khong hop le.\n";
                    break;
                }
                if (choice != 0)
                {
                    // Cứ mỗi lần sửa xong 1 thông tin thì sẽ cập nhật lại ngay lập tức cho thấy thông tin nào thay đổi
                    system("cls");
                    cout << "Thong tin sau khi chinh sua.\n";
                    displayReaderInfo(i, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate);
                    system("pause");
                }
            } while (choice != 0);

            return;
        }
    }
    cout << "Khong tim thay doc gia can tim de thay doi.\n";
    system("pause");
    system("cls");
}
// d. Xóa thông tin của một độc giả
void removeReader(int &count, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3])
{
    char readerid[100];
    system("cls");
    cout << "\nNhap id cua doc gia can xoa: ";
    cin.ignore();
    cin.getline(readerid, 100);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(readerId[i], readerid) == 0)
        {
            // Nếu tìm ra được thì tiếp tục thực hiện công việc
            cout << "Da tim thay doc gia can tim.\n";
            // In ra thông tin độc giả đó và xác nhận muốn xóa hay không
            displayReaderInfo(i, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate);
            cout << "Ban co muon xoa doc gia nay khong ? (y/n)\n";
            char c;
            cin >> c;
            if (c == 'n' || c == 'N')
            {
                // Chọn no thì quay về
                cout << "Khong xoa doc gia, ve lai menu chinh.\n";
                system("pause");
                system("cls");
                return;
            }
            else if (c == 'y' || c == 'Y')
            {
                // Nếu Yes thì thực hiện phép remove Element trên mảng bằng cách ghi đè, dịch mọi phần tử về trái, giảm số lượng độc giả
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
                // Sau khi xóa xong, break khỏi vòng lặp của hàm
                system("pause");
                system("cls");
                return;
            }
        }
    }
    cout << "Khong tim thay ten doc gia.\n";
    system("pause");
    system("cls");
}
// e. Tìm kiếm độc giả theo CCCD
void FindReaderBaseOnCCCD(int count, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3])
{
    system("cls");
    char cccd[100];
    cout << "\nNhap CCCD cua doc gia can tim: ";
    cin.ignore();
    cin.getline(cccd, 100);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(readerCCCD[i], cccd) == 0)
        {
            displayReaderInfo(i, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate);
            system("pause");
            system("cls");
            return;
        }
    }
    cout << "Khong tim thay doc gia.\n";
    system("pause");
    system("cls");
}
// f. Tìm kiếm độc giả theo họ tên
void FindReaderBaseOnName(int count, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3])
{
    system("cls");
    char name[100];
    cout << "\nNhap ten doc gia can tim kiem: ";
    cin.ignore();
    cin.getline(name, 100);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(readerName[i], name) == 0)
        {
            displayReaderInfo(i, readerName, readerId, readerCCCD, readerMail, readerAddress, readerGender, readerBirthday, readerCardDates, readerExpiryDate);
            system("pause");
            system("cls");
            return;
        }
    }
    cout << "Khong tim thay doc gia.\n";
    system("pause");
    system("cls");
}

// Hàm hỗ trợ để tìm độc giả theo ID
int FindReaderBaseOnId(int count, char readerId[][20], char input[])
{
    int indexId = -1;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(readerId[i], input) == 0)
        {
            indexId = i;
            break;
        }
    }
    return indexId;
}