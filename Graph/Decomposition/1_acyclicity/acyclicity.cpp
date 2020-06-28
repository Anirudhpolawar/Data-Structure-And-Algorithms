#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int explore(vector<vector<int>> &adj,vector<int> &visited,int x,vector<int> &temporaryvisit)
{
  visited[x] = 1;
  temporaryvisit[x] = 1;
  for(int val : adj[x])
  {
    if(visited[val]==0)
    {
         if(explore(adj,visited,val,temporaryvisit)==1)
              return 1;
    }
    else if (temporaryvisit[val]==1)
    {
      return 1;
    }
   
  }
  temporaryvisit[x] = 0;
  return 0;
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here
  vector<int> visited(adj.size(),0);
  vector<int> temporaryvisit(adj.size(),0);
  for(int i = 0;i<adj.size();i++)
  {
      if(visited[i]==0)
      {
        if(explore(adj,visited,i,temporaryvisit)==1)
          return 1;
      }

  }
  return 0;
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
  std::cout << acyclic(adj);
}
