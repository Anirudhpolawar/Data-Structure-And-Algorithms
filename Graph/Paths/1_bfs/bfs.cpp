#include <iostream>
#include <vector>
#include <queue>
#include<climits>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  queue<int> que;
  que.push(s);
  vector<int> dis(adj.size(),INT_MAX);
  dis[s] = 0;
  que.push(s);
  while(!que.empty())
  {
      int cur  = que.front();
      que.pop();
      for(int val : adj[cur])
      {
        if(dis[val]==INT_MAX)
        {
            que.push(val);
            dis[val] = dis[cur]+1;
            if(val==t)
              return dis[val];
        }
      }
  }
  return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
