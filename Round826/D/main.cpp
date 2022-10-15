/*
    Jakub Żojdzik
    11-10-2022
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

ll p[300007][20];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        ll m;
        cin >> m;
        ll h = 0, temp = m;
        while(temp)
        {
            temp /= 2;
            h++;
        }
        debug(h);
        rep(i, 1, m)
        {
            cin >> p[i][0];
        }
        ll w = 0;
        bool ok = 1;
        for(int k = 0; k < h-1; k++)
        {
            debug(k);
            for(int i = 1; i <= m; i += pow(2, k+1))
            {
                debug(i);
                if(p[i][k] == p[i+ll(pow(2, k))][k] - pow(2, k))
                {
                    p[i][k+1] = p[i+ll(pow(2, k))][k];
                    // cout << "p[" << i << "][" << k+1 << "] = " << p[i][k+1] << '\n'; 
                    debug("dobrze");
                }
                else if(p[i][k] == p[i+ll(pow(2, k))][k] + pow(2, k))
                {
                    w++;
                    p[i][k+1] = p[i][k];
                    // cout << "p[" << i << "][" << k+1 << "] = " << p[i][k+1] << '\n'; 
                    debug("zle");
                }
                else
                {
                    debug("fatalnie");
                    ok = 0;
                    break;
                }
            }
        }
        if((!ok))
        {
            cout << "-1\n";
            continue;
        }
        cout << w << '\n';
    }
}

/*
1
8
6 5 7 8 4 3 1 2
*/