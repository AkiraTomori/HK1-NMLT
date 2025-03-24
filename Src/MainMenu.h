#ifndef _MAIN_MENU_H
#define _MAIN_MENU_H
// Thư viện hệ thống
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
// Đoạn code đơn thể
#include "Support.h"
#include "Constants.h"
#include "Reader.h"
#include "Book.h"
#include "Query.h"
#include "BookLoan.h"

using namespace std;

void Showtime(int &countReader, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3],
              int &countBook, int &totalBooks, int &remainBooks, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantities[],
              int &countLoan, char loanReaderIDs[][20], char loanBooks[][MAX_BORROWED_BOOKS][20], int loanBookQuantities[MAX_LOANS][MAX_BORROWED_BOOKS], int loanDates[MAX_LOANS][3], int returnDates[][3], int returnDatesActual[][3], int loanBookCount[]);

void ReaderMenu(int &countReader, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3]);
void BookMenu(int &countBook, int &totalBooks, int &remainBooks, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantities[]);
void borrowBooksMenu(int countReader, char readerId[][20], char readerName[][100], int countLoan, char loanReaderIDs[][20], char loanBooks[MAX_LOANS][MAX_BORROWED_BOOKS][20], int loanBookQuantites[][MAX_BORROWED_BOOKS], int loanDates[][3], int returnDates[][3],
                     int loanBookCount[], int countBook, char bookISBN[][20], char bookTitles[][100], int bookQuantities[], int &remainBooks);
void returnBookMenu(int countLoan, char loanReaderIDs[][20], char loanBooks[MAX_LOANS][MAX_BORROWED_BOOKS][20], int loanBookQuanties[][MAX_BORROWED_BOOKS],
                    int loanDates[][3], int returnDates[][3], int returnDatesActual[][3], int loanBookCount[],
                    int countBook, char bookISBN[][20], int BookQuantites[], int bookPrices[], int &remainBooks);
void QueryMenu(int &countReader, char readerName[][100], char readerId[][20], char readerCCCD[][100], char readerMail[][100], char readerAddress[][100], char readerGender[][100], int readerBirthday[][3], int readerCardDates[][3], int readerExpiryDate[][3],
               int &countBook, int &totalBooks, int &remainBooks, char bookISBN[][20], char bookTitles[][100], char bookAuthor[][100], char bookPublisher[][100], char bookGenres[][50], int bookPublishedYear[], int bookPrices[], int bookQuantities[],
               int &countLoan, char loanReaderIDs[][20], char loanBooks[][MAX_BORROWED_BOOKS][20], int loanBookQuantities[MAX_LOANS][MAX_BORROWED_BOOKS], int loanDates[MAX_LOANS][3], int returnDates[][3], int returnDatesActual[][3], int loanBookCount[]);

#endif