#include <iostream>
#include<vector>
#include<set>

using namespace std;

class Solver {
	string s;
public:	
	vector<long long> h1;
	vector<long long> h2;
	vector<long long> powers;
	vector<long long> powers2;
	const long long m1 = 1e9 + 7;
	const long long m2 = 1e9 + 9;
	const long long x = 31;
	int n;
	Solver(string s) : s(s) {
		n = s.length();
		h1.resize(n+1,0);
		h2.resize(n+1,0);
		powers.resize(n+1,1);
		powers2.resize(n+1,1);

		h1[0] = 0;
		for(int i = 1;i<=n;i++)
		{
			powers[i] = (powers[i-1]*x)%m1;
			powers2[i] = (powers2[i-1]*x)%m2;
			h1[i] = (h1[i-1] + s[i-1]*powers[i-1])%m1;
			h2[i] = (h2[i-1] + s[i-1]*powers2[i-1])%m2;
		}

	}

	bool ask(int a, int b, int l) {

		long long first = (h1[a+l]+m1 -h1[a])%m1;
		long long second = (h1[b+l]+m1 - h1[b])%m1;
		first = (first * powers[n-a-1])%m1;
		second = (second * powers[n-b-1])%m1;

		long long first2 = (h2[a+l]+m2 -h2[a])%m2;
		long long second2 = (h2[b+l]+m2 - h2[b])%m2;
		first2 = (first2 * powers2[n-a-1])%m2;
		second2 = (second2 * powers2[n-b-1])%m2;
		
		if((first==second)&&(first2==second2))
			return true;
		return false;
		
	}

	bool ask2(int a, int b, int l) {
		return s.substr(a, l) == s.substr(b, l);
	}
};


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}

	//Stress Check
	// int n = s.size();
	// int flag =1;
	// for(int i = 0;i<s.size()&&flag;i++)
	// {
	// 	for(int j = 0;j<n&&flag;j++)
	// 	{
	// 		for(int l = 1;l<=n-j;l++)
	// 		{
	// 			cout<<i<<"  "<<j<<"   "<<l<<"  "<<" status :  ";
	// 			if(solver.ask(i, j, l)==solver.ask2(i,j,l))
	// 				cout<<"OK\n";
	// 			else
	// 			{
	// 				cout<<"Not Okay \n";
	// 				flag = 0;
	// 				cout<<"expected "<<solver.ask2(i,j,l)<<" But Got "<<solver.ask(i,j,l)<<"\n";
	// 				break;
	// 			}
				
	// 		}
	// 	}
	// }
	// if(flag==1)
	// 	cout<<"sucessfully completed\n";
}
