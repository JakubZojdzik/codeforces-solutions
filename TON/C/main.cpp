/*
    Jakub Żojdzik
    31-07-2022
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

ll a[100007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ll t, n, m;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        sort(a, a + m);
        vector<ll> odst;
        if (n - a[m - 1] + a[0] - 1 > 0)
        {
            odst.pb(n - a[m - 1] + a[0] - 1);
        }
        for (int i = 0; i < m - 1; i++)
        {
            if (a[i + 1] - a[i] -1 > 0)
                odst.pb(a[i + 1] - a[i] - 1);
        }
        sort(all(odst));
        // debug(odst);
        ll minelo = 0, wynik = m;
        for (int i = odst.size() - 1; i >= 0; i--)
        {
            if (minelo * 2 >= odst[i])
            {
                wynik += odst[i];
            }
            else if (odst[i] - minelo * 2 == 1)
            {
                wynik += 2 * minelo;
                minelo++;
            }
            else
            {
                wynik += 2 * minelo + 1;
                minelo += 2;
            }
            
            // debug(i, odst[i], wynik);
        }
        cout << wynik << '\n';
    }
}

/*
1
10 3
3 6 8
*/