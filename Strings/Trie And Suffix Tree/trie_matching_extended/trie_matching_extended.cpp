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
	bool patternEnd;

	Node ()
	{
		fill (next, next + Letters, NA);
		patternEnd = false;
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
		int cur = 0;
		for(char val : s)
		{
			int numval = letterToIndex(val);
			if(t[cur].next[numval]!=-1)
			{
				cur = t[cur].next[numval];
			}
			else
			{
				t[cur].next[numval] = t.size();
				cur  = t.size();
				Node temp;
				t.push_back(temp);
			}
		}
		t[cur].patternEnd = true;
	}
}

vector <int> solve (string text, int n, vector <string> &patterns)
{
	vector <int> result;

	// write your code here
	vector<Node> t;
	ConstructTrie(t,patterns);
	int length = text.length();
	for(int i = 0;i<length;i++)
	{
		int cur = 0;
		for(int j = i;j<length;j++)
		{
			int numval = letterToIndex(text[j]);
			if(t[cur].next[numval]==-1)
			{
				break;
			}
			else if(t[cur].patternEnd)
			{
				break;
			}
			else
			{
				cur = t[cur].next[numval];
			}	
		}

		if(t[cur].patternEnd)
			result.push_back(i);
	}

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
