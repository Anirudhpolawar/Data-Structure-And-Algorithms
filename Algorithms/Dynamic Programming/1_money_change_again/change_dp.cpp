#include <iostream>
#include<vector>
#include<algorithm>

using std::vector;

int get_change(int m) {
  //write your code here
  vector<int> array(m+1,0);
  for(int i = 1;i<=m;i++)
  {
      array[i] = array[i-1]+1;
      if(i>=3)
        array[i] = std::min(array[i],array[i-3]+1);
      if(i>=4)
        array[i] = std::min(array[i],array[i-4]+1);
  }
 
  return array[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
