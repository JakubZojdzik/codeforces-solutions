/*
    Jakub Żojdzik
    19-09-2022
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

ll a[107];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ll t;
    cin >> t;
    rep(T, 1, t)
    {
        ll n, k;
        cin >> n >> k;
        rep(i, 1, n)
        {
            cin >> a[i];
        }
        ll w = 0, wakt;
        rep(i, 1, k)
        {
            wakt = 0;
            for(int j = i; j <= n; j += k)
            {
                wakt = max(wakt, a[j]);
            }
            w += wakt;
        }
        cout << w << '\n';
    }
}

/*

*/