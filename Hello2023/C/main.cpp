/*
    Jakub Żojdzik
    04-01-2023
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

ll a[200007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        priority_queue<pll> pq;
        for(int i = m-1; i > 0; i--)
        {
            pq.push({a[i], i});
        }
        ll sum = 0;
        for(int i = m; i >= 0; i--)
        {
            sum += a[i];
        }

    }
}

/*
1, 2, -4, -6, 1, -1, 10
1, 3, -1, -7, -6, -7, 2
*/