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

//find a small equivalent of F(n) mod m as F(n mod Pisano(m)) mod m
long long fibonacci_num_mod_m(long long n, long long m)
{
    long long small_equivalent = n % pisano_period(m);

    if (small_equivalent <= 1)
        return small_equivalent;

    long long prev_prev = 0;
    long long prev = 1;
    long long current = 1;

    for (int i = 0; i < small_equivalent - 1; i++)
    {
        current = (prev_prev + prev) % m; //note that this term is not going to grow large because of mod
        prev_prev = prev;
        prev = current;
    }

    return current;
}

int main(int argc, char const *argv[])
{
    long long n = 0, m = 0;
    cin >> n >> m;

    /* uncomment to know what is going on */
    // cout << "Pisano period for m = " << m << " is " << pisano_period(m) << endl;
    // cout << "Reduced Fibonacci num from n = " << n << " to n = " << n % pisano_period(m) << endl;
    // cout << "Fibonacci num for n = " << n % pisano_period(m) << " % " << m << " is " << fibonacci_num_mod_m(n, m)<< endl;

    cout << fibonacci_num_mod_m(n, m);

    return 0;
}
