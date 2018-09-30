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
  char * placeholder = dest;
  while(*dest) { //check current val of dest
    *dest++ = *source++; //change dest val to source val then increment both
  }
  return placeholder;
}

/*
* Overwrites dest with source up until limit, source unaffected
*/
char * myStrncpy(char * dest, char * source, int limit) {
  char * placeholder = dest;
  int i =0;
  while(*dest && i < limit) {
    *dest++ = *source++;
    i++;
  }
  return placeholder;
}

/*
* Compares s1 and s2, both unaffected
*/
int myStrcmp(char *s1, char *s2) {
  while( 1 ) { //while (true) { ... }
    if (*s1 > *s2) {
      return 99;
    }
    if (*s1 < *s2) {
      return -99;
    }
    //if none of the above, increment both to check next val
    s1++;
    s2++;
  }
  return 0;
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
  char s1[] = "Hello";
  char s2[] = "Hello";
  char s3[] = "Person";
  char s4[] = "Person";
  char s5[] = "Concatenation";
  char s6[] = "Puppy";
  char s7[] = "Concatenation";
  char s8[] = "Puppy";
  char s9[] = "Good person Phillip";
  char s10[] = "Good person phiLip!";
  char s11[] = "Moth memes are lighting the world's mind up to its tragic story. Change my mind";
  char s12[] = "Tide pods amirite?";
  char s13[] = "The quick brown fox";
  char s14[] = " made friends with the nice man with ice cream.";
  char s15[] = "The quick brown fox ";
  char s16[] = "made friends with the nice man with ice cream.";
  char s17[] = "Angry YouTube comments.";
  char s18[] = " Angry YouTube comments everywhere <:(";
  char s19[] = "Angry YouTube comments.";
  char s20[] = " Angry YouTube comments everywhere <:(";
  char s21[] = "Feels like the TSA for some odd reason...";
  char s22[] = "A quick brown fox laid a pretty nice trap.";

  printf("----------------------------String Length--------------------\nString to be measured: \"%s\"\n[Mine]: %i\n[Actual]: %li\n", s1, myStrlen(s1), strlen(s1));
  printf("---------------------------String copy-----------------------\nString to be copied: String \"%s\" copied over to string \"%s\"\n[Mine]: \"%s\"\n[Actual]: \"%s\"\n", "Person", "Hello", myStrcpy(s3, s1), strcpy(s4, s2));
  printf("---------------------------String copy (numbered)------------\nString \"%s\" copied over to \"%s\" up until the letter at index %i of \"%s\"\n[Mine]: \"%s\"\n[Actual]: \"%s\"\n", "Concatenation", "Puppy", 4, "Concatenation", myStrncpy(s5, s6, 4), strncpy(s7, s8, 4));
  printf("--------------------------String Comparisons-----------------\nStrings to be compared: \"%s\" and \"%s\", then \"%s\" and \"%s\"\nIf \"%s\" is greater, returns a positive number, else returns a negative number.\nEqual returns a zero(0).\n[Mine]: %i\n[Actual]: %i\nIf \"%s\" is greater, returns a positive number, else returns a negative number.\nEqual returns a zero(0).\n[Mine]: %i\n[Actual]: %i\n", s9, s10, s5, s7, s9, myStrcmp(s9, s10), strcmp(s9, s10), s5, myStrcmp(s5, s7), strcmp(s5, s7));
  printf("---------------------String Search (single character)-----------------\nString to search: \"%s\". We shall look for this character: \"%s\"\n[Mine]: Is this the character? \"%s\"\nWe found it at %p\n[Actual]: This is the character: %s.\nIt was found at %p\n\nLet's go on a wild goose chase with \"%s\" and tell them to look for \"%s\"  :3\n[Mine]: What a joker. We found this \"%s\" at \"%p\". Nice going. >:(\n[Actual]: This search system is either looking for what doesn\'t exist or \nthe person is an idiot. We found \"%s\" at \"%p\"\n", s11, "d", myStrchar(s11, *"d"), myStrchar(s11, *"d"), strchr(s11, *"d"),strchr(s11, *"d"), s12, "!", myStrchar(s12, *"!"), myStrchar(s12, *"!"), strchr(s12, *"!"), strchr(s12, *"!"));
  printf("-------------------String Concatenation----------------------------\nStrings to join together: \"%s\" and \"%s\", with \"%s\" leading.\n[Mine]: %s\n[Actual]: %s\n", "The quick brown fox", " made friends with the nice man with ice cream.", "The quick brown fox", myStrcat(s13, s14), strcat(s15, s16));
  printf("-------------------String Concatenation (with limit)-----------------\nStrings to join together: \"%s\" and \"%s\", with \"%s\" leading.\nThis will add %i characters of \"%s\".\n[Mine]: %s\n[Actual]: %s\n", "Angry YouTube comments.", " Angry YouTube comments everywhere <:(", "Angry YouTube comments.", 5, " Angry YouTube comments everywhere <:(", myStrncat(s17, s18, 5), strncat(s19, s20, 5));
  printf("\n\nWARNING WARNING WARNING WARNING WARING WARNING WARNING WARNING WARNING WARNING WARNING WARNING\nEXTRA BOSS APPROACHING EXTRA BOSS APPROACHING EXTRA BOSS APPROACHING EXTRA BOSS APPROACHING\n");
  printf("------------------String Search (entIRE STRINGS!!!!!)----------------\nString to be searched: \"%s\" will be searched for \"%s\". Let's see what happens.\n[Mine]: We found it! It is \"%s\" at over here right? %p\n[Actual]: ACKCHYUALLY... it is \"%s\" at %p\n[Mine]: It's the same thing.\n[Actual]: ...\n\nWho said a joke done once isn\'t funny? Time to fake them out:33333\nEveryone! Look for \"%s\" in \"%s\". Do. Now.\n[Mine]: Really, again? Uggghh. Look, we found \"%s\" at %p. Can we stop now?\n[Actual]: I second that. There was \"%s\" at %p. I\'m bored, I quit.\n[Mine]: Same.\n(Both leaves)\n\n<:(((( ", s21, "reason", myStrstr(s21, "reason"), myStrstr(s21, "reason"), strstr(s21, "reason"), strstr(s21, "reason"),"mankind", s22, myStrstr(s22, "mankind"), myStrstr(s22, "mankind"), strstr(s22, "mankind"), strstr(s22, "mankind") );
  return 0;
}
