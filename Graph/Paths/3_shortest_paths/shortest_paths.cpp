#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include<stack>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::stack;

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
        vector<int> visited(adj.size(),0); //global visited for dfs/bfs short circuiting
        stack<int> stack; //global stack since each dfs will exit with empty stack anyway

        distance[s] = 0;

        for (int i = 0; i < adj.size() - 1; i++) { //v - 1 iteration
            for (int u = 0; u < adj.size(); u++) {
                for (int j = 0; j < adj[u].size(); j++) {
                    int v = adj[u][j];
                    int w = cost[u][j];
                    long long dist = distance[v];
                    long long  newDist = distance[u];

                    if (newDist == std::numeric_limits<long long>::max()) continue;
                   
                    newDist = newDist + w;

                    if (dist > newDist) distance[v] = newDist; //relax
                }
            }
        }

        // negative cycle iteration, refactor?
        for (int u = 0; u < adj.size(); u++) {
            
            for  (int j = 0; j < adj[u].size(); j++) {
                // relaxation
                  int v = adj[u][j];
                  int w = cost[u][j];
                  long long dist = distance[v];
                  long long  newDist = distance[u];


                if (newDist == std::numeric_limits<long long>::max()) continue;
                newDist = newDist + w;

                // not relaxable || v in visited neg cycle visitable path
                if (dist <= newDist || visited[v]==1) continue;

                
                stack.push(v);
                while (!stack.empty()) {
                    int n = stack.top();
                     stack.pop();

                    visited[n] = 1;
                    shortest[n] = 0;

                    for (int m : adj[n])
                        if (!visited[m]==1) stack.push(m);
                }
            }
        }

        for (int i = 0; i < distance.size(); i++)
            if (distance[i] < std::numeric_limits<long long>::max()) reachable[i] = 1;
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
