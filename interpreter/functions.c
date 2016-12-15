#include<math.h>
#include<stdlib.h>
#include "functions.h"

double stod(char str[]) {
  int length = 0;
  int i = 0;
  while(str[i] != '\0') {
    i++;
    length++;
  }
  bool decimal = false;
  double n = 0;
  double power = 1;
  if(str[0] == '-')
    i=1;
  else
    i=0;
  for(;i<length;i++) {
    if(str[i] == '.') {
      decimal = true;
      power = 10;
      continue;
    }
    if(decimal) {
      n = n + (str[i] - '0')/power;
      power = power*10;
    } else {
      n = n*10 + (str[i] - '0');
    }
  }
  if(str[0] == '-')
    n*=(-1);
  return n;
}

SplitString split(char str[], char delim) {
  int length = 0;
  int i=0;
  while(str[i] != '\0') {
    i++;
    length++;
  }
  SplitString splitstr;
  splitstr.length = 0;
  int runcount = 0;
  for(i=0;i<length;i++) {
    if(str[i] == ' ') {
      int j;
      for(j=runcount;j<i;j++) {
	splitstr.array[splitstr.length][j-runcount] = str[j];
      }
      splitstr.array[splitstr.length][j-runcount] = '\0';
      runcount = i+1;
      splitstr.length++;
    }
  }

  int j;
  for(j=runcount;j<i-1;j++) {
    splitstr.array[splitstr.length][j-runcount] = str[j];
  }
  splitstr.array[splitstr.length][j-runcount] = '\0';
  runcount = i+1;
  splitstr.length++;

  return splitstr;
}
