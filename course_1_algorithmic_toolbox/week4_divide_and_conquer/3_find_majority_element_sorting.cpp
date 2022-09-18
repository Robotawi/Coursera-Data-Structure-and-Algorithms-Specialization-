#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//The idea is that sorting array will make the majority element be available at sequence[n/2]\
then, we sort the array, get this element, and count occurrences. If > n/2, it is a majority element.

int main(int argc, char const *argv[])
{
    int input_size = 0;
    cin >> input_size;

    vector<int> sequence(input_size, 0);

    for (int i = 0; i < input_size; i++)
    {
        cin >> sequence.at(i);
    }

    sort(sequence.begin(), sequence.end());

    int result = sequence.at(sequence.size() / 2);

    count(sequence.begin(), sequence.end(), result) > sequence.size() / 2 ? cout << 1 : cout << 0;

    return 0;
}
