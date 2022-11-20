#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> vec)
{
    for (auto &elem : vec)
    {
        cout << elem << " ";
    }
    cout << endl;
}

void print_vvec(vector<vector<int>> &vvec)
{
    cout << endl;
    for (auto &vec : vvec)
    {
        print_vec(vec);
    }
    cout << "--------\n";
}

int main(int argc, char const *argv[])
{
    int rows = 4;
    int cols = 10;

    vector<vector<int>> vecy(rows, vector<int>(cols));
 
    cout << "Number of rows is " << vecy.size() << "\nNumber of cols is " << vecy.at(0).size() << endl;
    
    vecy.at(3).at(9) = 10;

    print_vvec(vecy);

    return 0;
}
