/*
    Jakub Żojdzik
    27-12-2022
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

ll tab[1000007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        ll temp;
        bool ok = 1;
        for(ll i = 0; i < m; i++)
        {
            cin >> tab[i];
            tab[i] = -tab[i];
        }
        sort(tab, tab+m);
        if(m < k)
        {
            cout << "NO\n";
            continue;
        }
        for(int i = 0; i < m; i++)
        {
            temp = n / k;
            if(n % k)
            {
                n--;
                temp++;
            }
            if(temp < -tab[i]) ok = 0;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}

/*
2
12 6 2
1 1 1 1 1 7
12 6 2
2 2 2 2 2 2
*/