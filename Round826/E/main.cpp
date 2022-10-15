/*
    Jakub Żojdzik
    11-10-2022
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

bool wch[200007], dp[200007];
ll b[200007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ll t;
    cin >> t;
    rep(T, 1, t)
    {
        ll n;
        cin >> n;
        rep(i, 1, n)
        {
            cin >> b[i];
            dp[i] = 0;
            wch[i] = 0;
        }
        dp[0] = 1;
        if(b[1] + 1 <= n)
            wch[b[1]+1] = 1;
        for(ll i = 2; i <= n; i++)
        {
            if(i - b[i] - 1 >= 0)
            {
                if(dp[i - b[i] - 1])
                {
                    dp[i] = 1;
                }
            }
            if(wch[i]) dp[i] = 1;
            if(dp[i-1])
            {
                if(i+b[i] <= n)
                    wch[i+b[i]] = 1;
            }
        }
        if(dp[n]) cout << "YES\n";
        else cout << "NO\n";
    }
}

/*
1
6
5 7 8 9 10 3
*/