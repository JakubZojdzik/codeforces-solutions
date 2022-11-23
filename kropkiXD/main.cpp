/*
    Jakub Żojdzik
    17-10-2022
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

map<pll, ll> vek;
vpll inp;

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ll t;
    cin >> t;
    rep(T, 1, t)
    {
        ll n, a, b, c, d;
        cin >> n;
        rep(i, 1, n)
        {
            cin >> a >> b >> c >> d;
            c -= a;
            d -= b;
            vek[{a/__gcd(a, b), b/__gcd(a, b)}]++;
            inp.pb({a/__gcd(a, b), b/__gcd(a, b)});
        }

        ll w = 0;
        rep(i, 1, n)
        {
            w += vek[inp[i]] * vek[{-inp[i].fi, -inp[i].se}];
        }

        cout << w/2 << '\n';
    }
}

/*

*/