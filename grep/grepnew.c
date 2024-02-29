#include "grepnew.h"
int strstr1(const char* arr, const char* buf, int* mas_of, int* ofik);
int main(int argc, char* argv[]) {
  openDoc("Temp1.txt", "w", "");
  viewMas(argc, argv);
  return 0;
}
int viewMas(const int argc, char* argv[]) {
  int nn = 0;
  int* n = &nn;
  int sum_flag = 0;  // сумма встречаемости эл-в флагов
  for (int i = 0; i < argc; i++) {
    if (argv[i][0] == '-') {
      sum_flag++;
    }
  }
  if ((argc - sum_flag) > 1 && argc > 1) {
    int mas_flag[11] = {0};
    int masdoc[8000] = {-1};
    int p_i = scanMas(n, argc, masdoc, mas_flag, argv);
    openFile(nn, p_i, argc, masdoc, mas_flag, argv);
  } else {
    printError();
  }
  return 0;
}
int scanMas(int* n, const int argc, int* masdoc, int* mas_flag, char* argv[]) {
  int doc_point_i = 0;
  int doc_point_ii = 0;
  for (int i = 1; i < argc; i++) {
    int len_argv_i = strlen(argv[i]);
    if (argv[i][0] == '-') {
      if ((doc_point_ii = searchFlagE(n, i, argc, masdoc, mas_flag, argv)) ==
          0) {
        parsingMas(i, len_argv_i, mas_flag, argv);
      }
    }
  }
  doc_point_i = searchSearchNoEF(argc, mas_flag, argv);
  if (doc_point_i < doc_point_ii) {
    doc_point_i = doc_point_ii;
  }
  return doc_point_i;
}
int searchFlagE(int* n, int i, int argc, int* masdoc, int* mas_flag,
                char* argv[]) {
  int ret = 0, i_point = 0;
  int len_argv_i = strlen(argv[i]);
  for (int j = 0; j < len_argv_i; j++) {
    if (argv[i][j] == 'e' || argv[i][j] == 'f') {
      sortMass(i, j, mas_flag, argv);
      if (j < len_argv_i - 1) {
        parsingMas(i, j, mas_flag, argv);
        if (argv[i][j] == 'e') {
          i_point = sendDocSearch(i, j, argv);
          if (i < argc - 1) {
            i++;
            j = 0;
          }
          ret = 1;
          len_argv_i = j;
        }
        if (argv[i][j] == 'f') {
          i_point = openFileAtAdress(i, j, argv);
          int nn = *n;
          masdoc[nn] = i;
          masdoc[nn + 1] = j + 1;
          *n = *n + 2;
          if (i < argc - 1) {
            i++;
            j = 0;
          }
          ret = 1;
          len_argv_i = j;
        }
      } else if (j == len_argv_i - 1) {
        parsingMas(i, j, mas_flag, argv);
        if (argv[i][j] == 'e') {
          i++;
          int t = 0;
          i_point = sendDocSearch(i, t, argv);
          ret = 1;
        }
        if (argv[i][j] == 'f') {
          i++;
          int t = 0;
          i_point = openFileAtAdress(i, t, argv);
          int nn = *n;
          masdoc[nn] = i;
          masdoc[nn + 1] = 0;
          *n = *n + 2;
          ret = 1;
        }
      }
    }
    if (i_point > ret) {
      ret = i_point;
    }
  }
  return ret;
}
int parsingMas(int i, int j, int* mas_flag, char* argv[]) {
  int ret = 0;
  for (int jj = 1; jj < j; jj++) {
    sortMass(i, jj, mas_flag, argv);
  }
  return ret;
}
int sortMass(int i, int j, int* masflag, char* argv[]) {
  int f1 = 0;
  char flags[] = "ivclnhsfeo";
  int lenflags = strlen(flags);
  for (int k = 0; k < lenflags; k++) {
    if (argv[i][j] == flags[k]) {
      masflag[k] = 1;
      f1++;
    }
  }
  if (f1 == 0) {
    printf("grep: invalid option -- %c\nusage: grep ", argv[i][j]);
    printError();
    exit(1);
  }
  return f1;
}
void printError() {
  printf("[-abcdDEFGHhIiJLlMmnOopqRSsUVvwXxZz] [-A num] [-B num] [-C[num]]\n");
  printf("[-e pattern] [-f file] [--binary-files=value] [--color=when]\n");
  printf(
      "[--context[=num]] [--directories=action] [--label] [--line-buffered]\n");
  printf("[--null] [pattern] [file ...]");
}
int searchSearchNoEF(int argc, const int* mas_flag, char* argv[]) {
  int doc_point_i = 0;
  if (mas_flag[7] == 0 && mas_flag[8] == 0) {
    int n = 0;
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] != '-' && n == 0) {
        int t = 0;
        doc_point_i = sendDocSearch(i, t, argv);
        n++;
      }
    }
  }
  return doc_point_i;
}
int sendDocSearch(int i, int j, char* argv[]) {
  int doc_point = i + 1;
  int len_str = strlen(argv[i]);
  int k = 0, l = 0;
  char t[8000] = {0};
  if (j > 0) {
    k = j + 1;
  }
  for (; k < len_str; k++) {
    t[l] = argv[i][k];
    l++;
  }
  openDoc("Temp1.txt", "a+", t);
  return doc_point;
}
int openFileAtAdress(int i, int j, char* argv[]) {
  int doc_point = i + 1;
  int len_str = strlen(argv[i]);
  int k = 0;
  char t[8000] = {0};
  int l = 0;
  if (j > 0) {
    k = j + 1;
  }
  for (; k < len_str; k++) {
    t[l] = argv[i][k];
    l++;
  }
  FILE* file;
  file = fopen(t, "r");
  if (!file) {
    printf("grep: %s: No such file or directory", t);
    exit(1);
  } else {
    fclose(file);
  }
  return doc_point;
}
void openFile(int n, int p, int argc, int* masdoc, int* mas_flag,
              char* argv[]) {
  int i = p;
  FILE* pfile = NULL;
  if (argc == p) {
    char buf[6000] = {0};
    int n_str = 0;
    // exit(1);
    while (1 > 0) {
      char text[8000] = {0};
      n_str++;
      mas_flag[10] = 0;
      readTextStr(text);
      readAllDoc(n_str, 0, "", pfile, buf, n, masdoc, mas_flag, text, argv);
    }
  } else {
    readTextDoc(n, i, argc, masdoc, mas_flag, argv);
  }
}
void readTextDoc(int n, int p, int argc, int* masdoc, int* mas_flag,
                 char* argv[]) {
  int pt = 0, counter = 0, not_file = 0;
  while (p < argc) {
    FILE *pfile = NULL, *file;
    if (mas_flag[1] > 0) {
      mas_flag[9] = 0;
    }
    if (mas_flag[2] > 0) {
      mas_flag[2] = 1;
    }
    if (mas_flag[3] > 0) {
      mas_flag[3] = 1;
    }
    file = fopen(argv[p], "r");
    if (!file) {
      if (mas_flag[6] == 0) {
        printf("grep: %s: No such file or directory\n", argv[p]);
        not_file = 1;
      }
    } else {
      int n_str = 0;
      char arr[8000] = {0};
      char buf[8000] = {0};
      while (!feof(file)) {
        mas_flag[10] = 0;
        fgets(arr, 6000, file);
        n_str++;
        if ((p + 1 == argc && pt != 0) || (p + 1 != argc)) {
          counter = 1;
        }
        readAllDoc(n_str, counter, argv[p], pfile, buf, n, masdoc, mas_flag,
                   arr, argv);
        memset(arr, 0, 8000);
      }
      fclose(file);
    }
    p++;
    pt++;
    if ((mas_flag[2] > 0 && not_file == 0)) {
      if (counter == 1 && mas_flag[5] == 0) {
        printf("%s:", argv[p - 1]);
      }
      printf("%d\n", mas_flag[2] - 1);
    }
    if (mas_flag[3] == 3) {
      printf("%s\n", argv[p - 1]);
    }
    not_file = 0;
  }
}
int openDoc(char* file, char* set, char* text) {
  FILE* pfile;
  pfile = fopen(file, set);
  if (set[0] == 'a') {
    fprintf(pfile, "%s", text);
    fprintf(pfile, "\n");
  }
  fclose(pfile);
  return 0;
}
void readTextStr(char* text) {
  char c = 0;
  for (int i = 0; c != '\n'; i++) {
    scanf("%c", &c);
    text[i] = c;
  }
  clearMassSimbol(text);
}
void readAllDoc(int n_str, int counter, char* file_name, FILE* pfile, char* buf,
                int n, const int* masdoc, int* mas_flag, char* arr,
                char* argv[]) {
  inFile(n_str, counter, file_name, "Temp1.txt", pfile, buf, mas_flag, arr);
  for (int z = 0; z < n; z = z + 2) {
    char yy[8000] = {0};
    int i = masdoc[z];
    int j = masdoc[z + 1];
    int what = strlen(argv[i]);
    int kk = 0;
    for (int m = j; m < what; m++) {
      yy[kk] = argv[i][m];
      kk++;
    }
    inFile(n_str, counter, file_name, yy, pfile, buf, mas_flag, arr);
  }
}
void inFile(int n_str, int counter, char* file_name, char* name, FILE* file,
            char* buf, int* mas_flag, char* arr) {
  int mas_of[8000] = {-1};
  int counter1 = 0;
  file = fopen(name, "r");
  while (!feof(file) || buf[0] != 0) {
    fgets(buf, 6000, file);
    int symv1 = strlen(buf);
    clearMassSimbol(buf);
    int n2 = strlen(buf);
    if (buf[0] != '\0' && arr[0] != '\0') {
      int counter_o = 0;
      if (mas_flag[9] == 1 && mas_flag[8] == 0 && mas_flag[7] == 0) {
        if (mas_flag[0] == 1) {
          char arrcopy[8000] = {0};
          char arrbuf[8000] = {0};
          ignorflagIinO(arr, buf, mas_of, arrcopy, arrbuf);
          counter_o = flagO(arrcopy, arrbuf, mas_flag) - 1;
        } else {
          counter_o = flagO(arr, buf, mas_flag) - 1;
        }
      }
      int regex_f = reg_file(arr, buf, mas_flag);
      if (mas_flag[10] == 0) {
        if (regex_f == 0) {
          mas_flag[10]++;
        }
        buf[symv1 - 1] = '\n';
        if ((regex_f == 0 && mas_flag[10] == 1)) {
          if (mas_flag[3] >= 1) {
            mas_flag[3] = 3;
          }
          if (mas_flag[2] > 0) {
            mas_flag[2]++;
          }
          if (mas_flag[3] == 0) {
            if (mas_flag[2] == 0) {
              while (counter_o >= 0) {
                if (counter == 1 && mas_flag[5] == 0) {
                  printf("%s:", file_name);
                }
                if (mas_flag[4] == 1) {
                  printf("%d:", n_str);
                }
                if (mas_flag[9] > 0 && mas_flag[8] == 0 && mas_flag[7] == 0) {
                  if (mas_flag[0] == 0) printf("%s", buf);
                  if (mas_flag[0] > 0) {
                    for (int j = 0; j < n2 - 1; j++) {
                      printf("%c", arr[mas_of[counter1] + j]);
                    }
                    printf("\n");
                    counter1++;
                  }
                } else {
                  printf("%s", arr);
                }
                counter_o--;
              }
            }
          }
        }
      }
    }
    memset(buf, 0, 8000);
  }
  fclose(file);
}
void clearMassSimbol(char* arr) {
  int size_str = strlen(arr);
  for (int i = 0; i <= size_str; i++) {
    if (arr[0] == '\n') {
      arr[0] = ' ';
    }
    if (arr[i] == '\n') {
      arr[i] = ' ';
    }
  }
}
int reg_file(char* arr, char* buf, const int* masflag) {
  int n = strlen(buf);
  if (buf[n - 1] == '\n' || buf[n - 1] == ' ') buf[n - 1] = '\0';
  regex_t reegex;
  int value;
  if (masflag[0] == 0) {
    regcomp(&reegex, buf, 0);
  }
  if (masflag[0] == 1) {
    regcomp(&reegex, buf, REG_ICASE);
  }
  value = regexec(&reegex, arr, 0, NULL, 0);
  regfree(&reegex);
  if (value != 1) {
    value = 0;
  }
  if (masflag[1] == 1) {
    if (value == 1) {
      value = 0;
    } else if (value == 0) {
      value = 1;
    }
  }
  return value;
}
int flagO(char* arr, char* buf, const int* mas_flag) {
  char* strSrc = arr;
  char* strFnd = buf;
  if (mas_flag[0] == 0) strFnd[strlen(strFnd) - 1] = '\0';
  char* strSrcEnd = strSrc + strlen(strSrc);
  int fndLen = strlen(strFnd);
  int count = 0;
  char* p = strSrc;
  while (p && p < strSrcEnd) {
    p = strstr(p, strFnd);
    if (p) {
      count++;
      p += fndLen;
    }
  }
  return count;
}
void ignorflagIinO(char* arr, char* buf, int* mas_of, char* arrcopy,
                   char* arrbuf) {
  int n1 = strlen(arr);
  int n2 = strlen(buf);
  for (int i = 0; i < n1 - 1; i++) {
    int t = (int)arr[i];
    if (t >= 97) {
      arrcopy[i] = t - 32;
    } else {
      arrcopy[i] = t;
    }
  }
  for (int i = 0; i < n2 - 1; i++) {
    int t = (int)buf[i];
    if (t >= 97) {
      arrbuf[i] = t - 32;
    } else if (t == '\n') {
      arrbuf[i] = '\0';
    } else {
      arrbuf[i] = t;
    }
  }
  int ofik[2] = {0};
  if (n1 - 1 >= n2 - 1 || n1 - 1 >= ofik[1]) {
    strstr1(arrcopy, arrbuf, mas_of, ofik);
  }
}
int strstr1(const char* arr, const char* buf, int* mas_of, int* ofik) {
  int t = 0;
  int n1 = strlen(arr);
  int n2 = strlen(buf);
  for (int i = 0; i <= n1; i++) {
    if (buf[0] == arr[i]) {
      int k = 0;
      for (int j = 0; j < n2; j++) {
        if (buf[j] == arr[j + i]) {
          k = k + 1;
        }
      }
      ofik[0] = t;
      mas_of[t] = i;
      t++;
      if (k == n1) {
        i = i + k;
      }
    }
  }
  return (0);
}
