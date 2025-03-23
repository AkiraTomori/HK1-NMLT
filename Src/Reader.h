#ifndef READER_H
#define READER_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Support.h"
#include <conio.h>
#include "Constants.h"
using namespace std;

#define MAX_READER 100
// a. Xem danh sach doc gia va cac thong tin ca nhan
void viewReader(char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3], int count);
// b. Thêm độc giả
void addReader(int &count, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3]);
// c. Chỉnh sửa thông tin của một độc giả
void editReader(int count, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3]);
// d. Xóa thông tin của một độc giả
void removeReader(int &count, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3]);
// e. Tìm kiếm độc giả theo CCCD
void FindReaderBaseOnCCCD(int count, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3]);
// f. Tìm kiếm độc giả theo họ tên
void FindReaderBaseOnName(int count, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3]);

void displayReaderInfo(int index, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3]);

int FindReaderBaseOnId(int count, char readerId[][20], char input[]);
// void Menu1();
#endif
