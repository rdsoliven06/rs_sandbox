#include <stdio.h>

/* This program prints Fahrenheit-Celsius Table*/

int main(){

  float fahr, celsius;
  float lower, upper, step;

  lower = -100.0; //lower limit of temperature scale
  upper = 100.0; //upper limit
  step = 20.0; // step size

  fahr = lower;

  printf("Fahrenheit to Celsius\n");
  printf("  F \t  C \n");
  while (fahr <= upper){
    celsius = 5 * (fahr-32) / 9;
    printf("%4.0f\t%0.2f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
