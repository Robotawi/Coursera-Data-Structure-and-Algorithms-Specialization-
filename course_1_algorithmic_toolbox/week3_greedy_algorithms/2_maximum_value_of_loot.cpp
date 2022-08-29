#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

double maximize_loot(const int capacity, map<double, double, greater<double>> &cost_weight)
{
    int collected = 0;
    double collected_value = 0.0;

    // for every item, if the weight is >= capacity - collected weight, add only capacity-collected weight
    // else, which  means the item weight is less that capacity - collected weight, add all the weight of the item
    for (auto &entry : cost_weight)
    {
            if (entry.second >= capacity - collected)
            {  
                collected_value += entry.first * (capacity - collected);
                collected += capacity - collected;
                entry.second -= capacity - collected;
            }
            else
            {   
                collected_value += entry.first * entry.second;
                collected += entry.second;
                entry.second -= entry.second;
            }
    }

    return collected_value;
}

int main(int argc, char const *argv[])
{
    double num_comp = 0.0;
    double capacity = 0.0;

    cin >> num_comp;
    cin >> capacity;

    // make a map of descending order
    map<double, double, greater<double>> cost_weight;

    // fill the map with unit price and weight of each item
    for (int i = 0; i < num_comp; ++i)
    {
        double cost = 0;
        double weight = 0;
        cin >> cost >> weight;
        cost_weight.insert(make_pair(cost / weight, weight));
    }

    // cout << "Got num compounds " << num_comp << endl;

    // for (auto it = cost_weight.begin(); it != cost_weight.end();it++)
    // {
    //     cout << it->first << ", ";
    //     cout << it->second << "\n";
    // }

    cout << setprecision(4) << fixed << maximize_loot(capacity, cost_weight) << endl;
    return 0;
}
