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

priority_queue<ll> a;

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        ll n, m, tmp;
        cin >> n >> m;
        while(!a.empty())
        {
            a.pop();
        }
        for(int i = 0; i < n; i++)
        {
            cin >> tmp;
            a.push(-tmp);
        }
        for(int i = 0; i < m; i++)
        {
            cin >> tmp;
            a.pop();
            a.push(-tmp);
        }

        ll res = 0;
        while(!a.empty())
        {
            res += a.top();
            a.pop();
        }
        cout << -res << '\n';
    }
}

/*
4
3 2
1 2 3
4 5
2 3
1 2
3 4 5
1 1
100
1
5 3
1 1 1 1 1
1000000000 1000000000 1000000000
*/