#include <stdio.h>
#define TAB_STOPS 4
#define TRUE 1
#define FALSE 0


int main() {
  printf("\ta\tb\tc\td\te\n");
  // char text[1000] = "        a   c";
  char text[1000] = "asdf    a  b";
  int c = '\0';

  int i = 0;
  int spaces_buffer = 0;
  int tabs_count = 0;
  int is_tab_stop = FALSE;

  for (int i = 0;(c = text[i]) != '\0'; i++) {
    if (c == ' ') {
      spaces_buffer++;
      is_tab_stop = i % TAB_STOPS == 3;

      if (is_tab_stop) {
        if (spaces_buffer > 1)
          putchar('\t');
        else
          putchar(' ');

        spaces_buffer = 0;
      }
    } else {
      if (spaces_buffer) {
        for (int j = 0; j < spaces_buffer; j++) {
          putchar(' ');
        }

        spaces_buffer = 0;
      }

      putchar(c);
    }
  }

  printf("\nEND\n");
}

// detect 2+ spaces => its a tab
  // if it's tabstop put tab
  //     clear whitespaces buffer
  // [' ', ' ', ' ', ' ', 'a']