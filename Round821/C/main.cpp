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

int a[100007];

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
            cin >> a[i];
        }
        if(n == 1)
        {
            cout << "0\n";
            continue;
        }

        vpii mv;
        mv.pb({1, n});
        if(a[1] + a[n] % 2 == 0)
        {
            a[1] = a[n];
        }
        else a[n] = a[1];
        rep(i, 2, n-1)
        {
            if((a[1] % 2) != (a[i] % 2))
            {
                mv.pb({1, i});
            }
        }
        for(int i = n-1; i >= 2; i--)
        {
            if(((a[1] % 2) == (a[i] % 2)))
            {
                mv.pb({i, n});
            }
        }

        cout << sz(mv) << '\n';
        rep(i, 0, sz(mv)-1)
        {
            cout << mv[i].fi << " " << mv[i].se << '\n';
        }
    }
}

/*

*/