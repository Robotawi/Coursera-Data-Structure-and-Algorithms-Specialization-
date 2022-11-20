#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

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

int min_coins_dp(const int &total_money)
{
    vector<int> money(total_money + 1);
    vector<int> coins{1, 3, 4};
    vector<vector<int>> T(coins.size(), vector<int>(total_money + 1)); // DP table

    int coin_idx = 0;

    for (int m = 0; m <= total_money; m++)
    {
        money.at(m) = m;
        T.at(0).at(m) = m;
    }

    //if less than the the first coin after 1,\
    return the number of ones, which is the money in this case
    if (total_money < 3)
        return total_money;

    for (int i = 1; i < coins.size(); i++)
    {
        for (int j = 1; j <= total_money; j++)
        {
            //if the current money is more than the current coin value, use the formula at line 62 for the number of coins,\
            otherwise, use number of coins in the directly previous row 
            if (money.at(j) >= coins[i])
            {
                    T.at(i).at(j) = min(T.at(i - 1).at(j), T.at(i).at(j - coins[i]) + 1);
            }
            else
            {
                T.at(i).at(j) = T.at(i - 1).at(j);
            }
            // print_vvec(T);
        }
    }

    return T.at(coins.size()-1).at(total_money);
}

int main(int argc, char const *argv[])
{
    int total_money;
    cin >> total_money;

    cout << min_coins_dp(total_money) << endl;

    return 0;
}
