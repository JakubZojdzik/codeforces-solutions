/*
    Jakub Żojdzik
    21-07-2022
*/

#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.hpp"
#define dt cout << "HERE!\n"
#else
#define debug(...)
#define dt
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define nl cout << '\n'

ll h[200007];

ll tree[1000007];
ll limit = 1;

ll query(ll a, ll b)
{
    ll wynik = max(h[a], h[b]);
    if(a == b)
    {
        return h[a];
    }
    a = limit+a;
    b = limit+b;
    while((a>>1) != (b>>1))
    {
        if(a%2 == 0)
        {
            wynik = max(wynik, tree[a+1]);
        }
        if(b%2 == 1)
        {
            wynik = max(wynik, tree[b-1]);
        }
        a >>= 1;
        b >>= 1;
    }
    return wynik;
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ll n, m, q, x1, y1, x2, y2, k;
    cin >> n >> m;
    while (limit <= m)
    {
        limit <<= 1;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> h[i];
        tree[limit+i] = h[i];
    }

    for(int i = limit; i > 0; i--)
    {
        tree[i] = max(tree[2*i], tree[2*i+1]);
    }

    cin >> q;
    for (int Q = 0; Q < q; Q++)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        ll najm = 0;
        if(y1 > y2)
        {
            swap(y1, y2);
            swap(x1, x2);
        }
        if(h[y1] >= x1 || h[y2] >= x2 || najm > n || abs(y2-y1) % k != 0 || abs(x2-x1) % k != 0)
        {
            cout << "NO\n";
            continue;
        }
        najm = query(y1, y2) + 1;
        debug(najm);
        if(((n-x1) / k) * k < (najm - x1) || ((n-x2) / k) * k < (najm - x2))
        {
            cout << "NO\n";
        }
        else cout << "YES\n";
    }
}

/*
10 10
2 10 1 5 2 0 6 10 2 7
1
7 7 7 1 3



11 10
9 0 0 10 3 4 8 11 10 8
1
5 3 11 5 2
*/