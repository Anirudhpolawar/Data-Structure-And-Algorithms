#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> dpapproach(int n)
{
  std::vector<int> dp(n+1,0);
  for(int i = 1 ;i<=n;i++)
  {
      dp[i] = dp[i-1]+1;
      if(i%2==0)
        dp[i] = std::min(dp[i],1+dp[i/2]);
      
      if(i%3 == 0)
        dp[i] = std::min(dp[i],dp[i/3]+1);
  }

  std::vector<int> sequence;
  for(int i = n;i>1;)
  {
      sequence.push_back(i);
      if(dp[i] == dp[i-1]+1)
        i = i-1;
      else if(i % 2 == 0 &&dp[i/2]==dp[i]-1)
        i = i / 2;
      else 
        i = i/3;
  }

  sequence.push_back(1);
  reverse(sequence.begin(),sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = dpapproach (n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
