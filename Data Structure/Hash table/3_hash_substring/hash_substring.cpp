#include <iostream>
#include <string>
#include <vector>

using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

std::vector<int> get_occurrences(const Data& input) {

    const string& s = input.pattern, t = input.text;
    long long n = t.length();
    long long m = s.length();

    std::vector<int> ans;

    long long d = 256;
    long long h = 1;
    long long curhash  = 0;
    long long patternhash = 0;
    long long prime = 100000000007;
    long long i = 0;
    long long j = 0;

    for(i = 0;i<m-1;i++)
    {
        h = (h*d)%prime;
    }

    for(i = 0;i<m;i++)
    {
        curhash = (curhash * d + t[i])%prime;
        patternhash = (patternhash * d + s[i])%prime;
    }

    for(i = 0; i <= n - m; i++)
    {
        if(curhash == patternhash)
        {
            if(t.substr(i,m)==s)
                ans.push_back(i);
        }
        

        if(i<n)
        {
            curhash = (((d * (curhash - t[i]*h) + t[i+m])%prime)+prime)%prime;
        }
        
    }
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
