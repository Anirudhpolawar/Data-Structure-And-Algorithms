#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int>> &adj,int x,vector<int> &visited,vector<int> &postcollector)
{
    visited[x] = 1;
    for(int val : adj[x])
      if(visited[val]==0)
        dfs(adj,val,visited,postcollector);
    postcollector.push_back(x);
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  //write your code here
  int n = adj.size();
  vector<vector<int> > reverse_graph(n);
  for(int i = 0;i<n;i++)
  {
    for(int val : adj[i])
    {
      reverse_graph[val].push_back(i);
    }
  }

  vector<int> visited(n,0);
  vector<int> postcollector;
  for(int i = 0;i<n;i++)
    if(visited[i]==0)
    {
      dfs(reverse_graph,i,visited,postcollector);
    }
  
  for(int i = 0;i<n;i++)
    visited[i] = 0;

  for(int i = n-1;i>=0;i--)
  {
     if(visited[postcollector[i]]==0)
     {
       dfs(adj,postcollector[i],visited,postcollector);
       result++;
     } 
  }
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << number_of_strongly_connected_components(adj);
}
