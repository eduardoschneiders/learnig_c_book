#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

int main(){
  float fahr, celsius;
  fahr = 0;

  printf("Fahr \t Celsius\n");
  while (fahr <= 300) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f \t %6.1f\n", fahr, celsius);
    fahr += 20;
  }

  printf("Celsius \t Fahr\n");
  celsius = 0;
  while (celsius <= 300) {
    fahr = (celsius * 9.0/5.0) + 32.0 ;
    printf("%3.0f \t %6.1f\n", celsius, fahr);
    celsius += 20;
  }

  printf("Using for\n");

  for (int fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
    printf("%3d \t %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
  }

  return 0;
}