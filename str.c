#include <string.h>
#include <stdio.h>
#include "str.h"

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
* Overwrites dest with source up until limit, source unaffected
*/
char * myStrncpy(char * dest, char * source, int limit) {
  int i =0;
  while(*dest && i < limit) {
    *dest++ = *source++;
    i++;
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
* Concatenates entire source to dest, source unaffected
*/
char * myStrcat(char * dest, char * source) {
  int length = myStrlen(source);
  return myStrncat(dest, source, length);
}

/*
* Concatenates source(up to n) to dest, source unaffected
*/
char * myStrncat( char *dest, char *source ,int n){
  char *arr=dest;
  while(*dest!= '\0'){
    dest++;
  }
  int i=0;
  while(*source !='\0' && i<n){
    *dest=*source;
    dest++;
    source++;
    i++;
  }
  *dest='\0';
  return arr;
}

/*
* Checks if s2 exists within s1, s2 unaffected
*/
char * myStrstr(char *s1, char *s2 ){
  if(strlen(s1)<strlen(s2)){//s2 cannot exist in s1 if s2 is larger
    return NULL;
  }

  while(*s1){//checks location of s1 
        char *pos1=s1;//holds value of s1 before changes 
        char *pos2=s2;//holds value of s2 before changes
        while(*s1 && *pos2 && *s1== *pos2){//s1 and pos2 string must have not terminated and they must match 
          *s1++;//moves value of s1 
          *pos2++;//moves value of pos2
        }
        if(!*pos2){//if string has been matched
            return pos1;//returns beginning of string at s1(pos1)
          }
        s1=pos1+1;//moves value of original string to start from
  }
  return NULL;//s2 not in s1 
}
/*char * myStrstr(char * str_to_search, char * wanted_str ){
  char * first_occurence = myStrchar(str_to_search, *wanted_str); //first place that wanted_str shows up, lets us forget about prev stuff
  int i =0; //avoids changing first_occurence address
  for (; wanted_str[i]; i++) { //while (wanted_str[i] != '\0') { ... i++ }
    if (first_occurence[i] != wanted_str[i]) {  //there is a mismatch, first_occurence doesn't have the string
      return myStrstr(first_occurence + 1, wanted_str); //starts from the second occurence of the first character in wanted_str
    }
  }
  return first_occurence; //location of first_occurence never changes from the location of the first occurence of the wanted_str, so first_occurence can be returned

} */

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
  char place[]="Hell";
  printf("cat: %s is appended to %s, to %d letters, resulting in %s\n",verb,"cat",4, myStrncat(animal,verb,4));
  printf("str str: %s is found in %s, location %p but real location %p", place,str, myStrstr(str,place), strstr(str,place));
    char first[] = "cat";
  char second[] = "HelloCatit\'sme, a cat";
  printf("Does string %s exist in %s ? Yes, at %p          actual is at %p\n", first, second, myStrstr(second, first), strstr(second, first));
  return 0;
}
