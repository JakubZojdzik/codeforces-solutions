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
#define rep(i, x, y) for (ll i = (ll)x; i <= (ll)y; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define nl '\n'

ll a[200007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        ll n, k, x;
        cin >> n >> k >> x;
        ll s = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        sort(a, a + n);

        for (ll i = 0; i < x; i++)
        {
            if (n - 1 - i < 0)
                break;
            s -= 2 * a[n - 1 - i];
        }
        ll res = s;
        // cout << "s: " << s << '\n';

        for (ll i = 0; i < k; i++)
        {
            if(n - 1 - x - i >= 0)
                s -= 2 * a[n - 1 - x - i];
            if(n - 1 - i >= 0)
                s += a[n - 1 - i];
            // cout << "i: " << i << ", s: " << s << '\n';
            res = max(res, s);
        }
        cout << res << '\n';
    }
}

/*
1
4 1 1
3 1 2 4

odp: 2
*/
