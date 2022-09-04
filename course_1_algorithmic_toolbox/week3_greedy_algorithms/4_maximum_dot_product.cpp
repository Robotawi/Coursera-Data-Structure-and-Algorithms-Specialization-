#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//this problem is also called maximum ads revenue 
int main(int argc, char const *argv[])
{
    long long input_size = 0;
    cin >> input_size;

    vector<long long> price_clicks(input_size, 0);
    vector<long long> slot_clicks(input_size, 0);

    for (long long i = 0; i < input_size; ++i)
    {
        cin >> price_clicks.at(i);
    }

    for (long long i = 0; i < input_size; ++i)
    {
        cin >> slot_clicks.at(i);
    }

    sort(price_clicks.begin(), price_clicks.end());
    sort(slot_clicks.begin(), slot_clicks.end());

    long long sum = 0;

    for (int i = 0; i < input_size; ++i)
    {
        sum += price_clicks.at(i) * slot_clicks.at(i);
    }

    cout << sum;

    return 0;
}
