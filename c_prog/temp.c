#include <stdio.h>

float cels_from_fahr(float fahr) { return (5.0 / 9.0) * (fahr - 32); }

int less_equal(int x, int y) { return x <= y; }
int greater_equal(int x, int y) { return x >= y; }

void temp_table(int start, int end, int delta, float (*fp) (float), const char* header, const char* col1, 
const char* col2){
  float tempFrom, tempTo;
  int lower = start, upper = end, step = delta;
  tempFrom = start;

  printf("%s\n", header);
  printf("%4s\t%4s\n",col1, col2); 

  int (*comp) (int, int) = (delta > 0 ? less_equal : greater_equal);
  while (comp(tempFrom, end)){
    tempTo = (*fp) (tempFrom);
    printf("%3.0f %10.1f\n", tempFrom, tempTo);
    tempFrom += step;
  }
  printf("\n");
}

void test_tempTable () { temp_table(-100, 100, 20, cels_from_fahr, "Farenheit to Celsius", "F", "C"); }


int main(int argc, const char* argv[]){
 test_tempTable();

 return 0;
}