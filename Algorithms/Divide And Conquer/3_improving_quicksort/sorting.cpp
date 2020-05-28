#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

void partition2(vector<int> &arr, int left, int right, int &i, int &j) {
   if (right - left <= 1) {
      if (arr[right] < arr[left])
         swap(arr[right], arr[left]);
      i = left;
      j = right;
      return;
        }
        int mid = left;
        int pivot = arr[right];
        while (mid <= right) {
          if (arr[mid]<pivot)
              swap(arr[left++], arr[mid++]);
              else if (arr[mid]==pivot)
                mid++;
              else if (arr[mid] > pivot)
                swap(arr[mid], arr[right--]);
          }
          i = left-1;
          j = mid;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int left = l;
  int right = r;
  partition2(a, l, r,left,right);
  // std::cout<<k<<" : "<<left<<" "<<right<<" ";
  randomized_quick_sort(a, l, left);
  randomized_quick_sort(a, right, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
