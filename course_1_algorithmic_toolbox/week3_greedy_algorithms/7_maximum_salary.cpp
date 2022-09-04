#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// The greedy algorithm does not return the correct answers in some cases. Ex. 32, 3 -> 323, but correct is 332.\
using this is_better function as an ordering criteria solved the problem. Convert to strings and compare for best ordering
bool is_better(const int &a, const int &b)
{
    string str1 = to_string(a);
    str1.append(to_string(b));

    string str2 = to_string(b);
    str2.append(to_string(a));

    return stoi(str1) > stoi(str2);
}

int main(int argc, char const *argv[])
{
    int input_size = 0;
    cin >> input_size;

    vector<int> inputs(input_size, 0);
    for (int i = 0; i < input_size; ++i)
    {
        cin >> inputs[i];
    }

    sort(inputs.begin(), inputs.end(), [](const int& a, const int& b){return is_better(a, b);});

    for (int i = 0; i < input_size; ++i)
    {
        cout << inputs[i];
    }

    return 0;
}
