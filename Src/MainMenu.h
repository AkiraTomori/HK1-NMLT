#ifndef _MAIN_MENU_H
#define _MAIN_MENU_H

// Thư viện hệ thống
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
// Thư viện đơn thể
// Thư viện phụ trách các công việc khác (Khung viền, kiểm tra ngày tháng hợp lệ)
#include "Support.h"
#include "Constants.h"
// Thư viện phụ trách những đơn thể công việc khác nhau mà Client yêu cầu
#include "Reader.h"
#include "Book.h"
#include "Query.h"
#include "BookLoan.h"

using namespace std;

/**
 * @brief Hiển thị thông tin về độc giả, sách và phiếu mượn/trả sách và thống kê.
 *
 * @param countReader Số lượng độc giả.
 * @param readerName Mảng chứa tên độc giả.
 * @param readerId Mảng chứa mã độc giả.
 * @param readerCCCD Mảng chứa CCCD của độc giả.
 * @param readerMail Mảng chứa email của độc giả.
 * @param readerAddress Mảng chứa địa chỉ của độc giả.
 * @param readerGender Mảng chứa giới tính của độc giả.
 * @param readerBirthday Mảng chứa ngày sinh của độc giả.
 * @param readerCardDates Mảng chứa ngày lập thẻ của độc giả.
 * @param readerExpiryDate Mảng chứa ngày hết hạn thẻ của độc giả.
 * @param countBook Số lượng sách.
 * @param totalBooks Tổng số sách.
 * @param remainBooks Số sách còn lại.
 * @param bookISBN Mảng chứa ISBN của sách.
 * @param bookTitles Mảng chứa tiêu đề của sách.
 * @param bookAuthor Mảng chứa tác giả của sách.
 * @param bookPublisher Mảng chứa nhà xuất bản của sách.
 * @param bookGenres Mảng chứa thể loại của sách.
 * @param bookPublishedYear Mảng chứa năm xuất bản của sách.
 * @param bookPrices Mảng chứa giá của sách.
 * @param bookQuantities Mảng chứa số lượng của sách.
 * @param countLoan Số lượng phiếu mượn.
 * @param loanReaderIDs Mảng chứa mã độc giả của các phiếu mượn.
 * @param loanBooks Mảng chứa ISBN các sách được mượn.
 * @param loanBookQuantites Mảng chứa số lượng sách mà độc giả mượn trong mỗi cuốn sách.
 * @param loanDates Mảng chứa ngày mượn sách.
 * @param returnDates Mảng chứa ngày trả dự kiến.
 * @param returnDatesActual Mảng chứa ngày trả thực tế.
 * @param loanBookCount Mảng chứa số lượng sách mượn trong mỗi phiếu.
 */

void Showtime(int &countReader, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3],
              int &countBook, int &totalBooks, int &remainBooks, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantities[],
              int &countLoan, char loanReaderIDs[][20], char loanBooks[][MAX_BORROWED_BOOKS][20], int loanBookQuantities[MAX_LOANS][MAX_BORROWED_BOOKS], int loanDates[MAX_LOANS][3], int returnDates[][3], int returnDatesActual[][3], int loanBookCount[]);

/**
 * @brief Hiển thị thông tin về độc giả
 *
 * @param countReader Số lượng độc giả.
 * @param readerName Mảng chứa tên độc giả.
 * @param readerId Mảng chứa mã độc giả.
 * @param readerCCCD Mảng chứa CCCD của độc giả.
 * @param readerMail Mảng chứa email của độc giả.
 * @param readerAddress Mảng chứa địa chỉ của độc giả.
 * @param readerGender Mảng chứa giới tính của độc giả.
 * @param readerBirthday Mảng chứa ngày sinh của độc giả.
 * @param readerCardDates Mảng chứa ngày lập thẻ của độc giả.
 * @param readerExpiryDate Mảng chứa ngày hết hạn thẻ của độc giả.
 */

void ReaderMenu(int &countReader, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3]);

/**
 * @brief Hiển thị thông tin về sách
 *
 * @param countBook Số lượng sách.
 * @param totalBooks Tổng số sách.
 * @param remainBooks Số sách còn lại.
 * @param bookISBN Mảng chứa ISBN của sách.
 * @param bookTitles Mảng chứa tiêu đề của sách.
 * @param bookAuthor Mảng chứa tác giả của sách.
 * @param bookPublisher Mảng chứa nhà xuất bản của sách.
 * @param bookGenres Mảng chứa thể loại của sách.
 * @param bookPublishedYear Mảng chứa năm xuất bản của sách.
 * @param bookPrices Mảng chứa giá của sách.
 * @param bookQuantities Mảng chứa số lượng của sách.
 */

