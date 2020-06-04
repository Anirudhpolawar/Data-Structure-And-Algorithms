#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void shiftdown(int i,int n)
  {
      int minindex = i;
      int left = 2 * i + 1;
      if(left<n && data_[left]<data_[minindex])
        minindex = left;
      int right = 2 * i + 2;
      if(right<n && data_[right]<data_[minindex])
        minindex = right;
      if(minindex!=i)
      {
        swap(data_[i],data_[minindex]);
        swaps_.push_back(make_pair(i,minindex));
        shiftdown(minindex,n);
      }
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    int n = data_.size();
    for (int i = n-1; i >= 0; --i)
    {
           shiftdown(i,n);
    }
    
}

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
