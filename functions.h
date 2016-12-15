#pragma once

#include<math.h>
#include<stdlib.h>
#define bool int
#define true 1
#define false 0

double stod(char str[]);
typedef struct _SplitString {
  char array[10][50];
  int length;
} SplitString;

SplitString split(char str[], char delim);
