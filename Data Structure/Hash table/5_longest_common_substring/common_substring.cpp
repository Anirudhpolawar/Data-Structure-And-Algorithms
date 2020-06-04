#include <iostream>
#include<unordered_map>
#include<vector>

using namespace std;



class HashOfString
{
	public:
	string s;
	vector<long long> hash1;
	vector<long long> power1;
	vector<long long> hash2;
	vector<long long> power2;
	long long p = 31;
	long long m1 = 1e9 + 7;
	long long m2 = 1e9 + 9;
	int n;
	HashOfString(string value)
	{
		n = value.length();
		s = value;
		hash1.resize(n+1,0);
		power1.resize(n+1,1);
		power2.resize(n+1,1);
		hash2.resize(n+1,0);
		
		cout<<"\n hash value : ";
		for(int i = 1;i<=n;i++)
		{
			power1[i] = (power1[i-1]*p)%m1;
			power2[i] = (power2[i-1]*p)%m2;
			hash1[i] = (hash1[i-1] + s[i-1]*power1[i-1])%m1;
			hash2[i] = (hash2[i-1] + s[i-1]*power2[i-1])%m2;
			 cout<<hash1[i]<<"  ";
		}
		cout<<"\n";

		
	}

	vector<long long> gethash(int i,int l)
	{
		vector<long long> ans;

		long long first = (hash1[i+l]+m1 - hash1[i])%m1;
		first = (first * power1[n-i-1])%m1;
		ans.push_back(first);
		
		long long second = (hash2[i+l]+m2 - hash2[i])%m2;
		second =  (second * power2[n-i-1])%m2;
		ans.push_back(second);

		return ans;
	}

};
void build_hash(string &s,vector<long long> &hash,vector<long long> &power1,vector<long long> &hash2,vector<long long> &power2)
{
	

}

struct Answer {
	size_t i, j, len;
};

Answer solve(const string &s, const string &t) {
	Answer ans = {0, 0, 0};
	for (size_t i = 0; i < s.size(); i++)
		for (size_t j = 0; j < t.size(); j++)
			for (size_t len = 0; i + len <= s.size() && j + len <= t.size(); len++)
				if (len > ans.len && s.substr(i, len) == t.substr(j, len))
					ans = {i, j, len};
	return ans;
}

long long compute_hash1(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

long long compute_hash2(string const& s) {
    const int p = 31;
    const int m = 1e9 + 7;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

Answer solve2(const string &s,const string &t)
{
	Answer ans = {0,0,0};
	

	int n = s.length();
	if(t.length()<n)
		n = t.length();
	
	int p = s.length();
	int q = t.length();

	for(int i = n;i>0;i--)
	{
		unordered_map<long long,int> m1;
		unordered_map<long long,int> m2;
		for(int j = 0;j<=p-i;j++)
		{
			vector<long long> temp;
			 temp.push_back(compute_hash1(s.substr(j,i)));
			 temp.push_back(compute_hash2(s.substr(j,i)));
			 
				 m1[temp[0]] = j;
				m2[temp[1]] = j;
			
			
		}
		
		for(int j =0;j<=q-i;j++)
		{
			vector<long long> temp;
			 temp.push_back(compute_hash1(t.substr(j,i)));
			 temp.push_back(compute_hash2(t.substr(j,i)));
			if(m1.find(temp[0])!=m2.end()&&m2.find(temp[1])!=m2.end())
			{
				if(m1[temp[0]]==m2[temp[1]])
				{
					ans.i = m1[temp[0]];
					ans.j = j;
					ans.len = i;
					return ans;
				}
			}
		}
	}

	return ans;

}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	string s, t;
	while (cin>>s>>t) {
		auto ans = solve2(s,t);
		cout << ans.i << " " << ans.j << " " << ans.len << "\n";

	}
}
