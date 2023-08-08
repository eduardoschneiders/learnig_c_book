#include <stdio.h>

int main() {

  enum { FALSE = 0, TRUE = 1 };

  int lim = 10;
  int i = 0;
  char c;
  char s[15];
  int loop = TRUE;

  // for (int i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    // s[i] = c;

  while (loop) {
    c = getchar();

    if (i >= lim - 1)
      loop = FALSE;

    if (c == '\n')
      loop = FALSE;

    if (c == EOF)
      loop = FALSE;


    s[i++] = c;
  }


  printf("%s\n", s);

  return 0;
}
