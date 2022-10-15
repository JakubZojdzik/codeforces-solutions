/*
    Jakub Żojdzik
    12-09-2022
*/

#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.hpp"
#else
#define debug(...)
#define dt
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<long long, long long>> vpll;

#define fi first
#define se second
#define pb push_back
#define rep(i, x, y) for(ll i = (ll)x; i <= (ll)y; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define nl cout << '\n'

int x[100007], y[100007], z[100007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        int n;
        cin >> n;
        rep(i, 1, n)
        {
            cin >> x[i];
        }
        rep(i, 1, n)
        {
            cin >> y[i];
            z[i] = y[i] - x[i];
        }
        sort(z+1, z+n+1);
        int a = 1, b = n, w = 0;
        while(a < b)
        {
            if(z[a] + z[b] >= 0)
            {
                w++;
                debug(a, b, z[a], z[b], w);
                a++;
                b--;
            }
            else
            {
                a++;
            }
        }
        cout << w << '\n';
    }
}

/*
1
6
1 4 1 2 4 2
1 3 3 2 3 4
*/