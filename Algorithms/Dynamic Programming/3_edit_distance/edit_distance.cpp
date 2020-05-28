#include <iostream>
#include <string>
#include<vector>
#include<algorithm>

using std::string;
using std::vector;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  vector< vector<int> > dp (str1.size()+1,vector<int>(str2.size()+1));
  int n = str1.size();
  int m = str2.size();

  for(int i = 0;i<=m;i++)
    dp[0][i] = i;
  
  for(int i = 0;i<=n;i++)
    dp[i][0] = i;
  
  for(int i = 1;i<=n;i++)
  {
    for(int j = 1;j<=m;j++)
    {
      int ins = dp[i][j-1]+1;
      int del = dp[i-1][j]+1;
      int misormat = dp[i-1][j-1];
      if(str1[i-1]!=str2[j-1])
        misormat++;
      
      dp[i][j] = std::min(std::min(del,ins),misormat); 
      
    }
  }

  return dp[n][m];

  
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
