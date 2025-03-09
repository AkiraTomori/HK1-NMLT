#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Support.h"
#include "Constants.h"
using namespace std;

#define MAX_BOOKS 100

void displayBookInfo(int index, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantites[]);
// a. Xem danh sach cac sach trong thu vien
void viewBook(int count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuatites[]);
// b. Them sach
void addBook(int &count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuatites[]);
// c. Chinh sua thong tin cua mot quyen sach
void editBook(int count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantites[]);
// d. Xoa thong tin sach
void removeBook(int &count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuatites[]);
// e. Tim kiem sach theo ISBN
void FindBookBaseOnISBN(int count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantites[]);
// f. Tim kiem theo ten sach
void FindBookBaseOnName(int count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantites[]);


#endif