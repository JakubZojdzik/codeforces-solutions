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
int dp[300007];

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
        rep(i, 0, n-1)
        {
            cin >> a[i];
            dp[i] = 1;
        }
        int w = 0;
        rep(i, 0, n-1)
        {
            for(int j = max(0LL, i-520); j < i; j++)
                if((a[j]^i) < (a[i]^j)) dp[i] = max(dp[i], dp[j]+1);
            w = max(dp[i], w);
        }

        cout << w << '\n';
    }
}

/*
1
2
1 2

1
5
5 2 4 3 1

0 1 2 3 4
1: 1
2: 2
3: 2
4: 3
5: 3


1
10
9 2 1 1 2 5 2 10 3 3
odp: 7


9  2  1  1  2  5  2  10  3  3

1  2  3  5  9  10

1  1  2  4  1  1
*/