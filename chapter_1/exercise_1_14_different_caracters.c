#include <stdio.h>
#define TOTAL_CHARS ('z' - ' ') //122 - 32

int main() {
  int chars[TOTAL_CHARS];
  int c;

  for (int i = 0; i < TOTAL_CHARS; i++)
    chars[i] = 0;

  while ((c = getchar()) != EOF) {
    chars[c - ' ']++;
  }

  for (int i = 0; i < TOTAL_CHARS; i++){
    printf("%c: %d ", (char)i + ' ', chars[i]);

    for (int j = 0; j < chars[i]; j++) {
      putchar('=');
    }

    putchar('\n');
  }
}

// [a,b..x,y,zA,B,C...X,Y,Z]