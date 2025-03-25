#ifndef BOOK_LOAN_H
#define BOOK_LOAN_H

// #define MAX_LOANS 100
// #define MAX_BORROWED_BOOKS 10
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Support.h"
#include "Constants.h"
#include "Reader.h"
#include "Query.h"
#include "Book.h"

using namespace std;

// void borrowBooks(char loanReaderIDs[][20], char loanBooks[][10][20], int loanDates[][3], int returnDates[][3], int returnDateActual[][3], int loanBookCount[], int &countLoan);
// void returnBooks(char loanReaderIDs[][20], int returnDates[][3], int returnDateSActual[][3], int countLoan);

/**
 * @brief Xử lý việc mượn sách của độc giả.
 *
 * @param countReader Số lượng độc giả.
 * @param readerId Mảng chứa mã độc giả.
 * @param readerName Mảng chứa tên độc giả.
 * @param countLoan Tham chiếu đến số lượng phiếu mượn.
 * @param loanReaderID Mảng chứa mã độc giả của các phiếu mượn.
 * @param loanBooks Mảng chứa ISBN các sách được mượn.
 * @param loanBookQuantites Mảng chứa số lượng sách mà độc giả mượn trong mỗi cuốn sách.
 * @param loanDates Mảng chứa ngày mượn sách.
 * @param returnDates Mảng chứa ngày trả dự kiến.
 * @param loanBookCount Mảng chứa số lượng sách mượn trong mỗi phiếu.
 * @param countBook Số lượng sách.
 * @param bookISBN Mảng chứa ISBN của sách.
 * @param bookTitles Mảng chứa tiêu đề của sách.
 * @param bookQuantities Mảng chứa số lượng của sách.
 * @param remainBooks Tham chiếu đến số sách còn lại.
 */

void borrowBooks(int countReader, char readerId[][20], char readerName[][100], int &countLoan, char loanReaderID[][20], char loanBooks[MAX_LOANS][MAX_BORROWED_BOOKS][20], int loanBookQuantites[][MAX_BORROWED_BOOKS], int loanDates[][3], int returnDates[][3],
                 int loanBookCount[], int countBook, char bookISBN[][20], char bookTitles[][100], int bookQuantities[], int &remainBooks);

/**
 * @brief Xử lý việc trả sách của độc giả và cập nhật số lượng sách trong kho.
 *
 * @param countLoan Số lượng phiếu mượn.
 * @param loanReaderIDs Mảng chứa mã độc giả của các phiếu mượn.
 * @param loanBooks Mảng chứa ISBN các sách được mượn.
 * @param loanBookQuantites Mảng chứa số lượng sách mà độc giả mượn trong mỗi cuốn sách.
 * @param loanDates Mảng chứa ngày mượn sách.
 * @param returnDates Mảng chứa ngày trả dự kiến.
 * @param returnDatesActual Mảng chứa ngày trả thực tế.
 * @param loanBookCount Mảng chứa số lượng sách mượn trong mỗi phiếu.
 * @param countBook Số lượng sách.
 * @param bookISBN Mảng chứa ISBN của sách.
 * @param bookQuantities Mảng chứa số lượng của sách.
 * @param bookPrices Mảng chứa giá của sách.
 * @param remainBooks Tham chiếu đến số sách còn lại.
 */

void returnBooks(int countLoan, char loanReaderIDs[][20], char loanBooks[MAX_LOANS][MAX_BORROWED_BOOKS][20], int loanBookQuanties[][MAX_BORROWED_BOOKS],
                 int loanDates[][3], int returnDates[][3], int returnDatesActual[][3], int loanBookCount[],
                 int countBook, char bookISBN[][20], int BookQuantites[], int bookPrices[], int &remainBooks);

#endif
