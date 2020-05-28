#include <iostream>
#include<cassert>
#include<cstdlib>

long long lcm_naive(int  a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

void swap(long  &a,long  &b)
{
  long long temp = a;
  a = b;
  b = temp;
}

int  gcd(long a,long b)
{
    if(a>b)
      swap(a,b);
    while(a)
    {
      b = b%a;
      swap(a,b);
    }
    return b;
}

long long lcm_fast(long long a, long long b)
{
    long long num = a*b;
    long long GCD = gcd(a,b);
    return num/GCD;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  //Stree testing
  // while(true)
  // {
  //   long long a = rand()%10000;
  //   long long b = rand()%10000;
  //   std::cout<<a<<" "<<b<<"\n";
  //   assert(lcm_fast(a,b) == lcm_naive(a,b));
  //   std::cout<<"OK\n";
  // }
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
