#include <iostream>

using namespace std;

int main () {
  int numbers[6];
  int * p;
  
  p = numbers;
  *p = 1;
  
  p++;
  *p = 4;
  
  p = &numbers[2];
  *p = numbers[0];
  
  p = numbers + *p;
  *p = 4;
  
  p = numbers+1;
  *(p+4) = 5;
  
  cout << "Numbers : "<<numbers[0]<<" "<<numbers[1]<<" "<<numbers[2]<<" "<<numbers[3]<<" "<<numbers[4]<<" "<<numbers[5]<<endl;

  return 0;
}
