#include <iostream>
#include<cassert>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous%10;
        previous = current%10;
        current = (tmp_previous + current)%10;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n) {

    n = n % 60;

    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous%10;
        previous = current%10;
        current = (tmp_previous + current)%10;
        sum += current;
    }

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
    // while(true)
    // {
    //     long long n = rand() % 10000000000;
    //     std::cout<<n<<"\n";
    //     assert(fibonacci_sum_fast(n)==fibonacci_sum_naive(n));
    //     std::cout<<"OK\n";
    // }
}
