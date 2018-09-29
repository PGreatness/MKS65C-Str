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
  while(*dest) {
    *dest++ = *source++;
  }
  return dest;
}

int myStrcmp(char *s1, char *s2) {
  while( 1 ) {
    if (*s1 == '\0' && *s2 == '\0') {
      return 0;
    }
    if (*s1 == '\0') {
      return -99;
    }
    if (*s2 == '\0') {
      return 99;
    }
    s1++;
    s2++;
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
  printf("length is %i\n", myStrlen(len) );
  printf("Compare: %s to %s,  %i\n", len, str, myStrcmp(len, str));
  printf("cpy:at %p, len is now %s\n", myStrcpy(len, ert), len );
  printf("Str char: where does %s have %c?\n%c is at: %p\n actual location: %p\n",
          ert, 's', 's', myStrchar(ert, 's'), strchr(ert, 's'));
  
  return 0;
}
