#include <stdio.h>

int any(const char s[], const char s2[]);

int main() {
  char s1[100] = "foebobar";

  printf("%d\n", any(s1, "gpof"));

  return 0;
}

int any(const char s[], const char s2[]) {
  for (int z = 0; s2[z] != '\0'; z++) {
    for (int i = 0; s[i] != '\0'; i++) {
      if (s[i] == s2[z])
        return i;
    }
  }

  return -1;
}
