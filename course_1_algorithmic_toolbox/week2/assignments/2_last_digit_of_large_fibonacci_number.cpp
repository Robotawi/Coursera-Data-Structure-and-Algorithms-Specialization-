#include <iostream>
#include <cassert>
#include <vector>

int fibonacci_last_digit(int n)
{
    std::vector<long long> fib_digits;
    for (int i = 0; i <= n; ++i)
        if(i == 0 || i == 1){
            fib_digits.push_back(i);
        }
        else{
            fib_digits.push_back((fib_digits[i-1]+fib_digits[i-2])%10);
        }

    return fib_digits[n];
}


int main()
{
    int n = 0;
    std::cin >> n;

    std::cout << fibonacci_last_digit(n) << '\n';
    return 0;
}