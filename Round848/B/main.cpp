/*
    Jakub Żojdzik
    01-02-2023
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

int p[100007], a[100007], poz[100007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        int n, m, d;
        cin >> n >> m >> d;
        for(int i = 0; i < n; i++)
        {
            cin >> p[i];
            poz[p[i]] = i;
        }
        for(int i = 0; i < m; i++)
        {
            cin >> a[i];
        }

        int w = 1e6;
        for(int i = 0; i < m-1; i++)
        {
            w = min(w, poz[a[i+1]] - poz[a[i]]);
            if(d < n-1 && poz[a[i]] < poz[a[i+1]])
                w = min(w, d - (poz[a[i+1]] - poz[a[i]]) + 1);
        }
        cout << max(w, 0) << '\n';
    }
}

/*
1
2 2 1
2 1
1 2

1
6 2 4
1 2 3 4 5 6
2 5

1
5 2 4
5 4 3 2 1
5 2
*/