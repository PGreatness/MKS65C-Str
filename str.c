#include <string.h>
#include <stdio.h>

int myStrlen(char * len) {
  int runSum = 0;
  while (*len++) {
    runSum++;
  }
  return runSum;
}

char * myStrcpy(char * dest, char * source) {
  char retChar[256];
  int i =0;
  for (; ; *dest++) {
    retChar[i] = *dest;
    i++;
  }
  for (; ;*source++) {
    retChar[i] = *source;
    i++;
  }
  
  return retChar;
}

int main() {
  char len[10] = "Hello";
  char str[5] = "Hello";
  printf("length is %i\n", myStrlen(len));
  printf("cpy %p, %s\n", myStrcpy(len, str), len);
  return 0;
}
