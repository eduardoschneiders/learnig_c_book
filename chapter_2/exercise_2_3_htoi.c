#include <stdio.h>

int is_valid_number(char str[]);
int strlen(char str[]);
int hex_char_to_int(char c);
int chartoi(char c);
int pow(int base, int multiplier);

int main() {
  // char str[100] = "\\x18";
  // char str[100] = "\\x1f";
  // char str[100] = "\\x2af"; // 687
  char str[100] = "\\X2aF"; // 687
  // char str[100] = "1f"; // 31

  if (!is_valid_number(str)) {
    printf("%s is not a valid hexadecimal number", str);
    return 1;
  }

  int sum = 0;
  int len = strlen(str);

  int start = 0;

  if (str[0] == '\\' && (str[1] == 'x' || str[1] == 'X')) {
    start = 2;
  }

  for (int i = len - 1; i >= 0; i--) {
    sum += (hex_char_to_int(str[i + start]) * pow(16, len - i - 1));
  }

  printf("%d \n", sum);
  return 0;
}


int is_valid_number(char str[]) {
  int start = 0;

  if (str[0] == '\\' && (str[1] == 'x' || str[1] == 'X')) {
    start = 2;
  }

  char c;

  for (int i = 0 + start; (c = str[i]) != '\0'; i++) {
    if (!(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F'))
      return 0;
  }


  return 1;
}

int strlen(char str[]) {
  char c;
  int i;
  int start = 0;

  if (str[0] == '\\' && (str[1] == 'x' || str[1] == 'X')) {
    start = 2;
  }

  for (i = 0 + start; (c = str[i]) != '\0'; i++)
    ;

  return i - start;
}

int hex_char_to_int(char c) {
  if (c >= '0' && c <= '9')
    return chartoi(c);

  return chartoi(c) + 10;
}


int chartoi(char c) {
  if (c >= '0' && c <= '9')
    return c - '0';
  else if (c >= 'a' && c <= 'z')
    return c - 'a';
  else if (c >= 'A' && c <= 'Z')
    return c - 'A';
}


int pow(int base, int n) {
  int i, p;
  p = 1;

  for (i = 1; i <= n; ++i)
    p = p * base;

  return p;
}