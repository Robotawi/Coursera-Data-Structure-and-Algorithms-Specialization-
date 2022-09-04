#include <iostream>
#include <vector>

#include <numeric> //note this

using namespace std;

// Calculate max num of integers that sum up to given number

// Time is improved by tracking the current_sum in an integer \
instead of summing all vectors elements every time.
vector<int> calc_max_ints_in_num(int input_num)
{
    int current_int = 1;
    int current_sum = 1;
    vector<int> result;

    if (input_num <= 2)
    {
        result.push_back(input_num);
        return result;
    }

    result.push_back(1);
    while (current_sum <= input_num)
    {   // if adding the next integer to the sum does not exceed the input number, add it \
        otherwise, check if the current_sum is equal to the input number \
        if not, increment the integer currently at the end of the vector till they become equal then break the loop on equality!
        // I think removing the = from the while loop condition may also work, but may try it later 
        if (current_int + 1 + current_sum <= input_num)
        {
            result.push_back(current_int + 1);
            current_sum += current_int + 1;
            current_int++;
        }   
        else
        {
            if (current_sum == input_num)
            {
                break;
            }
            else
            {
                // current_sum -= current_int;
                current_int++;
                // current_sum += current_int;
                current_sum++;
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
