#include <iostream>
#include<cassert>
#include<cstdlib>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}


void swap(int &a,int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

int gcd_fast(int a,int b)
{
    if(a>b)
      swap(a,b);

    while(a)
    {
        b = b%a;
        swap(b,a);
    }
    return b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //Stress testing
  // while(true)
  // {
  //   int a = rand() % 100000;
  //   int b = rand()%100000;
  //   std::cout<<a<<" "<<b<<"\n";
  //   assert(gcd_naive(a,b) == gcd_fast(a,b));
  //   std::cout<<"OK"<<"\n";
  // }
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
