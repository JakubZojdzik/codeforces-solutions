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

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        int n, x, y;
        string s1, s2;
        cin >> n >> x >> y >> s1 >> s2;
        vi poz;
        for(int i = 0; i < n; i++)
        {
            if(s1[i] != s2[i])
            {
                poz.pb(i);
            }
        }
        if(sz(poz) % 2 == 1)
        {
            cout << "-1\n";
        }
        else if(sz(poz) == 2 && poz[0] == poz[1]-1)
        {
            cout << min(x, 2*y) << '\n';
        }
        else
        {
            cout << (sz(poz) / 2) * y << '\n';
        }
    }
}

/*

*/