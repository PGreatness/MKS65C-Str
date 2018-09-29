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

int myStrcmp(char *s1, char *s2) {
  char * first = s1;
  char * second = s2;
  while(*first++) {
    if (*second++ == '\0') {
      return 99;
    }
  }
  if (*second++ != '\0') {
    return -99;
  }else{
    return 0;
  }
}

char * myStrchar(char * location, char wanted) {
  while (*location++) {
    if (*location == wanted) {
      return location;
    }
  }
  return NULL;
}



int main() {
  char len[] = "Hello";
  char str[] = "Hello";
  char ert[] = "Person";
  printf("length is %i\n", myStrlen(len));
  // printf("cpy %p, %s\n", myStrcpy(len, str), len);
  printf("Compare: %s to %s,  %i\n        %s to %s, %i\n",
	 len, str, myStrcmp(len, str), str, ert, myStrcmp(str, ert));
   printf("Str char: where does %s have %c?\n%c is at: %p\n actual location: %p\n",
          ert, 's', 's', myStrchar(ert, 's'), strchr(ert, 's'));
  
  return 0;
}
