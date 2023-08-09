#include <stdio.h>

void squeeze(char s[], char s2[]);

int main() {
  char s1[100] = "foebobar";
  char s2[100] = "aeiou";

  squeeze(s1, s2);
  printf("%s", s1);

  return 0;
}

void squeeze(char s[], char s2[]) {
  int i, j;

  for (int z = 0; s2[z] != '\0'; z++) {
    for (i = j = 0; s[i] != '\0'; i++) {
      if (s[i] != s2[z])
        s[j++] = s[i];
    }

    s[j] = '\0';
  }
}
