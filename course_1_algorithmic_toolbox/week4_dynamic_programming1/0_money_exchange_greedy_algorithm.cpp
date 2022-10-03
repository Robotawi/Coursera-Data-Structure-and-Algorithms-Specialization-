#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main(int argc, char const *argv[])
{
    int money_value = 0;
    cin >> money_value;

    int denom_size;
    cin >> denom_size;

    vector<int> denoms(denom_size, 0);

    for (int i = 0; i < denom_size; i++)
    {
        cin >> denoms.at(i);
    }
    sort(denoms.begin(), denoms.end());

    vector<int> result;
    for (int i = denom_size - 1; i >= 0; --i)
    {
        while (money_value >= denoms.at(i))
        {
            money_value -= denoms.at(i);
            result.push_back(denoms.at(i));
        }
    }

    cout << result.size() << "\n";
    cout << accumulate(result.begin(), result.end(), 0);
    
    return 0;
}
