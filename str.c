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
} //end myStrlen(char *)

/*
* Overwrites dest with source, source unaffected
*/
char * myStrcpy(char * dest, char * source) {
  while(*dest) { //check current val of dest
    *dest++ = *source++; //change dest val to source val then increment both
  }
  return dest;
} //end myStrcpy(char *, char *)

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
} //end myStrcmp(char *, char*)

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
} //end myStrchar(char *, char *)

/*
* Concatenates source to dest, source unaffected
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
} //end myStrcat(char *, char *, int)

/*
* Searches str_to_search for wanted_str, both unaffected. Returns pointer
*/
char * myStrstr(char * str_to_search, char * wanted_str ){
  char * first_occurence = myStrchar(str_to_search, *wanted_str); //first place that wanted_str shows up, lets us forget about prev stuff
  int i =0; //avoids changing first_occurence address
  for (; wanted_str[i]; i++) { //while (wanted_str[i] != '\0') { ... i++ }
    if (first_occurence[i] != wanted_str[i]) {  //there is a mismatch, first_occurence doesn't have the string
      return myStrstr(first_occurence + 1, wanted_str); //starts from the second occurence of the first character in wanted_str
    }
  }
  return first_occurence; //location of first_occurence never changes from the location of the first occurence of the wanted_str, so first_occurence can be returned

} //end myStrstr(char *, char *)

int main() {
  //need better test cases
  char len[] = "Hello";
  char str[] = "Hello";
  char ert[] = "Person";
  printf("length is %i\n", myStrlen(len) );
  printf("Compare: %s to %s,  %i\n", len, str, myStrcmp(len, str));
  printf("cpy:at %p, len is now %s\n", myStrcpy(len, ert), len );
  printf("Str char: where does %s have %c?\n%c is at: %p\n actual location: %p\n",
          ert, 's', 's', myStrchar(ert, 's'), strchr(ert, 's'));
  char animal[]="cat";
  char verb[]="fishing";
  printf("cat: %s is appended to %s, to %d letters, resulting in %s\n",verb,"cat",4, myStrncat(animal,verb,4));
  char first[] = "cat";
  char second[] = "HelloCatit\'sme, a cat";
  printf("Does string %s exist in %s ? Yes, at %p          actual is at %p\n", first, second, myStrstr(second, first), strstr(second, first));
  return 0;
}
