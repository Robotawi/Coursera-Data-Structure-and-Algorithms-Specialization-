#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// this solution uses a vector of Segments.\
Using a vector of struct is better than using a map in readability

struct Segment{
    int left; 
    int right;
};

vector<int> calc_min_points(vector<Segment>& segments){
    vector<int> points;
    int point = segments.front().right;
    points.push_back(point);

    for (auto& seg : segments){
        // if the point is not on the segment, then next point is this segment's right end
        if (point < seg.left || point > seg.right)
        {
            point = seg.right;
            points.push_back(point);
        }
    }

    return points;
}

int main(int argc, char const *argv[])
{
    int num_seg;
    vector<Segment> segments;

    cin >> num_seg;
    for (int i = 0; i < num_seg; i++)
    {   
        Segment input_segment;
        cin >> input_segment.left >> input_segment.right; 
        segments.emplace_back(std::move(input_segment));
    }

    sort(segments.begin(), segments.end(), [](const Segment& a, const Segment& b){return a.right < b.right;});

    vector<int> result_points = calc_min_points(segments);
    cout << result_points.size() << endl;
    for (auto & point : result_points){
        cout << point << " "; 
    }
    return 0;
}
