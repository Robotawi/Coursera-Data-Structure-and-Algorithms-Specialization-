#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//The idea is that The idea is to use divide and conquer with recursion.\
In every step, the given sequence is divided into two problems of size n/2.\
The division keeps going till we reach a base case where an array has a single element.\
If the left and right child nodes return the same element, then it is the majority element in the parent.\
If returned element from both is different, the elements are counted in the parent sequence and the one with more occurrences becomes the majority element of the parent.

int majority_element(vector<int>& sequence, int l, int r)
{
    if (l == r)
        return sequence.at(r);

    int m = l + floor((r - l) / 2);
    int lm = majority_element(sequence, l, m);
    int rm = majority_element(sequence, m + 1, r);

    if (lm == rm)
        return rm;

    return count(sequence.begin() + l, sequence.begin() + r + 1, rm) > count(sequence.begin() + l, sequence.begin() + r + 1, lm) ? rm : lm;
}

int get_majority_element(vector<int>& sequence)
{

    return majority_element(sequence, 0, sequence.size() - 1);
}

int main(int argc, char const *argv[])
{
    int input_size = 0;
    cin >> input_size;

    vector<int> sequence(input_size, 0);

    for (int i = 0; i < input_size; i++)
    {
        cin >> sequence.at(i);
    }

    int result = get_majority_element(sequence);

    // cout << "Majority element is " << result <<  ". It repeated " << count(sequence.begin(), sequence.end(), result) << " times in the sequence\n";

    if (count(sequence.begin(), sequence.end(), result) > input_size / 2)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }

    return 0;
}
