/*
    Jakub Żojdzik
    23-11-2022
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

int a[300007];
int wchodz[300007];
int dp[300007];
bitset<207> bylo;
vi kraw[300007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        bylo.reset();
        int n;
        cin >> n;
        rep(i, 0, n-1)
        {
            cin >> a[i];
            bylo[a[i]] = 1;
        }
        rep(i, 0, 199)
        {
            if(!bylo[i]) continue;
            rep(j, i+1, 200)
            {
                if(!bylo[j]) continue;
                if((a[i] ^ j) < (a[j] ^ i))
                {
                    kraw[j].pb(i);
                    cout << i << " -> " << j << '\n';
                }
            }
        }
        int w = 0;
        rep(i, 0, 200)
        {
            dp[i] = 1;
            rep(j, 0, sz(kraw[i])-1)
            {
                dp[i] += dp[j];
            }
            w = max(dp[i], w);
        }
        cout << w << '\n';
    }

}

/*
1
10
9 2 1 1 2 5 2 10 3 3
odp: 7


9  2  1  1  2  5  2  10  3  3

1  2  3  5  9  10

1  1  2  4  1  1
*/