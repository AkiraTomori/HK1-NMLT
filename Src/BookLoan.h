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


void borrowBooks(int countReader, char readerId[][20], char readerName[][100], int countLoan, char loanReaderID[][20], char loanBooks[MAX_LOANS][MAX_BORROWED_BOOKS][20], int loanBookQuantites[][MAX_BORROWED_BOOKS], int loanDates[][3], int returnDates[][3],
    int loanBookCount[], int countBook, char bookISBN[][20], char bookTitles[][100], int bookQuantities[], int &remainBooks);

void returnBooks(int countLoan, char loanReaderIDs[][20], char loanBooks[MAX_LOANS][MAX_BORROWED_BOOKS][20], int loanBookQuanties[][MAX_BORROWED_BOOKS], 
    int loanDates[][3], int returnDates[][3], int returnDatesActual[][3], int loanBookCount[],
    int countBook, char bookISBN[][20], int BookQuantites[], int bookPrices[], int &remainBooks);

#endif
