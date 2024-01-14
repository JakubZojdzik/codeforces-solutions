/*
    Jakub Żojdzik
    13-01-2024
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
typedef vector<long long> vl;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<long long, long long>> vpll;

#define fi first
#define se second
#define pb push_back
#define rep(i, x, y) for(ll i = (ll)x; i <= (ll)y; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define nl '\n'

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        ll n;
        cin >> n;
        ll a, x;
        vl z1, z2, z3;
        for (ll i = 0; i < n; i++)
        {
            cin >> a >> x;
            if(a == 1) // >=
                z1.pb(x);
            else if(a == 2) // <=
                z2.pb(x);
            else if(a == 3) // !=
                z3.pb(x);
        }
        ll pocz = 0;
        ll kon = 1e9 + 2;
        for(auto tmp : z1)
        {
            pocz = max(pocz, tmp);
        }
        for(auto tmp : z2)
        {
            kon = min(kon, tmp);
        }
        // cout << "pocz:" << pocz << " kon:" << kon << '\n';

        debug(pocz, kon);

        ll res = kon - pocz + 1;
        for(auto tmp : z3)
        {
            if(tmp >= pocz && tmp <= kon)
                res--;
        }
        cout << max(0ll, res) << '\n';
    }
}

/*
1
4
1 3
2 10
3 1
3 5
*/
