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

ll a[1000007];

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
            cin >> a[i];
        }
        ll w = n;
        rep(i, 1, n)
        {
            debug(i);
            bool ok = 1;
            ll sum = 0, dl = 0, aktdl = 0;
            for(int j = 0; j < i; j++)
            {
                sum += a[n-j];
                dl++;
            }
            debug(sum, dl);
            ll mam = 0;
            for(int j = n-i; j >= 1; j--)
            {
                mam += a[j];
                if(mam > sum) 
                {
                    ok = 0;
                    continue;
                }
                aktdl++;
                dl = max(dl, aktdl);
                if(mam == sum)
                {
                    mam = 0;
                    aktdl = 0;
                }
            }
            if(ok && mam == 0)
            {
                w = min(dl, w);
            }
        }

        cout << w << '\n';
    }
}

/*
1
6
4 1 1 1 1 4
*/