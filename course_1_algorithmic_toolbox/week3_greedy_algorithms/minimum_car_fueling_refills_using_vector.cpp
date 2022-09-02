#include <iostream>
#include <vector>
using namespace std;

int calc_min_refills(const vector<int> &stations, const int &max_dist_one_refil)
{
    int refills = 0;
    int current_st = 0;
    int last_refil_st = 0;

    // cout << "Stations size is " << stations.size() << endl;

    while (current_st < stations.size() - 1) // current_st max = 4
    {
        // cout << "Current station is " << current_st << ", and last refill station is " << last_refil_st << endl;
        if (stations.at(current_st + 1) - stations.at(last_refil_st) <= max_dist_one_refil)
        {
            // cout << "Distance difference is " << stations.at(current_st + 1) - stations.at(last_refil_st) << endl;
            current_st++;
        }
        else
        {
            if (stations.at(current_st + 1) - stations.at(current_st) <= max_dist_one_refil)
            {
                last_refil_st = current_st;
                refills++;
                // cout << "Refilled at current station. Refills = " << refills << endl;
            }
            else
            {   
                // cout << "Distance difference is " << stations.at(current_st + 1) - stations.at(last_refil_st) << ". No way! "<< endl;
                return -1;
            }
        }
    }

    return refills;
}
int main(int argc, char const *argv[])
{
    int travel_dist = 0;
    int max_dist_one_refil = 0;
    int num_stations = 0;

    cin >> travel_dist >> max_dist_one_refil >> num_stations;

    vector<int> stations(num_stations + 2, 0);
    stations.front() = 0;
    stations.back() = travel_dist;

    for (int i = 1; i < num_stations + 1; i++)
    {
        cin >> stations.at(i);
    }

    // for (auto &i : stations)
    // {
    //     cout << i << ", ";
    // }
    // cout << endl;

    int refills = calc_min_refills(stations, max_dist_one_refil);

    // cout << "vector size is " << stations.size() << endl;

    cout << refills;
    return 0;
}