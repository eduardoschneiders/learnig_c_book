#include <stdio.h>

int main(){
  int c, b, t, n;
  b = t = n = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ')
      b++;
    else if (c == '\t')
      t++;
    else if (c == '\n')
      n++;
  }

  printf("\nb: %d, t: %d, n: %d\n", b, t, n);

  return 0;
}