#include <stdio.h>
#define OUTSIDE_COMMENT 0
#define CHECKING_STATUS 1
#define INSIDE_COMMENT 2
#define INSIDE_MULTILINE_COMMENT 3
#define INSIDE_STRING 4
#define OUTSIDE_STRING 5
#define FALSE 0
#define TRUE 1

// comments
/* comments */
/* comments
  comments
*/
// printf("text // text")
// printf("text /*comment*/ text")

// comment
int foo = 0; // comment
int bla = /* comments */ 1;
/* comments
  comments
*/
int blo = 0;

int main() {
  // char text[100] = "eduardo matheus Schneiders foobar wert wertertr ertertwetaa";
  // char text[100] = "eduardo matheus Schneiders 1 / 2 foobar wert wertertr ertertwetaa // comment";
  // char text[100] = "int foo = 0; // comment";
  // char text[100] = "int bla = /* comments */1;";
  // char text[100] = "bla // comment\nfoo";
  // char text[100] = "int a = 1;\n/*comment*/";
  // char text[100] = "/*comment\nallala*/eduardo\n";
  char text[100] = "print(\"foobar//asdf/*asdf*/\"); /*comment*/ int i = 0;//comment";
  char c = '\0';
  char last_c = '\0';
  int status = OUTSIDE_COMMENT;
  int inside_string = FALSE;


  for (int i = 0; (c = text[i]) != '\0'; i++) {

    if (inside_string) {
      if (c == '\"')
        inside_string = FALSE;
    } else if (status == OUTSIDE_COMMENT) {
      if (c == '\"') {
        inside_string = TRUE;
      } else if (c == '/')
        status = CHECKING_STATUS;
    } else if (status == CHECKING_STATUS) {
      if (c == '/')
        status = INSIDE_COMMENT;
      else if (c == '*')
        status = INSIDE_MULTILINE_COMMENT;
      else {
        status = OUTSIDE_COMMENT;
        putchar(last_c);
      }
    } else if (status == INSIDE_COMMENT) {
      if (c == '\n')
        status = OUTSIDE_COMMENT;
    } else if (status == INSIDE_MULTILINE_COMMENT) {
      if (last_c == '*' && c == '/') {
        status = OUTSIDE_COMMENT;
        continue;
      }
    }

    last_c = c;

    if (status == OUTSIDE_COMMENT)
      putchar(c);
  }
}

// comment

// start OUTSIDE_COMMENT

// for each letter
  // if OUTSIDE_COMMENT
    // if c == /
      // status CHECKING

  // if c == / && status CHECKING
    // status = INSIDE COMMENT
  //  else
    // status = OUTSIDE_COMMENT
    // print last_c


  // else status == INSIDE_COMMENT
    // check way out

  // update last_c