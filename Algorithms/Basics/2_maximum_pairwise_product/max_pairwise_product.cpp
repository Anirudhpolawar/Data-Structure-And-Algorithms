#include <iostream>
#include<cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

long long  MaxPairwiseProduct(const  vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product =  max(max_product,(long long)numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const  vector<int> &number)
{
    
    int max1 = 0;
    int max2 = 0;

    for(int i = 0;i<number.size();i++)
    {
        if(number[i]>max1)
        {
            max2 = max1;
            max1 = number[i];
        }
        else if(number[i]>max2)
        {
            max2 = number[i];
        }
    }

    long long ans = (long long)max1 *max2;
    return ans;

}

int main() {
    //stress check
    // while(true)
    // {
    //     int n = rand() % 1000 + 2;
    //      vector<int> v(n,0);
    //      cout<<n<<"\n";
    //     for(int i = 0;i<n;i++)
    //     {
    //         v[i] = rand()%100000;
    //          cout<<v[i]<<" ";
    //     }
    //      cout<<"\n";
    //     long long ans1 = MaxPairwiseProduct(v);
    //     long long ans2 = MaxPairwiseProductFast(v);
    //     if(ans1!=ans2)
    //     {
    //          cout<<"Wrong ans"<<ans1<<" "<<ans2<<"\n";
    //          break;
    //     }
    //     else
    //     {
    //          cout<<"okau"<<"\n";
    //     }
        
    // }
    int n;
     cin >> n;
     vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
         cin >> numbers[i];
    }

     cout << MaxPairwiseProductFast(numbers)<< "\n";
    return 0;
}
