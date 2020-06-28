#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore(vector<vector<int>> &adj,vector<int> &visited,int x)
{
  visited[x] = 1;
  for(int val : adj[x])
  {
    if(visited[val]==0)
      explore(adj,visited,val);
  }
}


int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  int n = adj.size();
  vector<int> visited(n,0);
  for(int i = 0;i<n;i++)
  {
    if(visited[i]==0)
    {
      explore(adj,visited,i);
      res++;
    }
  }
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
