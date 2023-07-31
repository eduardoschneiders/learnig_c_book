#include <stdio.h>
#define TAB_STOPS 4
int get_text(char line[]);

int main() {
  int lenght = 0;
  // char text[15] = "abcd\t1\t";
  char text[1000] = "abcd\t1\t\teduardo";
  char new_text[1000] = "";
  int c = '\0';

  int i;
  int new_text_i;

  for (i = new_text_i = 0; (c = text[i]) != '\0'; i++) {
    if (c == '\t') {
      int missing = TAB_STOPS - (new_text_i % TAB_STOPS);

      for (int j = 0; j < missing; j++) {
        new_text[new_text_i++] = ' ';
      }
    } else {
      new_text[new_text_i++] = c;
    }
  }

  new_text[new_text_i++] = '\0';

  printf("\nText: \n%s\n", new_text);
}

int get_text(char line[]) {
  int c;
  int lenght = 0;


  printf("Text: \n");

  while ((c = getchar()) != EOF)
    if (c == '\t') {
      for (int i = 0; i < 4; i++) {
        line[lenght++] = ' ';
      }
    } else
      line[lenght++] = c;

    if (lenght > 0)
      line[lenght++] = '\0';

    return lenght;
}

// 1234\t5678\n
// \t\t23\t12355\n

// 1234    5678
//         2345 12355
