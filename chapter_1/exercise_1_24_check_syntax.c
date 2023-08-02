#include <stdio.h>
#define OUTSIDE_COMMENT 0
#define CHECKING_STATUS 1
#define INSIDE_COMMENT 2
#define INSIDE_MULTILINE_COMMENT 3
#define INSIDE_STRING 4
#define OUTSIDE_STRING 5
#define FALSE 0
#define TRUE 1

int main() {
  // char text[100] = "printf(\"correct\")";
  // char text[100] = "printf(\"correct\")";
  char text[100] = "printf(\"wrong\"";
  char c = '\0';
  char last_c = '\0';
  int status = OUTSIDE_COMMENT;
  int inside_string = FALSE;

  int parentheses = 0;
  int brackets = 0;
  int braces = 0;


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

    if (status == OUTSIDE_COMMENT) {
      if (c == '(')
        parentheses++;
      else if (c == ')')
        parentheses--;

      if (c == '[')
        brackets++;
      else if (c == ']')
        brackets--;

      if (c == '{')
        braces++;
      else if (c == '}')
        braces--;

      putchar(c);
    }
  }

  printf("\nparentheses: %d, brackets: %d, braces: %d\n", parentheses, brackets, braces);
  if (parentheses || brackets || braces)
    printf("parentheses || brackets || braces don't match");
}
