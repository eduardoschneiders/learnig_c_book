#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

int f_to_c(double fahr);
double c_to_f(int celsius);

int main(){
  float fahr, celsius;
  fahr = 0;

  printf("Fahr \t Celsius\n");
  while (fahr <= UPPER) {
    celsius = f_to_c(fahr);
    printf("%3.0f \t %6.1f\n", fahr, celsius);
    fahr += STEP;
  }

  printf("Celsius \t Fahr\n");
  celsius = 0;
  while (celsius <= UPPER) {
    fahr = c_to_f(celsius);
    printf("%3.0f \t %6.1f\n", celsius, fahr);
    celsius += STEP;
  }

  return 0;
}

int f_to_c(double fahr) {
  return (5.0 / 9.0) * (fahr - 32.0);
}

double c_to_f (int celsius) {
  return (celsius * 9.0/5.0) + 32.0;
}
