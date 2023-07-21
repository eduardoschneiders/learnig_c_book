#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define MINIMUM_LINE_LENGHT 80

int fetch_line(char line[MAXLINE]);
int is_valid_char(int c, int last_char);
int is_double_space(int c, int last_char);
int is_tab(int c);
int is_empty_line(int c, int last_char);

int main() {
  char line[MAXLINE];
  int lenght;

  while ((lenght = fetch_line(line)) != 0)
    printf("%s\n", line);
}

int fetch_line(char line[MAXLINE]) {
  int c;
  int lenght = 0;
  int last_char = '\0';

  while ((c = getchar()) != EOF && c != '\n')
    if (is_valid_char(c, last_char))
      line[lenght++] = last_char = c;

  line[lenght++] = '\0';

  return lenght;
}

int is_valid_char(int c, int last_char) {
  return !is_double_space(c, last_char) && !is_tab(c) && !is_empty_line(c, last_char);
}

int is_double_space(int c, int last_char) {
  return c == ' ' && last_char == ' ';
}

int is_tab(int c) {
  return c == '\t';
}

int is_empty_line(int c, int last_char) {
  return (last_char == '\0' && c == '\n') && last_char == '\n' && c == '\n';
}


