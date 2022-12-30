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

ll a[100007], b[100007];
set<ll> ust;

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
        for(ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(ll i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        ll perm = 1;
        for(ll i = 0; i < n; i++)
        {
            if(ust.count(a[i]) || ust.count(b[i])) continue;

        }
    }
}

/*

*/