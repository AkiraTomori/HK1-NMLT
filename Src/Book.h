#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Support.h"
#include "Constants.h"
#include "Query.h"
using namespace std;

#define MAX_BOOKS 100

void displayBookInfo(int index, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantites[]);
// a. Xem danh sach cac sach trong thu vien
void viewBook(int count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuatites[]);
// b. Them sach
void addBook(int &count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuatites[], int &totalbooks, int &remainBooks);
// c. Chinh sua thong tin cua mot quyen sach
void editBook(int count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantites[], int &totalbooks, int &remainBooks);
// d. Xoa thong tin sach
void removeBook(int &count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuatites[], int &totalbooks, int &remainBooks);
// e. Tim kiem sach theo ISBN
void FindBookBaseOnISBN(int count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantites[]);
// f. Tim kiem theo ten sach
void FindBookBaseOnName(int count, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantites[]);

int FindBookBasedOnISBN(int count, char bookISBN[][20], char input[]);

int FindBookBasesOnName(int count, char bookTitiles[][100], char input[]);
#endif