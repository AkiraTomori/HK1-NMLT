#ifndef SUPPORT_H
#define SUPPORT_H

#include <iostream>
#include <string.h>
using namespace std;

/**
 * @brief kiểm tra xem một năm có phải là năm nhuận không
 * @param year Năm đang xét
 * @return là năm nhuận hay không
 */
bool isLeapYear(int year);

/**
 * @brief Lấy những ngày trong 1 tháng
 * @param month tháng hiện tại
 * @param year năm hiện tại
 * @return trả về số ngày trong 1 tháng
 */
int getDaysInMonth(int month, int year);
/**
 * @brief Khung trang trí thứ nhất
 */
void header1();
/**
 * @brief khung trang trí thứ hai
 */
void header2();

#endif
