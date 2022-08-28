#include <iostream>
using namespace std;

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
long long fibonacci_num_mod_m(long long n, int m = 10)
{
    // the required output is sum mod 10, then we can find a small equivalent with Pisano period
    // because the calculation considers only the last digit, the equivalent is found with Pisano(10) = 60
    long long small_equivalent = n % pisano_period(m);

    if (small_equivalent <= 1)
        return small_equivalent;

    long long prev_prev = 0;
    long long prev = 1;
    long long current = 1;

    for (int i = 0; i < small_equivalent - 1; i++)
    {
        current = (prev_prev + prev) % m; // note that this term is not going to grow large because of mod
        prev_prev = prev;
        prev = current;
    }

    return current;
}

int main(int argc, char const *argv[])
{
    long long n = 0;
    cin >> n;

    // I implemented a more nice solution. From the problem description, we can see the square is a rectangle are of F(n) * F(n + 1).
    // so just compute (F(n) * F(n + 1)) % 10, while mod is 10

    cout << (fibonacci_num_mod_m(n) * fibonacci_num_mod_m(n + 1)) % 10;

    // Another way is to just make the list of last squared digits(this is the same as task with modulo m, here we just have m = 10) of the Fibonacci number(it is called Pisano period),
    // then steps the same like in task 6.

    return 0;
}
