#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//The idea is to use a map to count the elements in the given sequence\
then, loop over the map elements and find the elements with most occurrences.\
At the end, if the occurrences are more than n/2, we found the majority element.

int main(int argc, char const *argv[])
{
    int input_size = 0;
    cin >> input_size;

    vector<int> sequence(input_size, 0);

    for (int i = 0; i < input_size; i++)
    {
        cin >> sequence.at(i);
    }

    unordered_map<int, int> counter;

    for (int i = 0; i < input_size; i++)
    {
        counter[sequence.at(i)]++;
    }

    int maj_element = 0;
    int maj_count = 0;

    for (auto &elem : counter)
    {
        if (elem.second > maj_count)
        {
            maj_count = elem.second;
            maj_element = elem.first;
        }
    }

    if (maj_count > input_size/2)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }

    return 0;
}
