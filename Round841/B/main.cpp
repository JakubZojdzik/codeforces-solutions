/*
    Jakub Żojdzik
    29-12-2022
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

constexpr ll MOD = 1e9+7;

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        ll n;
        cin >> n;
        ll w = n;
        w = (w % MOD);
        w *= n+1;
        w = (w % MOD);
        w *= (4*n-1) % MOD;
        w = (w % MOD);
        debug(w);
        w *= 337;
        w = (w % MOD);

        cout << w << '\n';
    }
}

/*

*/