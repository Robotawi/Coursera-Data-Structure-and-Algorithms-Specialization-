#include <iostream>
#include <vector>

#include <numeric> //note this

using namespace std;

// Calculate max num of integers that sum up to given number
vector<int> calc_max_ints_in_num(int input_num)
{
    int current_int = 1;
    // int next_int = 0;
    vector<int> result;

    if (input_num <= 2)
    {
        result.push_back(input_num);
        return result;
    }

    result.push_back(1);
    while (accumulate(result.begin(), result.end(), 0) <= input_num)
    {
        if (current_int + 1 + accumulate(result.begin(), result.end(), 0) <= input_num)
        {
            result.push_back(current_int + 1);
            current_int++;
        }
        else
        {
            if (accumulate(result.begin(), result.end(), 0) == input_num)
            {
                break;
            }
            else
            {
                current_int++;
                result.back() = current_int;
            }
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    int input_num = 0;
    cin >> input_num;

    vector<int> result = calc_max_ints_in_num(input_num);

    cout << result.size() << endl;
    for (auto &elem : result)
    {
        cout << elem << " ";
    }
    return 0;
}
