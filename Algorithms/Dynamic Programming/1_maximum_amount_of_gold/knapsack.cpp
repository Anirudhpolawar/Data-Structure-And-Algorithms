#include <iostream>
#include<algorithm>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  vector< vector<int> > dp(w.size()+1,vector<int>(W+1,0));
  int n = w.size();
  
  for(int i = 0;i<n;i++)
  {
        for(int j = 0;j<=W;j++)
        {
            if(j>=w[i])
              dp[i+1][j] = std::max(dp[i][j],dp[i][j-w[i]]+w[i]);
            else
              dp[i+1][j] = dp[i][j];
        }
  }

  return dp[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
