#include <stdio.h>

int main(){
  int c, last_char;
  c = last_char = '\0';

  printf("Enter chars: \n");

  while ((c = getchar()) != EOF) {
    if(c != ' ' || c == ' ' && last_char != ' '){
      putchar(c);
    }

    last_char = c;
  }

  return 0;
}
