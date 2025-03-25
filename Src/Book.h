#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Support.h"
#include "Constants.h"
#include "Query.h"
using namespace std;

/**
 * @brief Hiển thị thông tin của một cuốn sách.
 *
 * @param index Chỉ số của cuốn sách trong mảng.
 * @param bookISBN Mảng chứa ISBN của sách.
 * @param bookTitles Mảng chứa tiêu đề của sách.
 * @param bookAuthor Mảng chứa tác giả của sách.
 * @param bookPublisher Mảng chứa nhà xuất bản của sách.
 * @param bookGenres Mảng chứa thể loại của sách.
 * @param bookPublishedYear Mảng chứa năm xuất bản của sách.
 * @param bookPrices Mảng chứa giá của sách.
 * @param bookQuantites Mảng chứa số lượng của sách.
 */

void displayBookInfo(int index, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantites[]);
// a. Xem danh sach cac sach trong thu vien

/**
 * @brief Xem danh sách các sách trong thư viện.
 *
 * @param count Số lượng sách.
 * @param bookISBN Mảng chứa ISBN của sách.
 * @param bookTitles Mảng chứa tiêu đề của sách.
 * @param bookAuthor Mảng chứa tác giả của sách.
 * @param bookPublisher Mảng chứa nhà xuất bản của sách.
 * @param bookGenres Mảng chứa thể loại của sách.
 * @param bookPublishedYear Mảng chứa năm xuất bản của sách.
 * @param bookPrices Mảng chứa giá của sách.
 * @param bookQuantites Mảng chứa số lượng của sách.
 */

void viewBook(int count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuatites[]);
// b. Them sach

/**
 * @brief Thêm sách vào thư viện.
 *
 * @param count Tham chiếu đến số lượng sách.
 * @param bookISBN Mảng chứa ISBN của sách.
 * @param bookTitles Mảng chứa tiêu đề của sách.
 * @param bookAuthor Mảng chứa tác giả của sách.
 * @param bookPublisher Mảng chứa nhà xuất bản của sách.
 * @param bookGenres Mảng chứa thể loại của sách.
 * @param bookPublishedYear Mảng chứa năm xuất bản của sách.
 * @param bookPrices Mảng chứa giá của sách.
 * @param bookQuantites Mảng chứa số lượng của sách.
 * @param totalbooks Tham chiếu đến tổng số sách.
 * @param remainBooks Tham chiếu đến số sách còn lại.
 */

void addBook(int &count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuatites[], int &totalbooks, int &remainBooks);
// c. Chinh sua thong tin cua mot quyen sach

/**
 * @brief Chỉnh sửa thông tin của một cuốn sách.
 *
 * @param count Số lượng sách.
 * @param bookISBN Mảng chứa ISBN của sách.
 * @param bookTitles Mảng chứa tiêu đề của sách.
 * @param bookAuthor Mảng chứa tác giả của sách.
 * @param bookPublisher Mảng chứa nhà xuất bản của sách.
 * @param bookGenres Mảng chứa thể loại của sách.
 * @param bookPublishedYear Mảng chứa năm xuất bản của sách.
 * @param bookPrices Mảng chứa giá của sách.
 * @param bookQuantites Mảng chứa số lượng của sách.
 * @param totalbooks Tham chiếu đến tổng số sách.
 * @param remainBooks Tham chiếu đến số sách còn lại.
 */

void editBook(int count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantites[], int &totalbooks, int &remainBooks);
// d. Xoa thong tin sach

/**
 * @brief Xóa thông tin của một cuốn sách.
 *
 * @param count Tham chiếu đến số lượng sách.
 * @param bookISBN Mảng chứa ISBN của sách.
 * @param bookTitles Mảng chứa tiêu đề của sách.
 * @param bookAuthor Mảng chứa tác giả của sách.
 * @param bookPublisher Mảng chứa nhà xuất bản của sách.
 * @param bookGenres Mảng chứa thể loại của sách.
 * @param bookPublishedYear Mảng chứa năm xuất bản của sách.
 * @param bookPrices Mảng chứa giá của sách.
 * @param bookQuantites Mảng chứa số lượng của sách.
 * @param totalbooks Tham chiếu đến tổng số sách.
 * @param remainBooks Tham chiếu đến số sách còn lại.
 */

void removeBook(int &count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuatites[], int &totalbooks, int &remainBooks);
// e. Tim kiem sach theo ISBN

/**
 * @brief Tìm kiếm sách theo ISBN.
 *
 * @param count Số lượng sách.
 * @param bookISBN Mảng chứa ISBN của sách.
 * @param bookTitles Mảng chứa tiêu đề của sách.
 * @param bookAuthor Mảng chứa tác giả của sách.
 * @param bookPublisher Mảng chứa nhà xuất bản của sách.
 * @param bookGenres Mảng chứa thể loại của sách.
 * @param bookPublishedYear Mảng chứa năm xuất bản của sách.
 * @param bookPrices Mảng chứa giá của sách.
 * @param bookQuantites Mảng chứa số lượng của sách.
 */

void FindBookBaseOnISBN(int count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantites[]);
// f. Tim kiem theo ten sach

/**
 * @brief Tìm kiếm sách theo tên.
 *
 * @param count Số lượng sách.
 * @param bookISBN Mảng chứa ISBN của sách.
 * @param bookTitles Mảng chứa tiêu đề của sách.
 * @param bookAuthor Mảng chứa tác giả của sách.
 * @param bookPublisher Mảng chứa nhà xuất bản của sách.
 * @param bookGenres Mảng chứa thể loại của sách.
 * @param bookPublishedYear Mảng chứa năm xuất bản của sách.
 * @param bookPrices Mảng chứa giá của sách.
 * @param bookQuantites Mảng chứa số lượng của sách.
 */

void FindBookBaseOnName(int count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantites[]);

/**
 * @brief Tìm kiếm sách theo ISBN.
 *
 * @param count Số lượng sách.
 * @param bookISBN Mảng chứa ISBN của sách.
 * @param input ISBN cần tìm kiếm.
 * @return Chỉ số của sách trong mảng.
 */

int FindBookBasedOnISBN(int count, char bookISBN[][20], char input[]);

/**
 * @brief Tìm kiếm sách theo tên.
 *
 * @param count Số lượng sách.
 * @param bookTitles Mảng chứa tiêu đề của sách.
 * @param input Tên sách cần tìm kiếm.
 * @return Chỉ số của sách trong mảng.
 */

int FindBookBasesOnName(int count, char bookTitiles[][100], char input[]);
#endif