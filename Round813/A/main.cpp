/*
    Jakub Żojdzik
    13-08-2022
*/

#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.hpp"
#define dt cout << "HERE!\n"
#else
#define debug(...)
#define dt
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define nl cout << '\n'

int p[107];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        int k, n;
        int w = 0;
        cin >> n >> k;
        for(int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        for(int i = 0; i < k; i++)
        {
            if(p[i] > k)
            {
                w++;
            }
        }
        cout << w << '\n';
    }


    // for(int T = 0; T < t; T++)
    // {
    //     dt;
    //     int n, k, w = 0;
    //     cin >> k >> n;
    //     for(int i = 1; i <= n; i++)
    //     {
    //         cin >> p[i];
    //     }
    //     for(int i = 1; i <= k; i++)
    //     {
    //         if(p[i] > k) w++;
    //         cout << i << '\n';
    //     }
    //     cout << w << '\n';
   
    // }
}

/*

*/