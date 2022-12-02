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

int edit_distance(const string &str_1, const string &str_2)
{
    vector<vector<int>> T(str_1.size() + 1, vector<int>(str_2.size() + 1));

    if (str_1.size() == 0)
    {
        return str_2.size();
    }
    if (str_2.size() == 0)
    {
        return str_1.size();
    }

    for (int i = 0; i <= str_1.size(); i++)
    {
        T.at(i).at(0) = i;
    }

    for (int j = 0; j <= str_2.size(); j++)
    {
        T.at(0).at(j) = j;
    }

    //We filled the zero row/column, and now start to fill the T grid from index 1\
    however, notice that we want to loop over the strings from their index 0, while filling the DP table/grid T starting from index 1\
    this is why we are checking str_1.at(i-1).at(j-1) and then setting T.at(i)(j)

    //There something I need to fix, despite the grid is and final result arecorrect, I made rows columns, and columns rows.   
    for (int i = 1; i <= str_1.size(); i++)
    {
        for (int j = 1; j <= str_2.size(); j++)
        {
            if (str_1.at(i - 1) == str_2.at(j - 1))
            {
                T.at(i).at(j) = T.at(i - 1).at(j - 1);
            }
            else
            {
                T.at(i).at(j) = min(T.at(i - 1).at(j - 1), min(T.at(i).at(j - 1), T.at(i - 1).at(j))) + 1;
            }
        }
    }

    // print_vvec(T);

    return T.at(str_1.size()).at(str_2.size());
}

int main(int argc, char const *argv[])
{
    string str_1, str_2;

    cin >> str_1;
    cin >> str_2;

    cout << edit_distance(str_1, str_2);

    return 0;
}
