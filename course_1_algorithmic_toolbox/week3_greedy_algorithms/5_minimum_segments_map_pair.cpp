#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> calc_min_points(map<int, int> &segments)
{
    // segments are sorted with respect to the right end
    vector<int> points;
    int point = segments.begin()->first;
    // cout << "first segment right end is " << segments.begin()->first << endl;
    points.push_back(point);

    for (auto &seg : segments)
    {
        if (point > seg.first || point < seg.second) // if > right or < left
        {
            point = seg.first;
            // cout << "new point is " << point << endl;
            points.push_back(point);
        }
    }

    return points;
}
int main(int argc, char const *argv[])
{
    int num_seg;
    map<int, int> segments;

    cin >> num_seg;
    for (int i = 0; i < num_seg; i++)
    {
        int left_end = 0, right_end = 0;
        cin >> left_end >> right_end;
        segments.insert(make_pair(right_end, left_end)); // notice the order
        // cout << "added pair of " << right_end << ", and " << left_end << endl;
        // segments will be ordered by their right_end
    }

    // for(auto& seg : segments){
    //     cout << seg.first << ", " << seg.second << endl;
    // }

    vector<int> result_points = calc_min_points(segments);
    cout << result_points.size() << endl;
    for (auto &point : result_points)
    {
        cout << point << " ";
    }
    return 0;
}
