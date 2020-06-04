#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::pair;
using std::make_pair;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }


  void shiftdown(int i,vector<pair<long long,int>> &workers,int n)
  {
    
      int minindex = i;
      int left = 2*i+1;
      if(left<n&&workers[minindex].first>workers[left].first)
      {
          minindex = left;
      }
      else if(left<n && workers[minindex].first==workers[left].first && workers[minindex].second>workers[left].second)
      {
        minindex = left;
      }
      int right = 2*i+2;
       if(right<n && workers[minindex].first>workers[right].first)
      {
          minindex = right;
      }
      else if(right<n && workers[minindex].first==workers[right].first && workers[minindex].second>workers[right].second)
      {
        minindex = right;
      }

      if(minindex==i)
        return;
      else
      {
            swap(workers[minindex],workers[i]);
            shiftdown(minindex,workers,n);
      }
      
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<pair<long long,int>> workers(num_workers_);
    for(int i = 0;i<num_workers_;i++)
    {
        workers[i].first = 0;
        workers[i].second = i;
    }
      
    for (int i = 0; i < jobs_.size(); ++i) {
      assigned_workers_[i] = workers[0].second;
      start_times_[i] = workers[0].first;
     workers[0].first = workers[0].first+ jobs_[i];
      shiftdown(0,workers,num_workers_);
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
