#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;

class Sets
{
public:
    vector<int> parent;
    vector<int> rank;
    Sets(int n)
    {
        for(int i = 0;i<=n;i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int Find(int value)
    {
        int i = value;

        //Iterating till the root node
        while(parent[i]!=i)
            i = parent[parent[i]];

        //Tree compression
        parent[value] = i;
        return i;
    }

    void Union(int i,int j)
    {
        int first = Find(i);
        int second = Find(j);
        if(first==second)
            return;
        else
        {
            //To keep the tree height minimum
            if(rank[first]>rank[second])
            {
                parent[second]=first;
            }
            else
            {
                parent[first]=second;
                if(rank[first]==rank[second])
                {
                    rank[second]++;
                }
            }   
        }
    }

    bool isconnected(int i,int j)
    {
        int first = Find(i);
        int second = Find(j);
        if(first==second)
            return true;
        return false;
    }


};

class Edge
{
  public:
    int p1;
    int p2;
    double distance;
    Edge(int point1,int point2,double dis): p1(point1) , p2(point2) , distance(dis){}

};


bool cmp(const Edge &a,const Edge &b)
{
    return a.distance < b.distance;
}

double weight(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}



double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  //write your code here
  vector<Edge> edges;
  int n = x.size();
  for(int i = 0;i<n-1;i++)
  {
      for(int j = i+1;j<n;j++)
      {
            double distance = weight(x[i],y[i],x[j],y[j]);
            edges.push_back(Edge(i,j,distance));
      }
  }

  vector<int> visited(n,0);
  sort(edges.begin(),edges.end(),cmp);
  int u = edges.size();
  Sets set(n);

  for(int i = 0;i<edges.size();i++)
  {
      int p1 = edges[i].p1;
      int p2 = edges[i].p2;
      double distance  = edges[i].distance;
      if(!set.isconnected(p1,p2))
      {
        set.Union(p1,p2);
        result+=distance;
      }
  }
  
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
