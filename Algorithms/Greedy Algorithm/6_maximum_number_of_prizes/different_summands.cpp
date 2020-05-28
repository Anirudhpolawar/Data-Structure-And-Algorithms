#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int cursum = 0;
  int i = 1;
  while(cursum!=n)
  {
    if((n-(cursum+i))>i||cursum+i==n)
    {
      summands.push_back(i);
      cursum+=i;
    }
    i++;
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
