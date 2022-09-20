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

int merge(vector<int> &sequence, int l, int m, int r)
{
    int i = l;     // left array first idx
    int j = m + 1; // right array first idx
    int count = 0;

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
            //This is tricky. It's like that because if an element A on the left subarray is > an element on the right,\
            all the elements after A will form inversion pairs with the smaller element from the right subarray.\
            m+1 is the number of elements on the left subarray because the counting starts from 0 and last element in it has index = m (according to my implementation)
            
            count = count + (m + 1 - i);//the tricky point.

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

    for (int i = l; i <= r; ++i) // notice this start and end points. It can also be temp.size()-1
    {
        // the first element in temp goes to lth position in sequence
        sequence.at(i) = temp.at(i - l);
    }

    return count;
}

int merge_sort(vector<int> &sequence, int l, int r)
{
    int count = 0;

    if (l < r)
    {
        int m = l + (r - l) / 2;
        count += merge_sort(sequence, l, m);
        count += merge_sort(sequence, m + 1, r);
        count += merge(sequence, l, m, r);
    }

    return count;
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

    int count = merge_sort(sequence, 0, input_size - 1);

    // for (size_t i = 0; i < sequence.size(); ++i)
    // {
    //     std::cout << sequence.at(i) << ' ';
    // }

    cout << count;

    return 0;
}
