#include <iostream>
#include<cassert>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
        sum += current * current;
    }

    return sum % 10;
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


 int fibonacci_huge_fast(long long n,long long m)
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


int fibonacci_sum_squares_fast(long long n)
{
    if(n<=1)
        return n;
    int t1 = fibonacci_huge_fast(n,10);
    int t2 = fibonacci_huge_fast(n-1,10);
    return (t1*(t1+t2))%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
    // while(true)
    // {
    //     long long n= rand()%10000;
    //     std::cout<<n<<"\n";
    //     assert(fibonacci_sum_squares_fast(n)==fibonacci_sum_squares_naive(n));
    //     std::cout<<"OK\n";
    // }
}
