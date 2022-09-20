#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> &sequence)
{
    for (auto &elem : sequence)
    {
        cout << elem << " ";
    }
    cout << "\n";
}

void merge(vector<int> &sequence, int l, int m, int r)
{
    int i = l;     // left array first idx
    int j = m + 1; // right array first idx

    vector<int> temp(r - l + 1);

    int k = 0; // temp array idx

    while (i <= m && j <= r)
    {
        if (sequence.at(i) <= sequence.at(j))
        {   
            temp.at(k) = sequence.at(i);
            i++;
            k++;
        }
        else
        {   
            temp.at(k) = sequence.at(j);
            j++;
            k++;
        }
    }
    while (i <= m)
    {   
        temp.at(k) = sequence.at(i);
        i++;
        k++;
    }
    while (j <= r)
    {   
        temp.at(k) = sequence.at(j);
        j++;
        k++;
    }

    for (int i = l; i <= r; ++i)//notice this start and end points. It can also be temp.size()-1 
    {   
        //the first element in temp goes to lth position in sequence
        sequence.at(i) = temp.at(i-l);
    }

    // print_vector(sequence);
}

void merge_sort(vector<int> &sequence, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort(sequence, l, m);
        merge_sort(sequence, m + 1, r);

        merge(sequence, l, m, r);
    }
}
int main(int argc, char const *argv[])
{
    int input_size;
    std::cin >> input_size;

    vector<int> sequence(input_size, 0);

    for (size_t i = 0; i < sequence.size(); ++i)
    {
        std::cin >> sequence.at(i);
    }

    merge_sort(sequence, 0, input_size - 1);

    for (size_t i = 0; i < sequence.size(); ++i)
    {
        std::cout << sequence.at(i) << ' ';
    }

    return 0;
}