void BookMenu(int &countBook, int &totalBooks, int &remainBooks, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantities[]);
/**
 * @brief Thông tin về phiếu mượn
 * 
 * @param countReader Số lượng độc giả
 * @param readerId Mảng chứa id độc giả
 * @param readerName Mảng chứa tên độc giả
 * @param countLoan Số lượng phiếu mượn.
 * @param loanReaderIDs Mảng chứa mã độc giả của các phiếu mượn.
 * @param loanBooks Mảng chứa ISBN các sách được mượn.
 * @param loanBookQuantites Mảng chứa số lượng sách mà độc giả mượn trong mỗi cuốn sách.
 * @param loanDates Mảng chứa ngày mượn sách.
 * @param returnDates Mảng chứa ngày trả dự kiến.
 * @param loanBookCount Mảng chứa số lượng sách mượn trong mỗi phiếu.
 * @param countBook Số lượng sách
 * @param bookISBN Mảng chứa ISBN của sách
 * @param bookTitles Mảng chứa tiêu đề của sách
 * @param bookQuantites Mảng chứa số lượng của sách
 * @param remainBooks Số sách còn lại.
 */

void borrowBooksMenu(int countReader, char readerId[][20], char readerName[][100], int countLoan, char loanReaderIDs[][20], char loanBooks[MAX_LOANS][MAX_BORROWED_BOOKS][20], int loanBookQuantites[][MAX_BORROWED_BOOKS], int loanDates[][3], int returnDates[][3],
                     int loanBookCount[], int countBook, char bookISBN[][20], char bookTitles[][100], int bookQuantities[], int &remainBooks);


/**
 * @brief Quản lý trả phiếu mượn của thư viện
 * 
 * @param countLoan Số lượng phiếu mượn.
 * @param loanReaderIDs Mảng chứa mã độc giả của các phiếu mượn.
 * @param loanBooks Mảng chứa ISBN các sách được mượn.
 * @param loanBookQuantites Mảng chứa số lượng sách mà độc giả mượn trong mỗi cuốn sách.
 * @param loanDates Mảng chứa ngày mượn sách.
 * @param returnDates Mảng chứa ngày trả dự kiến.
 * @param returnDatesActual Mảng chứa ngày trả thực tế.
 * @param loanBookCount Mảng chứa số lượng sách mượn trong mỗi phiếu.
 * @param countBook Số lượng sách
 * @param bookISBN Mảng chứa các ISBN 
 * @param BookQuantites Mảng chứa số lượng của sách
 * @param bookPrices Mảng chứa giá của các sách
 * @param remainBooks Giá trị của số sách còn lại
 */
void returnBookMenu(int countLoan, char loanReaderIDs[][20], char loanBooks[MAX_LOANS][MAX_BORROWED_BOOKS][20], int loanBookQuanties[][MAX_BORROWED_BOOKS],
                    int loanDates[][3], int returnDates[][3], int returnDatesActual[][3], int loanBookCount[],
                    int countBook, char bookISBN[][20], int BookQuantites[], int bookPrices[], int &remainBooks);

/**
 * @brief Sử dụng những thông tin của tất cả để thống kê
 *
 * @param countReader Số lượng độc giả.
 * @param readerName Mảng chứa tên độc giả.
 * @param readerId Mảng chứa mã độc giả.
 * @param readerCCCD Mảng chứa CCCD của độc giả.
 * @param readerMail Mảng chứa email của độc giả.
 * @param readerAddress Mảng chứa địa chỉ của độc giả.
 * @param readerGender Mảng chứa giới tính của độc giả.
 * @param readerBirthday Mảng chứa ngày sinh của độc giả.
 * @param readerCardDates Mảng chứa ngày lập thẻ của độc giả.
 * @param readerExpiryDate Mảng chứa ngày hết hạn thẻ của độc giả.
 * @param countBook Số lượng sách.
 * @param totalBooks Tổng số sách.
 * @param remainBooks Số sách còn lại.
 * @param bookISBN Mảng chứa ISBN của sách.
 * @param bookTitles Mảng chứa tiêu đề của sách.
 * @param bookAuthor Mảng chứa tác giả của sách.
 * @param bookPublisher Mảng chứa nhà xuất bản của sách.
 * @param bookGenres Mảng chứa thể loại của sách.
 * @param bookPublishedYear Mảng chứa năm xuất bản của sách.
 * @param bookPrices Mảng chứa giá của sách.
 * @param bookQuantities Mảng chứa số lượng của sách.
 * @param countLoan Số lượng phiếu mượn.
 * @param loanReaderIDs Mảng chứa mã độc giả của các phiếu mượn.
 * @param loanBooks Mảng chứa ISBN các sách được mượn.
 * @param loanBookQuantites Mảng chứa số lượng sách mà độc giả mượn trong mỗi cuốn sách.
 * @param loanDates Mảng chứa ngày mượn sách.
 * @param returnDates Mảng chứa ngày trả dự kiến.
 * @param returnDatesActual Mảng chứa ngày trả thực tế.
 * @param loanBookCount Mảng chứa số lượng sách mượn trong mỗi phiếu.
 */

void QueryMenu(int &countReader, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3],
               int &countBook, int &totalBooks, int &remainBooks, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantities[],
               int &countLoan, char loanReaderIDs[][20], char loanBooks[][MAX_BORROWED_BOOKS][20], int loanBookQuantities[MAX_LOANS][MAX_BORROWED_BOOKS], int loanDates[MAX_LOANS][3], int returnDates[][3], int returnDatesActual[][3], int loanBookCount[]);

#endif