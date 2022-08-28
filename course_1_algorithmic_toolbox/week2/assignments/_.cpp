#include <iostream>
using namespace std;

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

    // cout << "Pisano period for m = " << m << " is " << pisano_period(m) << endl;
    // cout << "Reduced Fibonacci num from n = " << n << " to n = " << n % pisano_period(m) << endl;
    // cout << "Fibonacci num for n = " << n % pisano_period(m) << " % " << m << " is " << fibonacci_num_mod_m(n, m)<< endl;

    cout << fibonacci_num_mod_m(n, m);

    return 0;
}

// #include <iostream>
// using namespace std;

// int pisano_period(int m)
// {
//     if (m <= 1)
//         return m;

//     int prev_prev = 0;
//     int prev = 1;
//     int current = 1;

//     for (int i = 0; i <= m * m; i++)
//     {
//         current = (prev_prev + prev) % m;
//         prev_prev = prev;
//         prev = current;

//         if (prev_prev == 0 && prev == 1)
//         {
//             return i + 1;
//         }
//     }
// }

// long long fibonacci_num_mod_m(long long n, int m = 10)
// {
//     long long small_equivalent = n % pisano_period(m);

//     if (small_equivalent <= 1)
//         return small_equivalent;

//     long long prev_prev = 0;
//     long long prev = 1;
//     long long current = 1;

//     for (int i = 0; i < small_equivalent - 1; i++)
//     {
//         current = (prev_prev + prev) % m; //note that this term is not going to grow large because of mod
//         prev_prev = prev;
//         prev = current;
//     }

//     return current;
// }

// int main(int argc, char const *argv[])
// {
//     long long n = 0;
//     cin >> n;

//     //just make the list of last squared digits(this is the same as task with modulo m, here we just have m = 10) of the Fibonacci number(it is called Pisano period),
//     //then steps the same like in 6 task. As more nice solution - we can see that area of this rectangle is F_n * F_(n + 1).
//     //so just compute ((F_n % 10) * (F_(n + 1) % 10)) % 10

//     cout << (fibonacci_num_mod_m(n) * fibonacci_num_mod_m(n+1))%10;

//     return 0;
// }

