#ifndef SRC_CAT_CAT_H_
#define SRC_CAT_CAT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scanFlagDoc(int argc, char *argv[]);  //  scan doc and flag
int masFlagOpred(char *flag, int *mfl);
int sum(const int *masflag);
int file_exists(char *filename);
void read_file(char *masdoc, int *masflag);
void clearMass(char *massiv);
void flagV(int i, int k, const char *arr, char *buf, const int *masflag);  // No
int masNULL(const char *arr);

#endif  // SRC_CAT_CAT_H_
