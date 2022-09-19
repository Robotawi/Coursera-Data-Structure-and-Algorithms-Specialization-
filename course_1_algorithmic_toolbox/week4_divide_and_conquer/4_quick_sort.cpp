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
int partition(vector<int> &sequence, int l, int r)
{
  // This is the key function of this algorithm as it gives us the partition elements, and make in-place sorting

  int pivot = sequence.at(r);
  int smaller_index = l; // smaller index is used to swap elements < the sequence[pivot] to the left of the pivot

  // loop over the sequence and swap smaller elements to be before the pivot

  for (size_t i = l; i < r; ++i)
  {
    if (sequence.at(i) < pivot)
    {
      swap(sequence.at(i), sequence.at(smaller_index));
      smaller_index++;
      // print_vector(sequence);
    }
  }
  // swap the pivot with the smaller index to put it at the right place
  swap(sequence.at(r), sequence.at(smaller_index));

  // cout << "last step in partitioning ";
  // print_vector(sequence);

  return smaller_index;
}

void quick_sort(vector<int> &sequence, int l, int r)
{
  int p = 0;

  // base case means call recursively till there is only one element in the array
  if (l < r)
  {
    p = partition(sequence, l, r);
    quick_sort(sequence, l, p - 1); // notice p is not included as it will be at the right place
    quick_sort(sequence, p + 1, r);
  }
}

int main()
{
  int input_size;
  std::cin >> input_size;

  vector<int> sequence(input_size, 0);

  for (size_t i = 0; i < sequence.size(); ++i)
  {
    std::cin >> sequence.at(i);
  }

  quick_sort(sequence, 0, sequence.size() - 1);

  for (size_t i = 0; i < sequence.size(); ++i)
  {
    std::cout << sequence.at(i) << ' ';
  }
}