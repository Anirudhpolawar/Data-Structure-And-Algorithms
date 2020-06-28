#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string BWT(const string& text) {
  string result = "";

  // write your code here
  vector<string> m;
  int n = text.length();
  for(int i = 0;i<n;i++)
  {
      string temp = text.substr(i,n-i)+text.substr(0,i);
      m.push_back(temp);
  }

  sort(m.begin(),m.end());

  for(int i = 0;i<n;i++)
  {
    result.push_back(m[i][m[i].length()-1]);
  }

  return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}