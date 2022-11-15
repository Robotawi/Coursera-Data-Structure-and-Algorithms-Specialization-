#include <iostream>
#include <vector>

using namespace std;

int least_com_subsequence(vector<int> &s1, vector<int> &s2)
{
    vector<vector<int>> T(s1.size() + 1, vector<int>(s2.size() + 1));

    for (size_t i = 0; i <= s1.size(); i++)
    {
        for (size_t j = 0; j <= s2.size(); j++)
        {
            if (i == 0 || j == 0)
                T[i][j] = 0;

            else if (s1[i] == s2[j])
                T[i][j] = T[i - 1][j - 1] + 1;

            else
                T[i][j] = max(T[i][j - 1], T[i - 1][j]);
        }
    }

    return T[s1.size()][s2.size()];
}

int main(int argc, char const *argv[])
{
    int s1_size{0};
    int s2_size{0};

    cin >> s1_size;
    vector<int> s1(s1_size, 0);

    for (size_t i = 0; i < s1_size; i++)
    {
        cin >> s1.at(i);
    }

    cin >> s2_size;
    vector<int> s2(s2_size, 0);

    for (size_t i = 0; i < s2_size; i++)
    {
        cin >> s2.at(i);
    }

    cout << least_com_subsequence(s1, s2) << endl;

    return 0;
}
