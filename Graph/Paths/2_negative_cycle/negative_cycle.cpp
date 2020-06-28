#include <iostream>
#include <vector>
#include<climits>
#include<unordered_map>


using std::vector;
using std::unordered_map;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
   unordered_map<int,int> m;
     for (int j = 0; j < adj.size() - 1; j++) { //v - 1 iteration
            for (int u = 0; u < adj.size(); u++) {
                for (int k = 0; k < adj[u].size(); k++) {
                    int v = adj[u][k];
                    int w = cost[u][k];
                    int dist = m[v];
                    int newDist = m[u] + w;
                    if (dist > newDist) 
                        m[v] = newDist; //relax
                }
            }
        }

       
        for (int u = 0; u < adj.size(); u++) {
            for (int k = 0; k < adj[u].size(); k++) {
                 int v = adj[u][k];
                    int w = cost[u][k];
                    int dist = m[v];
                    int newDist = m[u] + w;
                    if (dist > newDist) 
                       return 1; //relax
            }
        }

        return 0;
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
  std::cout << negative_cycle(adj, cost);
}
