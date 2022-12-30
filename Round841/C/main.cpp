/*
    Jakub Żojdzik
    30-12-2022
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

// int a[300007];
vi kwad;
int seen[300007][457];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    for(int i = 0; i * i <= 10; i++)
    {
        kwad.pb(i*i);
    }
    rep(T, 1, t)
    {
        ll najw = 1;
        int n, a, akt = 0, res = 0;
        cin >> n;
        while(najw <= n) najw <<= 1;
        for(int i = 0; i <= najw; i++)
            for(int j = 0; j <= 450; j++)
                seen[i][j] = 0;
        for(int i = 0; i <= 450; i++)
            seen[0][i] = 1;
        for(int i = 0; i < n; i++)
        {
            cin >> a;
            akt = a ^ akt;
            for(int j = 0; j < sz(kwad) && kwad[j] <= najw; j++)
            {
                ll reszt = kwad[j] ^ akt;
                if(seen[reszt][j])
                {
                    res += seen[reszt][j];
                    debug(i, j, kwad[j]);
                }
                if(a == kwad[j])
                {
                    res++;
                    debug(i, j, kwad[j]);
                }
                seen[reszt][j]++;
                debug(i, j, akt);
                debug(kwad[j], reszt, seen[reszt][j]);
            }
        }
        debug(res);
        cout << max(0, (n * (n-1)) / 2 + n - res) << '\n';
    }
}

/*
1
7
5 7 3 7 1 7 3
*/