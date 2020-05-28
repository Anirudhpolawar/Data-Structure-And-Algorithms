#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int majority = left;
  int count = 1;
  for(int i = left+1;i<right;i++)
  {
    if(a[majority] == a[i])
      count++;
    else 
      count--;
    if(count == 0)
    {
      majority = i; 
      count = 1;
    }
  }
  count = 0;
  for(int i = left ;i<right;i++)
  {
    if(a[i] == a[majority])
      count++;
  }

  if(count>=((right-left)/2+1))
    return 1;

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
