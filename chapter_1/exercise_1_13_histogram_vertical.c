#include <stdio.h>
#define MAX_COUNTS 10

int main() {
  int c, letter_counter, word_counter;
  letter_counter = word_counter = 0;
  int word_counts[MAX_COUNTS];

  for (int i; i < MAX_COUNTS; i++)
    word_counts[i] = 0;

  while ((c = getchar()) != EOF){
    if (c != '\n' && c != '\t' && c != ' ')
      letter_counter++;
    else{
      word_counts[word_counter] = letter_counter;
      word_counter++;
      letter_counter = 0;
    }
  }

  int max_lines = 0;
  for (int i = 0; i < MAX_COUNTS; i++) {
    if (word_counts[i] > max_lines)
      max_lines = word_counts[i];
  }

  for (int line = 0; line < max_lines; line++) {
    for (int col = 0; col < word_counter; col++) {
      if (word_counts[col] > line)
        printf("= ");
      else
        printf("  ");
    }

    putchar('\n');
  }
}