#ifndef SRC_GREP_GREPNEW_H_
#define SRC_GREP_GREPNEW_H_

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int viewMas(const int argc, char* argv[]);
int scanMas(int* n, const int argc, int* masdoc, int* mas_flag,
            char* argv[]);  // начинаем работать с массивом
int searchFlagE(int* n, int i, int argc, int* masdoc, int* mas_flag,
                char* argv[]);
int parsingMas(int i, int j, int* mas_flag, char* argv[]);
int sortMass(int i, int j, int* masflag,
             char* argv[]);  // Функция сортировки массива
void printError();
int searchSearchNoEF(int argc, const int* mas_flag,
                     char* argv[]);  // Строка для поиска если не встретила E F
int sendDocSearch(int i, int j,
                  char* argv[]);  // Функция добавляет поисковые запросы в файл
void openFile(int n, int p, int argc, int* masdoc, int* mas_flag, char* argv[]);
void readTextStr(char* text);
void readTextDoc(int n, int p, int argc, int* masdoc, int* mas_flag,
                 char* argv[]);
int openFileAtAdress(
    int i, int j,
    char* argv[]);  // Функция открывает файл построчно после флага ф
int openDoc(char* file, char* set,
            char* text);  // для функции без набора документов
void readAllDoc(int n_str, int counter, char* file_name, FILE* pfile, char* buf,
                int n, const int* masdoc, int* mas_flag, char* arr,
                char* argv[]);
void inFile(int n_str, int counter, char* file_name, char* name, FILE* file,
            char* buf, int* mas_flag, char* arr);
int reg_file(char* arr, char* buf, const int* masflag);
void clearMassSimbol(char* arr);  // убирает невидимые символы с массива
void print_result(int value);
int flagO(char* arr, char* buf, const int* mas_flag);
void ignorflagIinO(char* arr, char* buf, int* mas, char* arrcopy, char* arrbuf);
int strstr1(const char* arr, const char* buf, int* mas_of, int* ofik);
#endif  // SRC_GREP_GREPNEW_H_
