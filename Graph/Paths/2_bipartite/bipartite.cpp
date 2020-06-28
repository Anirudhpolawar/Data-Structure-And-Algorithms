#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  vector<int> colors(adj.size(),0);
  queue<int> que;
  que.push(0);
  colors[0] = 1;
  while(!que.empty())
  {
      int cur = que.front();
      que.pop();
      for(int val : adj[cur])
      {
            if(colors[val]==0)
            {
                colors[val] = -colors[cur];
                que.push(val);
            }
            else if(colors[val]==colors[cur])
            {
                return 0;
            }
      }
  }

  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
