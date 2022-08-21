#include <iostream>
#include <cassert>
#include <vector>

int fibonacci_naive(int n)
{
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long long fibonacci_fast(int n)
{
    // write your code here
    std::vector<long long> fib_numbers;
    for (int i = 0; i <= n; ++i)
        if(i <= 1){
            fib_numbers.push_back(i);
        }
        else{
            fib_numbers.push_back(fib_numbers[i-1]+fib_numbers[i-2]);
        }

    return fib_numbers[n];
}

void test_solution()
{
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main()
{
    int n = 0;
    std::cin >> n;

    // std::cout << fibonacci_naive(n) << '\n';
    // test_solution();
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}