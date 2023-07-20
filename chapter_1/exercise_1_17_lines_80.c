#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define MINIMUM_LINE_LENGHT 80

int fetch_line(char line[MAXLINE]);

int main() {
  char line[MAXLINE];
  int lenght;

  while ((lenght = fetch_line(line)) != 0)
    if (lenght >= MINIMUM_LINE_LENGHT)
      printf("%s\n", line);
}

int fetch_line(char line[MAXLINE]) {
  int c;
  int lenght = 0;

  while ((c = getchar()) != EOF && c != '\n')
    line[lenght++] = c;

  line[lenght++] = '\0';

  return lenght;
}

