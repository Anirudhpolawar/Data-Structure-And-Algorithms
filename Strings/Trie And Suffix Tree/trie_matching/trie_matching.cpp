#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters =    4;
int const NA      =   -1;

struct Node
{
	int next [Letters];

	Node ()
	{
		fill (next, next + Letters, NA);
	}

	bool isLeaf () const
	{
	    return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
	}
};

int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}

void ConstructTrie(vector<Node> &t,const vector<string> &patterns)
{
	Node temp;
	t.push_back(temp);
	for(string s : patterns)
	{
		int cur  = 0;
		for(char val : s)
		{
			int numval = letterToIndex(val);
			if(t[cur].next[numval] != -1)
			{
				cur = t[cur].next[numval];
			}
			else
			{
				t[cur].next[numval] = t.size();
				cur = t.size();
				Node temp;
				t.push_back(temp);
				
			}
			
		}
	}
}

vector <int> solve (const string& text, int n, const vector <string>& patterns)
{
	vector <int> result;
	vector <Node> t;
	ConstructTrie(t,patterns);
	int textsize = text.size();
	for(int i = 0;i<textsize;i++)
	{
		int flag = 0;
		int cur = 0;
		for(int j = i;j<textsize;j++)
		{
				int numval = letterToIndex(text[j]);
				if(t[cur].isLeaf())
				{
					flag = 1;
					break;
				}
				else if(t[cur].next[numval]==-1)
				{
					break;
				}
				else
				{
					cur = t[cur].next[numval];
				}
				
		}

		if(flag==1||t[cur].isLeaf())
			result.push_back(i);
	}


	// write your code here

	return result;
}

int main (void)
{
	string t;
	cin >> t;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (t, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}
