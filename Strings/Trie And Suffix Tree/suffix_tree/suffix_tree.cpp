#include <iostream>
#include <map>
#include<unordered_map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::unordered_map;
using std::string;
using std::vector;


struct Node
{
	unordered_map<char,int> next;

	bool isleaf()
	{
	   return next.size()==0;
	}

  bool issingle()
  {
    return next.size()==1;
  }

};


void ConstructTrie(vector<Node> &t,const string &text)
{
      Node temp;
      t.push_back(temp);
      int n = text.size();
      for(int i = 0;i<n;i++)
      {
            int cur = 0;
            for(int j = i;j<n;j++)
            {
                  if(t[cur].next.find(text[j])!=t[cur].next.end())
                  {
                      cur = t[cur].next[text[j]];
                  }
                  else
                  {
                      t[cur].next[text[j]] = t.size();
                      cur = t.size();
                       Node temp;
                        t.push_back(temp);    
                  }   
            }
      }
}


void travelcollect(vector<string> &result,int cur,vector<Node> &t,string still)
{
    if(t[cur].isleaf())
    {
        if(still.length()>0)
            result.push_back(still);
    }
    else if(t[cur].issingle())
    {
            char c = (t[cur].next.begin())->first;
            still.push_back(c);
            travelcollect(result,(t[cur].next.begin())->second,t,still);
    }
    else
    {
           if(still.length()>0)
            result.push_back(still);
          
          still.clear();
          map<char,int>::iterator itr;
          for(itr = t[cur].next.begin();itr!=t[cur].next.end();itr++)
          {
              string temp = "";
              temp.push_back(itr->first);
              travelcollect(result,itr->second,t,temp);
          }
    }
       
}



// Build a suffix tree of the string text and return a vector
// with all of the labels of its edges (the corresponding 
// substrings of the text) in any order.
vector<string> ComputeSuffixTreeEdges(const string& text) {
  vector<string> result;
  // Implement this function yourself
  vector<Node> t;
  ConstructTrie(t,text);
  string  temp = "";
  travelcollect(result,0,t,temp);
  return result;
}

int main() {
  string text;
  cin >> text;
  vector<string> edges = ComputeSuffixTreeEdges(text);
  for (int i = 0; i < edges.size(); ++i) {
    cout << edges[i] << endl;
  }
  return 0;
}
