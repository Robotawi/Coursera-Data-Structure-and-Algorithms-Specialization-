#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void print_vec(vector<int> vec)
{
    for (auto &elem : vec)
    {
        cout << elem << " ";
    }
    cout << endl;
}

void print_vvec(vector<vector<int>> &vvec)
{
    cout << endl;
    for (auto &vec : vvec)
    {
        print_vec(vec);
    }
    cout << "--------\n";
}

vector<int> primitive_calc_dp(const int &number)
{
    vector<int> T(number + 1);
    vector<int> parents(number + 1);
    vector<int> res_sequence;

    T.at(0) = 1;
    T.at(1) = 0;

    parents.at(0) = 0;
    parents.at(1) = 0;
    
    if (number < 2)
        return vector<int>(1,0);

    // loop from 2 onward
    for (int n = 2; n <= number; n++)
    {

        // First do this
        // Because in some cases, the previous is better than the division
        int min_ops = T.at(n - 1) + 1;
        T.at(n) = min_ops;
        parents.at(n) = n - 1;

        if (n % 3 == 0)
        {
            int num_ops = T.at(n / 3) + 1;
            if (num_ops < min_ops)
            {
                T.at(n) = T.at(n / 3) + 1;
                parents.at(n) = n / 3;
                cout << "Parent of " << n << " is " << n / 3 << endl;
            }
        }
        else if (n % 2 == 0)
        {
            int num_ops = T.at(n / 2) + 1;
            if (num_ops < min_ops)
            {
                T.at(n) = T.at(n / 2) + 1;
                parents.at(n) = n / 2;
                cout << "Parent of " << n << " is " << n / 1 << endl;
            }
        }
        else
        {
            cout << "Parent of " << n << " is " << n - 1 << endl;
        }
    }

    cout << "--- Parent indexes vector is ---\n";
    print_vec(parents);
    cout << "--- Parent indexes vector done ---\n";

    // vector<int> res_sequence;
    res_sequence.push_back(number);

    int idx = number;
    while (parents[idx] > 0)
    {
        cout << "parent[" << idx << "]"
             << " is " << parents[idx] << endl;
        res_sequence.push_back(parents[idx]);
        idx = parents[idx];
    }

    print_vec(res_sequence);

    std::reverse(res_sequence.begin(), res_sequence.end());

    return res_sequence;
}

int main(int argc, char const *argv[])
{
    int input = 0;
    cin >> input;
    vector<int> res_requence = primitive_calc_dp(input);
    cout << res_requence.back() << endl;
    for (auto &elem : res_requence)
        cout << elem << " ";
    cout << endl;
    return 0;
}
