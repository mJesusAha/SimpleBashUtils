#include "cat.h"

int main(int argc, char *argv[]) {
  if (argc > 1) {
    scanFlagDoc(argc, argv);
  } else {
    printf("\nusage: cat [-belnstuv] [file ...]");
  }
  return 0;
}
int scanFlagDoc(int argc, char *argv[]) {
  char simbols[1024] = {0};
  int masflag[30] = {0};
  char masdoc[256][256] = {0};
  int t1 = 0;
  for (int i = 1; i < argc; i++) {
    for (int j = 0; argv[i][j] != '\0'; j++) {
      simbols[j] = argv[i][j];
    }
    if (simbols[0] == '-') {
      if (masFlagOpred(simbols, masflag) < 0) {
        printf("cat: illegal option -- ");
        for (int j = 1; simbols[j] != '\0'; j++) {
          printf("%c", simbols[j]);
        }
        printf("\nusage: cat [-belnstuv] [file ...]");
        exit(1);
      }
    } else {
      file_exists(simbols);
      if (file_exists(simbols) == 1) {
        for (int j = 0; j < 256; j++) {
          masdoc[t1][j] = simbols[j];
        }
        t1++;
      } else {
        printf("%s: No such file or directory", simbols);
      }
    }
    clearMass(simbols);
  }

  char arfil[256] = {0};
  for (int i = 0; i < t1; i++) {
    for (int j = 0; masdoc[i][j] != '\0'; j++) {
      arfil[j] = masdoc[i][j];
    }
    read_file(arfil, masflag);
  }
  return 0;
}
int masFlagOpred(char *flag, int *mfl) {
  const char fl[] = "ebnstvET";
  int lenflag = strlen(flag) - 1;
  int p = 0;
  int counter = sum(mfl);
  int b = 2, n = 3, s = 4;
  char fb[] = "--number-nonblank";
  char fn[] = "--number";
  char fs[] = "--squeeze-blank";
  for (int i = 1; flag[i] != '\0'; i++) {
    for (int j = 0; fl[j] != '\0'; j++) {
      if (flag[i] == fl[j]) {
        p++;
      }
    }
  }
  if (lenflag == p) {
    int e = 1, t = 5, v = 6, ev = 7,
        tv = 8;  //  Eсли перечисленные флаги совпали по списку то делаем
    for (int i = 1; flag[i] != '\0'; i++) {
      if (flag[i] == 'E') {
        mfl[e] = e;
      } else if (flag[i] == 'b') {
        mfl[b] = b;
      } else if (flag[i] == 'v') {
        mfl[v] = v;
      } else if (flag[i] == 'n') {
        mfl[n] = n;
      } else if (flag[i] == 's') {
        mfl[s] = s;
      } else if (flag[i] == 't') {
        mfl[t] = t;
      } else if (flag[i] == 'e') {
        mfl[ev] = ev;
      } else if (flag[i] == 'T') {
        mfl[tv] = tv;
      }
    }
  } else if (flag[1] == '-') {
    int lenb = strlen(fb);
    int lenn = strlen(fn);
    int lens = strlen(fs);
    int tb = 0, tn = 0, ts = 0;
    for (int i = 0; flag[i] != '\0'; i++) {
      if (flag[i] == fb[i]) {
        tb++;
      }
      if (flag[i] == fn[i]) {
        tn++;
      }
      if (flag[i] == fs[i]) {
        ts++;
      }
    }
    int lenflag1 = strlen(flag);
    if (lenflag1 == tb && tb == lenb) {
      mfl[b] = b;
    } else if (lenflag1 == ts && ts == lens) {
      mfl[s] = s;
    } else if (lenflag1 == tn && tn == lenn) {
      mfl[n] = n;
    } else {
      counter = -1;
    }
  } else {
    counter = -1;
  }
  return counter;
}
int sum(const int *masflag) {
  int sum = 0;
  for (int i = 0; masflag[i] > 0; i++) {
    sum++;
  }
  return sum;
}
/////////  ФУНКЦИИ РАБОТЫ С ФАЙЛАМИ/////////
int file_exists(char *filename) {
  int t = 0;
  FILE *file;
  file = fopen(filename, "r");
  if (file) {
    fclose(file);
    t = 1;
  }
  return t;
}
void read_file(char *masdoc, int *masflag) {
  FILE *file;
  char arr[1024] = {0}, buf[1024] = {0};
  int s = 0, b = 0;
  file = fopen(masdoc, "r");
  while (!feof(file)) {
    fgets(arr, 500, file);
    for (int i = 0; i < 1024; i++) {
      buf[i] = arr[i];
    }
    int k = masNULL(arr);
    if ((k == 0 && arr[0] != 0) || k > 0) {
      for (int i = 0; i < k + 1; i++) {
        flagV(i, k, arr, buf, masflag);
      }
      if (masflag[4] == 4) {
        if (arr[0] != '\n') s = 0;
      }
      if (((masflag[2] == 2 && masflag[3] == 3) ||
           (masflag[2] == 2 && masflag[3] != 3)) &&
          s == 0) {
        if (arr[0] != '\n' && arr[0] != '\0') {
          b++;
          printf("%6d\t", b);
        }
      }
      if (masflag[3] == 3 && masflag[2] != 2 && s == 0 && arr[0] != '\0') {
        b++;
        printf("%6d\t", b);
      }
      for (int i = 0; i < k + 1; i++) {
        if (s == 0) {
          if (masflag[7] == 7 || masflag[1] == 1) {
            if (masflag[2] == 2 && arr[0] == '\n') {
              printf("      \t");
            }
            if (arr[i] == '\n' && arr[0] != '\n') {
              printf("$");
            } else if (arr[0] == '\n') {
              printf("$");
            }
          }
          if ((masflag[1] == 1 || masflag[5] == 5 || masflag[6] == 6 ||
               masflag[7] == 7 || masflag[8] == 8) &&
              arr[i] != buf[i]) {
            printf("^%c", buf[i]);
          } else {
            printf("%c", buf[i]);
          }
        }
      }
      if (masflag[4] == 4) {
        if (arr[0] == '\n') {
          s = 1;
        } else {
          s = 0;
        }
      }
    }
    clearMass(arr);
    clearMass(buf);
  }
  fclose(file);
}
void clearMass(char *massiv) {
  for (int i = 0; i < 1024; i++) massiv[i] = 0;
}
int masNULL(const char *arr) {
  int k = 0;
  for (int i = 0; i < 300; i++) {
    if (arr[i] >= 1 && arr[i] < 127 && k < i) {
      k = i;
    }
  }
  return k;
}
void flagV(int i, int k, const char *arr, char *buf, const int *masflag) {
  if (masflag[6] == 6 || masflag[7] == 7 || masflag[5] == 5) {
    if (arr[i] > 0 && arr[i] <= 32 && arr[i] != ' ' && arr[i] != '\n' &&
        arr[i] != 9)
      buf[i] = buf[i] + 64;
    if (arr[i] == 127) buf[i] = '?';
    if (arr[i] == '\0' && i != k) buf[i] = buf[i] + 64;
  }
  if ((masflag[5] == 5 || masflag[8] == 8) && arr[i] == '\t') buf[i] = 'I';
}
