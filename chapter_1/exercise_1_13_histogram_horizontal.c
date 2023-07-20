#include <stdio.h>

int main() {
  int c, counter;
  counter = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n'|| c == '\t' || c == ' ')
      putchar('\n');
    else
      putchar('=');
  }
}