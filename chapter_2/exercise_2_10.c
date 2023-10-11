#include <stdio.h>
int lower(int c);

int main() {
  printf("asdf %c", lower('E'));
}

int lower(int c) {
  return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}