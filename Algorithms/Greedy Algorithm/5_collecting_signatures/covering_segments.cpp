#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool cmp(Segment a,Segment b)
{
  return a.start < b.start;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  sort(segments.begin(),segments.end(),cmp);
  int maxleft = segments[0].start;
  int minright = segments[1].end;
  for(int i = 0;i<segments.size();i++)
  {
    minright = std::min(minright,segments[i].end);
    if(minright<segments[i].start)
    {
        points.push_back(maxleft);
        minright = segments[i].end;
    }
    maxleft = segments[i].start;
  }
  points.push_back(maxleft);
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
