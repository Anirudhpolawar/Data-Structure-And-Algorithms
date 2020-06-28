#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include<bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::make_pair;
using std::pair;

string InverseBWT(const string& bwt) {
  string text = "";

  // write your code here
  vector<pair<char,int>> m;
  int length = bwt.length();
  for(int i = 0;i<length;i++)
      m.push_back(make_pair(bwt[i],i));
  
  sort(m.begin(),m.end());

  pair<char,int> cur = m[0];
  for(int i = 0;i<length;i++)
  {
        cur = m[cur.second];
        text.push_back(cur.first);
  }

  return text;
}

int main() {
  string bwt;
  cin >> bwt;
  cout << InverseBWT(bwt) << endl;
  return 0;
}
