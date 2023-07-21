#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define MINIMUM_LINE_LENGHT 80

int fetch_line(char line[MAXLINE]);
void print_reversed(char line[MAXLINE], int lenght);
void reverse(char line[MAXLINE], int lenght);

int main() {
  char line[MAXLINE];
  int lenght;

  while ((lenght = fetch_line(line)) != 0) {
    printf("\nNormal: ");
    printf("%s\n", line);

    reverse(line, lenght);

    printf("\nReversed: ");
    printf("%s\n", line);
    // print_reversed(line, lenght);
  }
}

int fetch_line(char line[MAXLINE]) {
  int c;
  int lenght = 0;

  while ((c = getchar()) != EOF && c != '\n')
    line[lenght++] = c;

  line[lenght++] = '\0';

  return lenght;
}

void print_reversed(char line[], int lenght) {
  for (int i = lenght - 2; i >= 0; i--)
    putchar(line[i]);
}

void reverse(char line[], int lenght) {
  int begin_char = 0;
  int end_char = lenght - 2;
  int temp = '\0';

  while (begin_char < end_char) {
    temp = line[begin_char];
    line[begin_char] = line[end_char];
    line[end_char] = temp;

    begin_char++;
    end_char--;
  }
}

//abc\0
// 4

//abc\0 input
// end_char = 2, begin_char = 0
// end_char = 1, begin_char = 1


//eduardo\0 input
// begin_char = 0, end_char = 6 => oduarde\0
// begin_char = 1, end_char = 5 => oduarde\0
// begin_char = 2, end_char = 4 => odraude\0
// begin_char = 3, end_char = 3 => odraude\0