#ifndef READER_H
#define READER_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Support.h"
#include <conio.h>
#include "Constants.h"
using namespace std;

// a. Xem danh sach doc gia va cac thong tin ca nhan
/**
 * @brief Xem danh sách độc giả
 *
 * @param readerName Mảng chứa tên độc giả
 * @param readerId Mảng chứa mã độc giả
 * @param readerCCCD Mảng chứa căn cước công dân
 * @param readerMail Mảng chứa mail của độc giả
 * @param readerAddress Mảng chứa địa chỉ của độc giả
 * @param readerGender Mảng chứa giới tính của độc giả
 * @param readerBirthday Mảng chứa ngày sinh của độc giả
 * @param readerCardDates Mảng chứa ngày lập thẻ của độc giả
 * @param readerExipiryDates Mảng chứa ngày hết hạn của độc giả
 * @param count Số lượng độc giả
 */

void viewReader(char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3], int count);
// b. Thêm độc giả

/**
 * @brief Thêm độc giả
 *
 * @param readerName Mảng chứa tên độc giả
 * @param readerId Mảng chứa mã độc giả
 * @param readerCCCD Mảng chứa căn cước công dân
 * @param readerMail Mảng chứa mail của độc giả
 * @param readerAddress Mảng chứa địa chỉ của độc giả
 * @param readerGender Mảng chứa giới tính của độc giả
 * @param readerBirthday Mảng chứa ngày sinh của độc giả
 * @param readerCardDates Mảng chứa ngày lập thẻ của độc giả
 * @param readerExipiryDates Mảng chứa ngày hết hạn của độc giả
 * @param count Số lượng độc giả
 */

void addReader(int &count, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3]);
// c. Chỉnh sửa thông tin của một độc giả

/**
 * @brief Chỉnh sửa thông tin của độc giả
 *
 * @param readerName Mảng chứa tên độc giả
 * @param readerId Mảng chứa mã độc giả
 * @param readerCCCD Mảng chứa căn cước công dân
 * @param readerMail Mảng chứa mail của độc giả
 * @param readerAddress Mảng chứa địa chỉ của độc giả
 * @param readerGender Mảng chứa giới tính của độc giả
 * @param readerBirthday Mảng chứa ngày sinh của độc giả
 * @param readerCardDates Mảng chứa ngày lập thẻ của độc giả
 * @param readerExipiryDates Mảng chứa ngày hết hạn của độc giả
 * @param count Số lượng độc giả
 */

void editReader(int count, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3]);
// d. Xóa thông tin của một độc giả

/**
 * @brief Xóa 1 độc giả
 *
 * @param readerName Mảng chứa tên độc giả
 * @param readerId Mảng chứa mã độc giả
 * @param readerCCCD Mảng chứa căn cước công dân
 * @param readerMail Mảng chứa mail của độc giả
 * @param readerAddress Mảng chứa địa chỉ của độc giả
 * @param readerGender Mảng chứa giới tính của độc giả
 * @param readerBirthday Mảng chứa ngày sinh của độc giả
 * @param readerCardDates Mảng chứa ngày lập thẻ của độc giả
 * @param readerExipiryDates Mảng chứa ngày hết hạn của độc giả
 * @param count Số lượng độc giả
 */

void removeReader(int &count, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3]);
// e. Tìm kiếm độc giả theo CCCD

/**
 * @brief Tìm kiếm độc giả theo CCCD
 *
 * @param readerName Mảng chứa tên độc giả
 * @param readerId Mảng chứa mã độc giả
 * @param readerCCCD Mảng chứa căn cước công dân
 * @param readerMail Mảng chứa mail của độc giả
 * @param readerAddress Mảng chứa địa chỉ của độc giả
 * @param readerGender Mảng chứa giới tính của độc giả
 * @param readerBirthday Mảng chứa ngày sinh của độc giả
 * @param readerCardDates Mảng chứa ngày lập thẻ của độc giả
 * @param readerExipiryDates Mảng chứa ngày hết hạn của độc giả
 * @param count Số lượng độc giả
 */

void FindReaderBaseOnCCCD(int count, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3]);
// f. Tìm kiếm độc giả theo họ tên

/**
 * @brief Tìm kiếm độc giả theo họ và tên
 *
 * @param readerName Mảng chứa tên độc giả
 * @param readerId Mảng chứa mã độc giả
 * @param readerCCCD Mảng chứa căn cước công dân
 * @param readerMail Mảng chứa mail của độc giả
 * @param readerAddress Mảng chứa địa chỉ của độc giả
 * @param readerGender Mảng chứa giới tính của độc giả
 * @param readerBirthday Mảng chứa ngày sinh của độc giả
 * @param readerCardDates Mảng chứa ngày lập thẻ của độc giả
 * @param readerExipiryDates Mảng chứa ngày hết hạn của độc giả
 * @param count Số lượng độc giả
 */

void FindReaderBaseOnName(int count, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3]);

/**
 * @brief Hiển thị một độc giả
 *
 * @param readerName Mảng chứa tên độc giả
 * @param readerId Mảng chứa mã độc giả
 * @param readerCCCD Mảng chứa căn cước công dân
 * @param readerMail Mảng chứa mail của độc giả
 * @param readerAddress Mảng chứa địa chỉ của độc giả
 * @param readerGender Mảng chứa giới tính của độc giả
 * @param readerBirthday Mảng chứa ngày sinh của độc giả
 * @param readerCardDates Mảng chứa ngày lập thẻ của độc giả
 * @param readerExipiryDates Mảng chứa ngày hết hạn của độc giả
 * @param count Số lượng độc giả
 */

void displayReaderInfo(int index, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3]);

/**
 * @brief Tìm độc giả dựa trên id độc giả
 * @param count danh sách độc giả
 * @param readerId Mảng chứa danh sách của độc giả
 * @param input id độc giả cần được tìm kiếm
 * @return trả về vị trí của độc giả đó
 */

/**
 * @brief Tìm kiếm độc giả theo ID 
 * 
 * @param count Số lượng độc giả
 * @param readerId mảng chứa các Id độc giả
 * @param input Id độc giả mà người dùng muốn tìm kiếm
 * 
 * @return trả về vị trí tìm được kết quả (khác giá trị -1)
 */
int FindReaderBaseOnId(int count, char readerId[][20], char input[]);
// void Menu1();
#endif
