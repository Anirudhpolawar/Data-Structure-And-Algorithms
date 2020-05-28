#include <iostream>
#include<algorithm>
#include <vector>
#include<utility>

using std::vector;
using std::min;
using std::pair;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {

  vector<int> cnt(points.size());
  int i = 0;
  int j = 0;
  int u = 0;
  int count = 0;
  
  vector<pair<int,int> > locpuspoints(points.size());
  for(int i = 0;i<points.size();i++)
  {
      locpuspoints[i] = std::make_pair(points[i],i);
  }


  sort(starts.begin(),starts.end());
  sort(ends.begin(),ends.end());
  sort(locpuspoints.begin(),locpuspoints.end());

  while(j<starts.size()&&i<points.size())
  {
      int val = min(ends[u],min(locpuspoints[i].first,starts[j]));
      if(val == starts[j])
      {
          j++;
          count++;
      }
      else if(val == locpuspoints[i].first)
      {
        cnt[locpuspoints[i].second] = count;
        i++;
      }
      else
      {
          u++;
          count--;
      }
      
  }

  while(u<ends.size()&&i<points.size())
  {
    int val = min(ends[u],locpuspoints[i].first);
      if(val == locpuspoints[i].first)
      {
        cnt[locpuspoints[i].second] = count;
        i++;
      }
      else
      {
          u++;
          count--;
      }
  }

  while(i<points.size())
 {
      cnt[locpuspoints[i].second] = count;
      i++;
 }
 
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = naive_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
