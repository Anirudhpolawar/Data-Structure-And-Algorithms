#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include<climits>
#include<algorithm>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  //write your code here
  vector<int> nums;
  string curval = "";
  vector<char> op;
  for(int i = 0;i<exp.length();i++)
  {
      if(exp[i]<'0'||exp[i]>'9')
      {
          op.push_back(exp[i]);
          nums.push_back(atoi(curval.c_str()));
          curval = "";
      }
      else
      {
        curval+=exp[i];
      }   
  }

  nums.push_back(atoi(curval.c_str()));

  int n = nums.size();
  vector< vector<long long> > dp(n,vector<long long>(n,0));
  vector< vector<long long> > dp2(n,vector<long long>(n,0));

  for(int i = 0;i<n;i++)
  {
      dp[i][i] = nums[i];
      dp2[i][i]  = nums[i];
  }

  for(int len = 2;len<=n;len++)
  {
        for(int i = 0;i<n-len+1;i++)
        {
            int last = i+len-1;
            dp[i][last] = LONG_MIN;
            dp2[i][last] = LONG_MAX;
            for(int k = i;k<last;k++)
            {
                long long a = eval(dp[i][k],dp[k+1][last],op[k]);
                long long b = eval(dp[i][k],dp2[k+1][last],op[k]);
                long long c = eval(dp2[i][k],dp[k+1][last],op[k]);
                long long d = eval(dp2[i][k],dp2[k+1][last],op[k]);
                dp[i][last] = max(dp[i][last],max(a,max(b,max(c,d))));
                dp2[i][last] = min(dp2[i][last],min(a,min(b,min(c,d))));
            } 
        }
  }

  return dp[0][n-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
