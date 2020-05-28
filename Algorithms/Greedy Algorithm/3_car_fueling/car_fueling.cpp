#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int curfuel = tank;
    int refills = 0;
    int loc = 0;
    stops.push_back(dist);
    for(int i = 0;i<stops.size();i++)
    {
            if(stops[i]-loc>curfuel)
            {
                refills++;
                curfuel = tank - (stops[i]-loc);

                if(curfuel<0)
                    return -1;
            }
            else
            {
                curfuel-=(stops[i]-loc);
            }
            
            loc = stops[i]; 
    }

    return refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
