#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A) {
  //write your code here
  int sum = 0;
  for(int i = 0;i<A.size();i++)
    sum+=A[i];

  if(sum%3!=0)
    return 0;
    
  vector<bool> dp(sum+1);
  dp[0] = true;

  for(int i = 1;i<=sum;i++)
  {
    for(int j = 0;j<A.size();j++)
    {
        if(A[j]<=i)
          dp[i] = (dp[i] || dp[i-A[j]]);
    }
  }

  if(dp[sum/3]&&dp[(2*sum)/3])
  {
    return 1;
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
