#include <iostream>
#include <vector>

using std::vector;
using std::pair;


vector<int> visited;
int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  if(x==y)
    return 1;
  else
  {
    visited[x] = 1;
    for(int val : adj[x])
    {
      if(visited[val]==0)
      {
        if(reach(adj,val,y)==1)
          return 1;
      }
    }
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  visited.resize(n,0);
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
