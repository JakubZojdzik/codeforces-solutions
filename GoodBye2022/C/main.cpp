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

ll a[107];
ll prim[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271};
set<ll> seen;

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        ll n;
        cin >> n;
        seen.clear();
        bool ok = 1;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(seen.count(a[i])) ok = 0;
            seen.insert(a[i]);
        }
        if(!ok)
        {
            cout << "NO\n";
            continue;
        }
        for(ll i = 0; i <= 50; i++)
        {
            bool ter = 1;
            // debug(i, prim[i]);
            for(ll j = 0; j < prim[i]; j++)
            {
                ll akt = 0;
                // debug(j);
                for(ll k = 0; k < n; k++)
                {
                    if(a[k] % prim[i] == j)
                    {
                        akt++;
                        // debug(k, a[k]);
                    }
                }
                if(akt < 2) ter = 0;
                // debug(ter);
            }
            if(ter) ok = 0;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}

/*
1
3
5 7 10
*/