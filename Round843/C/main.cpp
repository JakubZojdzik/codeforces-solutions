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

vll pot;

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    ll tmp = 1;
    while(tmp <= 2e18)
    {
        pot.pb(tmp);
        tmp *= 2;
    }

    rep(T, 1, t)
    {
        ll a, b;
        cin >> a >> b;
        if(b > a)
        {
            cout << "-1\n";
            continue;
        }
        if(a == b)
        {
            cout << a << '\n';
            continue;
        }

        ll at = a, bt = b, roz = 0, itr = 0;
        bool ok = 1, bylo = 0;
        while(at)
        {
            if((at & 1) == 1 && (bt & 1) == 0)
            {
                if(bylo)
                {
                    ok = 0;
                    break;
                }
                roz = itr;
            }
            if((at & 1) == 0 && (bt & 1) == 1)
            {
                ok = 0;
                break;
            }
            if((at & 1) == 1 && (bt & 1) == 1)
            {
                bylo = 1;
            }
            bt /= 2;
            at /= 2;
            itr++;
        }
        if((a & (1LL << (roz+1))) || !ok)
        {
            cout << "-1\n";
            continue;
        }

        ll res = pot[roz+1];
        ll odj = 0;
        for(ll i = roz; i >= 0; i--)
        {
            if(a & (1LL << i))
            {
                odj += pot[i];
                res -= pot[i];
            }
        }
        cout << a + res << '\n';
    }
}

/*
1
3 1


5
10 8
10 10
10 42
20 16
1000000000000000000 0


1
21 16
*/