#include <iostream>
#include <cassert>
#include <vector>

int fibonacci_last_digit(int n)
{   
    if (n<=1)
    return n; 

    int prev = 0;
    int prev_prev = 0;
    int current = 1;

    for (int i = 2; i <= n; ++i)
    {   //current is calculated based on prev_prev and prev, \
        first step is to prepare them
        prev_prev = prev;
        prev = current;
        current = (prev_prev + prev) % 10;
    }

    return current;
}

int main()
{
    int n = 0;
    std::cin >> n;

    std::cout << fibonacci_last_digit(n) << '\n';
    return 0;
}