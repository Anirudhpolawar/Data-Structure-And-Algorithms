#include <iostream>
#include<algorithm>
#include <vector>
#include<utility>

using std::vector;
using std::pair;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int curweight = 0.0;

  // write your code here
  vector< pair<double,int> > ratio_values_weight;

  for(int i = 0;i<weights.size();i++)
  {
      ratio_values_weight.push_back(std::make_pair((double)values[i]/weights[i],i));
  }

  sort(ratio_values_weight.begin(),ratio_values_weight.end());

  for(int i = ratio_values_weight.size()-1;i>=0;i--)
  {
    int loc = ratio_values_weight[i].second;
    if(curweight+weights[loc]<=capacity)
    {
      curweight +=weights[loc];
      value+= (double) values[loc];
    }
    else
    {
        int leftcapacity = capacity - curweight;
        value+= (double) values[loc]*((double)leftcapacity/weights[loc]);
        break;
    }

  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
