#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

long long pairwise_product(vector<int> &input)
{
    int max1_idx = -1;

    for (int i = 0; i < input.size(); ++i)
    {
        if (max1_idx == -1 || input.at(i) > input.at(max1_idx))
        {
            max1_idx = i;
        }
    }

    int max2_idx = -1;
    for (int j = 0; j < input.size(); ++j)
    {
        if ((max2_idx == -1 || input.at(j) > input.at(max2_idx)) && j != max1_idx)
        {
            max2_idx = j;
        }
    }

    return (long long)input.at(max1_idx) * input.at(max2_idx);
}

int main(int argc, char const *argv[])
{
    int input_size{0};
    cin >> input_size;

    vector<int> input(input_size, 0);

    for (int i = 0; i < input_size; ++i)
    {
        cin >> input.at(i);
    }

    long long result = pairwise_product(input);

    cout << result << "\n";
    return 0;
}
