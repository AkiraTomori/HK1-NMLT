#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <string.h>
#include "Constants.h"
using namespace std;
// a. Thong ke tong sach co trong thu vien
int countTotalBooks(int bookQuantites[], int countBook);
// B. Thong ke sach theo the loai
void countBookByGenres(char bookGenres[][50], int bookQuanties[], int countBook);
// C. Thong ke co bao nhieu doc gia
int countTotalReaders(int countReader);
// D. Thong ke co bao nhieu doc gia theo gioi tinh
void countReaderByGenders(char readerGender[][100], int countReader);
// E. Thong ke so sach dang muon

// F. Thong ke danh sach doc gia bi tre hen

#endif