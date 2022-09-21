#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

struct Segment
{
    int start;
    int end;
};

int main(int argc, char const *argv[])
{
    int num_seg = 0;
    int num_pnt = 0;

    cin >> num_seg;
    cin >> num_pnt;

    vector<int> points(num_pnt); //to keep the order of the input
    map<int, string> points_segments; 

    Segment in_seg;
    for (int i = 0; i < num_seg; ++i)
    {
        cin >> in_seg.start;
        cin >> in_seg.end;

        points_segments.insert({in_seg.start, "start"});
        points_segments.insert({in_seg.end, "end"});
    }

    int point;
    for (int j = 0; j < num_pnt; ++j)
    {
        cin >> point;
        points.at(j) = point; 
        points_segments.insert({point, "point"});
    }

    unordered_map<int, int> points_count; //keeping the order does not really help because the input is not order\
    it is better to use an unordered_map for retrieve elements fast 
    
    int count = 0; 
    for (auto & elem : points_segments){

        if(elem.second == "start"){
            count++;
        }
        else if(elem.second == "end"){
            count--;
        }
        else
        {
            points_count.insert({elem.first, count}); 
        }
        
    }

    //fast retireval come here, boy! 
    for (auto & point : points){
        auto point_it = points_count.find(point); 
        cout << point_it->second << " "; 
    }
    
    return 0;
}
