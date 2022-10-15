/*
    Jakub Żojdzik
    12-10-2022
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
#define rep(i, x, y) for (ll i = (ll)x; i <= (ll)y; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define nl cout << '\n'

pll ac[100007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ll n, w = 0, poz;
    cin >> n;
    rep(i, 1, n)
    {
        cin >> ac[i].fi >> ac[i].se;
    }
    sort(ac + 1, ac + n + 1);
    poz = ac[1].fi;

    debug(w, poz);
    rep(i, 1, n)
    {
        debug(i, ac[i]);
        if (poz < ac[i].fi)
        {
            w += ac[i].fi - poz;
            debug("dodaje", ac[i].fi - poz);
        }
        poz = max(poz, ac[i].fi + ac[i].se);
        w += ac[i].se;
        debug(w, poz);
    }
    cout << w << '\n';
}

/*
6
4 2
8 4
3 0
2 3
7 1
0 1
*/