#ifndef READER_H
#define READER_H

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define MAX_READER 100
void viewReader(char readerName[][100], char readerId[][100], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][2], int readerExpiryDate[][2], int count);
// b. Thêm độc giả
void addReader(int *count, char readerName[][100], char readerId[][100], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][2], int readerExpiryDate[][2]);
// c. Chỉnh sửa thông tin của một độc giả
void editReader(int count, char readerName[][100], char readerCCCD[][100]);
// d. Xóa thông tin của một độc giả
void removeReader(int *count, char readerName[][100], char readerId[][100], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][2], int readerExpiryDate[][2]);
// e. Tìm kiếm độc giả theo CCCD
void FindReaderBaseOnCCCD(int count, char readerCCCD[][100], char readerName[][100]);
// f. Tìm kiếm độc giả theo họ tên
void FindReaderBaseOnName(int count, char readerName[][100]);

void Menu1();
#endif
