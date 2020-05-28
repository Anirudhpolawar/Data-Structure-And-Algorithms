#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  vector< vector<int> > dp(a.size()+1,vector<int>(b.size()+1,0));
  int n = a.size();
  int m = b.size();
  for(int i = 1;i<=n;i++)
  {
    for(int j = 1;j<=m;j++)
      {
        if(a[i-1]==b[j-1])
          dp[i][j] = dp[i-1][j-1]+1;
        else
          dp[i][j] = std::max(dp[i-1][j],dp[i][j-1]);
      }
  }
  return dp[n][m];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
