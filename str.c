#include <string.h>
#include <stdio.h>

/*
* Returns length, len unaffected
*/
int myStrlen(char * len) {
  int runSum = 0; 
  while (*len++) { //progress down the char array
    runSum++; 
  }
  return runSum;
}

/*
* Overwrites dest with source, source unaffected
*/
char * myStrcpy(char * dest, char * source) {
  while(*dest) { //check current val of dest
    *dest++ = *source++; //change dest val to source val then increment both
  }
  return dest;
}

/*
* Compares s1 and s2, both unaffected
*/
int myStrcmp(char *s1, char *s2) {
  while( 1 ) { //while (true) { ... }
    if (*s1 == '\0' && *s2 == '\0') { //both terminated at the same time
      return 0;
    }
    if (*s1 == '\0') { //s1 is smaller than s2
      return -99;
    }
    if (*s2 == '\0') { //s2 is smaller than s1
      return 99;
    }
    //if none of the above, increment both to check next val
    s1++;
    s2++;
  }
}

/*
* Searches location for wanted, both unaffected
*/
char * myStrchar(char * location, char wanted) {
  while (*location) { //check current val of location
    if (*location == wanted) { //wanted is the val of current location
      return location; //return current location
    }
    location++; //curr val of location isn't wanted, move along
  }
  return NULL; //wanted not in location
}
/*
* Concatenates source to dest, source unaffected
*/
char * myStrncat( char *dest, char *source ,int n){
  int high=strlen(dest);
  int i=0;
  for(;i<n;i++){
    dest[high+i]=source[i];
    printf("%s\n",dest);
  }
  return dest;
}


int main() {
  //need better test cases
  char len[] = "Hello";
  char str[] = "Hello";
  char ert[] = "Person";
  printf("length is %i\n", myStrlen(len) );
  printf("Compare: %s to %s,  %i\n", len, str, myStrcmp(len, str));
  printf("cpy:at %p, len is now %s\n", myStrcpy(len, ert), len );
  printf("Str char: where does %s have %c?\n%c is at: %p\n actual location: %p\n\n",
          ert, 's', 's', myStrchar(ert, 's'), strchr(ert, 's'));
  char animal[]="cat";
  char verb[]="fishing";
  printf("cat: %s is appended to %s, to %d letters, resulting in %s\n",verb,"cat",4, strncat(animal,verb,4));
  return 0;
}
