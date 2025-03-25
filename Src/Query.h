#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <string.h>
#include "Constants.h"
using namespace std;

// A. Thong ke tong sach co trong thu vien
/**
 * @brief Thống kê số lượng sách có trong thư viện
 * @param bookQuanties Mảng chứa số lượng các sách
 * @param countBook Số lượng sách có trong mảng
 * @return Tổng số lượng sách đang có ở trong thư viện
 */

int countTotalBooks(int bookQuantites[], int countBook);
// B. Thong ke sach theo the loai
/**
 * @brief Thống kê các độc giả theo giới tính
 * @param bookGenres Mảng chứa thể loại của sách
 * @param bookQuanties Mảng chứa số lượng của sách
 * @param countBook Số lượng sách có trong mảng
 */

void countBookByGenres(char bookGenres[][50], int bookQuanties[], int countBook);
// C. Thong ke co bao nhieu doc gia
/**
 * @brief Thống kê số đọc giả ở trong thư viện
 * @param countReader số lượng độc giả
 * @return số lượng độc giả hiện có
 */

int countTotalReaders(int countReader);
// D. Thong ke co bao nhieu doc gia theo gioi tinh

/**
 * @brief Thống kê số lượng độc giả theo giới tính
 * @param readerGender mảng giới tính của các độc giả
 * @param countReader số lượng độc giả
 */

void countReaderByGenders(char readerGender[][100], int countReader);
// E. Thong ke so sach dang muon

/**
 * @brief Thống kê số lượng sách đang được độc giả mượn
 * @param countLoan Số lượng thẻ mượn
 * @param loanBookQuantites Mảng chứa danh sách số lượng sách mà độc giả mượn
 * @param LoanBookCount Mảng chứa số lượng sách mà đọc giả mượn
 * @return trả về số lượng sách được mượn
 */

int countBorrowedBooks(int countLoan, int loanBookQuantites[][MAX_BORROWED_BOOKS], int LoanBookCount[]);
// F. Thong ke danh sach doc gia bi tre hen

/**
 * @brief Thống kê số lượng độc giả bị trễ hẹn
 * @param countLoan Số lượng thẻ mượn
 * @param loanReaderIDs Mảng chứa danh sách đọc giả
 * @param returnDates Mảng chứa danh sách ngày trả dự kiến
 * @param returnDatesActual Mảng chứa danh sách ngày trả thực tế
 */
void listOverduedReaders(int countLoan, char loanReaderIDs[][20], int returnDates[][3], int returnDatesActual[][3]);
#endif