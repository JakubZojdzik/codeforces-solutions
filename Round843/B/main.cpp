/*
    Jakub Żojdzik
    10-01-2023
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

int licz[200007];
vi tab[100007];

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
        for(int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            for(int j = 0; j < k; j++)
            {
                int p;
                cin >> p;
                licz[p]++;
                tab[i].pb(p);
            }
        }
        bool res = 0;
        for(int i = 0; i < n; i++)
        {
            bool ok = 1;
            for(int x : tab[i])
            {
                if(licz[x] <= 1)
                {
                    ok = 0;
                    break;
                }
            }
            if(ok) res = 1;
        }
        if(res) cout << "YES\n";
        else cout << "NO\n";

        for(int i = 0; i < n; i++)
        {
            for(int x : tab[i])
            {
                licz[x] = 0;
            }
        }
        for(int i = 0; i < n; i++)
        {
            tab[i].clear();
        }
    }
}

/*

*/