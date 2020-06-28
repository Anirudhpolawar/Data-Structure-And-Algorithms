#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <utility>

using std::map;
using std::vector;
using std::string;
using std::pair;

typedef map<char, int> edges;
typedef vector<edges> trie;


trie build_trie(vector<string> & patterns) {
 trie t;
  // write your code here
  for (string val : patterns) {
    int cur = 0;
    for (char c : val) 
    {
      if(cur<t.size())
      {
          if(t[cur].find(c)!=t[cur].end())
          {
            cur = t[cur][c]; 
          }
          else
          {
              edges m;
              t.push_back(m);
              t[cur][c] = t.size();
              cur = t.size();
          }
          
      }
      else
      {
        edges m;
        m[c] = t.size()+1;
        t.push_back(m);
        cur = t.size();
      }
     
  }
  }
  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}