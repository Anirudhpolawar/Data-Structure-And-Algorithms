#include <iostream>


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

    for (int i = 2; i <=n ; i++) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current);
    }

    return current % m;
    
 }

 int get_fibonacci_last_digit_fast(int n) {
    n = n%60;
    if (n <= 1)
        return n;
    
    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n-1; ++i) {
        int tmp_previous = previous%10;
        previous = current%10;
        current = (tmp_previous + current)%10;
    }

    return current % 10;
}


long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    long long temp1, temp2;
    if (from == to) {
        return get_fibonacci_last_digit_fast(from % 60);
    } else {
        from = from % 60;
        to = to % 60;

        temp1 = fibonacci_huge_fast(from + 1, 10) - 1;
        temp2 = fibonacci_huge_fast(to + 2, 10) - 1;
    }
    
    if(temp2 - temp1<0)
        return 10 + (temp2-temp1);

    return (temp2 - temp1) % 10;
    
    
}





int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
