#include <iostream>
#include <cassert>
#include <vector>

//Pisano period helps us find a small equivalent of F(n) mod m as F(n mod Pisano(m)) mod m
//Construct the sequence of F(n) mod m and find the Pisano period at which values in ther series repeat.
//Once the previous two values becomes 0, 1 in the series, we got the period (Pisano number)
int pisano_period(int m)
{
    if (m <= 1)
        return m;

    int prev_prev = 0;
    int prev = 1;
    int current = 1;

    for (int i = 0; i <= m * m; i++)
    {
        current = (prev_prev + prev) % m;
        prev_prev = prev;
        prev = current;

        if (prev_prev == 0 && prev == 1)
        {
            return i + 1;
        }
    }
}

//find a small equivalent of F(n) mod 10 because we care about only the last digit
int fibonacci_sum_last_digit(long long n)
{
    if (n <= 1)
        return n;

    // the required output is sum mod 10, then we can find a small equivalent with Pisano period
    // because the calculation considers only the last digit, the equivalent is found with Pisano(10) = 60 
    int small_equivalent = n % pisano_period(10);

    long long prev = 0;
    long long prev_prev = 0;
    long long current = 1;

    for (long long i = 2; i <= small_equivalent; ++i)
    { //current is calculated based on prev_prev and prev, \
        first step is to prepare them. Look at example 5 or 8 to see another way starting from 0.
        prev_prev = prev;
        prev = current;
        current = (prev_prev + prev) % 10;
    }

    // handle the case when the last digit is 0, we should print 9 not -1.
    return current != 0 ? current : 10;
}

int main()
{
    long long m = 0, n = 0;
    std::cin >> m;
    std::cin >> n;

    // formula: sum(f(n) to f(0)) = f(n+2) - 1
    // start from f(n+1) = f (n) + f(n-1), then
    // f(n-1) = f(n+1) - f(n), which also means f(n) = f(n+2) - f(n+1),
    // then sum from f(n) t0 f(0), terms cancel and give the above formula

    // for this challenge, calculate sum f(n) - sum f(m-1) to get sum between f(n) and f(m)
    int n_sum = fibonacci_sum_last_digit(n + 2) - 1;
    int m_sum = fibonacci_sum_last_digit(m - 1 + 2) - 1;
    int result = (n_sum - m_sum) >= 0 ? (n_sum - m_sum) : (n_sum - m_sum) + 10;

    std::cout << result << '\n';
    return 0;
}