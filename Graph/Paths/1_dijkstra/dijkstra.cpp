#include <iostream>
#include <vector>
#include <queue>
#include<climits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;


class Edge
{

  public:
    int from;
    int to;
    int distance;
    Edge(int from,int to,int distance)
    {
      this->from = from;
      this->to = to;
      this->distance = distance;
    }
};

class comprator
{
  public :
   int operator() (const Edge &a,const Edge &b)
    {
        return a.distance > b.distance;
    }
    
};

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her

  priority_queue<Edge,vector<Edge>,comprator> heap;
  vector<int> dis(adj.size(),INT_MAX);
  dis[s] = 0;
  heap.push(Edge(s,s,0));
  while(!heap.empty())
  {
      Edge cur = heap.top();
      heap.pop(); 
      int from = cur.to;
      for(int i = 0;i<adj[from].size();i++)
      { 
          int to = adj[from][i];
          int distemp = cost[from][i];
          if(dis[to]> dis[from] + distemp)
          {
              heap.push(Edge(from,to,distemp));
              dis[to] = dis[from] + distemp;
          }                
      }
  }

  if(dis[t]==INT_MAX) 
    return -1;

  return dis[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
