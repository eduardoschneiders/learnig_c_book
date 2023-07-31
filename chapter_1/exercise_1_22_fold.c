#include <stdio.h>
#define MAX_LENGTH 10
#define FALSE 0

int next_word_lenght(char text[], int i);

int main() {
  char text[100] = "eduardo matheus Schneiders foobar wert wertertr ertertwetaa";
  char c = '\0';
  int i_from_begin = 0;
  int next_lenght = 0;
  int next_word_fits = FALSE;
  int is_last_space = FALSE;
  int should_break_line = FALSE;

  for (int i = 0; (c = text[i]) != '\0'; i++) {
    next_lenght = next_word_lenght(text, i + 1);
    next_word_fits = (next_lenght + i_from_begin) <= MAX_LENGTH;
    is_last_space = i_from_begin >= MAX_LENGTH;
    should_break_line = (c == ' ' && is_last_space) || (c == ' ' && !next_word_fits);

    if (should_break_line) {
      putchar('\n');
      i_from_begin = 0;
    } else {
      i_from_begin++;
      putchar(c);
    }
  }
}

int next_word_lenght(char text[], int i) {
  int lenght = 0;
  char c = '\0';

  while ((c = text[i++]) != ' ' && c != '\0')
    lenght++;

  return lenght;
}
