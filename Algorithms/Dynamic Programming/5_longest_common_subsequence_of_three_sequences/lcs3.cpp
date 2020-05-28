#include <iostream>
#include <vector>
#include<algorithm>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  vector< vector< vector<int> > > dp(a.size()+1,vector< vector<int>>(b.size()+1,vector<int> (c.size()+1,0)));
  int n = a.size();
  int m = b.size();
  int k = c.size();
  for(int i = 1;i<=n;i++)
  {
    for(int j = 1;j<=m;j++)
    {
      for(int p = 1;p<=k;p++)
      {
          if(a[i-1]==b[j-1] && a[i-1] == c[p-1])
          {
            dp[i][j][p] = dp[i-1][j-1][p-1]+1;
          }
          else
          {
            dp[i][j][p] = std::max(std::max(dp[i-1][j][p],dp[i][j-1][p]),dp[i][j][p-1]);
          }
          
      }
    }
  }

  return dp[n][m][k];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
