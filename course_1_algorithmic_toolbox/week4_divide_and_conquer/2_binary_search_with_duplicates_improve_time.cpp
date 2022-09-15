#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int binary_search(vector<int> &sequence, int target)
{
    double low = 0;
    double high = sequence.size() - 1;
    int mid = 0;
    int pre = 0;

    while (low <= high)
    {
        mid = low + floor((high - low) / 2);

        if (target == sequence.at(mid))
        {
            // if we reached the target, search in the previous elements. How?\
            not to confuse with mid element, it is similar to binary search, but a bit different\
            let a 'pre'vious element = mid. Then proceed as pre = low + pre -1, which saves much time.\
            then, if the pre element becomes < target, increment pre++ to reach the first target element occurrence.
            
            pre = mid;

            if (pre == 0)
            {
                return pre;
            }

            while (sequence.at(pre - 1) == target)
            {
                pre = low + floor((pre - 1 - low)/2);

                if (pre == 0)
                {
                    return pre;
                }

                if (sequence.at(pre) < target){
                    while(sequence.at(pre) < target){
                        pre++;
                    }

                    return pre;
                }
            }

            return pre;
        }
        else if (target < sequence.at(mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    int input_size = 0;
    cin >> input_size;

    vector<int> sequence(input_size, 0);

    for (int i = 0; i < input_size; ++i)
    {
        cin >> sequence.at(i);
    }

    int inquiry_size = 0;
    cin >> inquiry_size;

    vector<int> inquiry(inquiry_size, 0);

    for (int i = 0; i < inquiry_size; ++i)
    {
        cin >> inquiry.at(i);
    }

    vector<int> result;

    for (int i = 0; i < inquiry_size; ++i)
    {
        result.push_back(binary_search(sequence, inquiry.at(i)));
    }

    for (int i = 0; i < inquiry_size; ++i)
    {
        cout << result.at(i) << " ";
    }

    return 0;
}
