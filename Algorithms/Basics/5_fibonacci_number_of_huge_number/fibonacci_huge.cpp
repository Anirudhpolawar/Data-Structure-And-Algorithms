#include <iostream>
#include<cassert>
#include<cstdlib>
#include<vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous % 100000;
        previous = current % 100000;
        current = (tmp_previous + current) % 100000;
    }

    return current % m;
}

long long pisano_Period(long long m)
{
    long long previous = 0;
    long long cur = 1;
    for(long long i = 0;;i++)
    {
        long long temp = cur;
        cur = ((previous+cur))%m;
        previous = temp;
        if(previous == 0 && cur == 1)
            return i+1;
    }
    return previous;
 }

 long long fibonacci_huge_fast(long long n,long long m)
 {
    n = n % pisano_Period(m);

     if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n-1 ; ++i) {
        long long tmp_previous = previous % 100000;
        previous = current % 100000;
        current = ((tmp_previous + current)%m) % 100000;
    }

    return current % m;
    
 }

int main() {
        long long n, m;
        std::cin >> n >> m;
        std::cout <<fibonacci_huge_fast(n, m) << '\n';
   
}
