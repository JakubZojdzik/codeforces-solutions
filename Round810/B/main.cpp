/*
    Jakub Żojdzik
    24-07-2022
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
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define nl cout << '\n'

vi kraw[100007];
ll tab[100007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ll t, n, m, x, y;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
        {
            cin >> tab[i];
            kraw[i].clear();
        }
        for(int i = 1; i <= m; i++)
        {
            cin >> x >> y;
            kraw[x].pb(y);
            kraw[y].pb(x);
        }
        if(m % 2 == 0)
        {
            cout << "0\n";
            continue;
        }
        ll wynik = LONG_LONG_MAX;
        for(int i = 1; i <= n; i++)
        {
            if(kraw[i].size() % 2 == 1)
            {
                wynik = min(wynik, tab[i]);
            }
            else
            {
                for(int j = 0; j < (int)kraw[i].size(); j++)
                {
                    ll nast = kraw[i][j];
                    if(kraw[nast].size() % 2 == 0)
                    {
                        wynik = min(wynik, tab[i]+tab[nast]);
                    }
                }
            }
        }
        cout << wynik;
        nl;
    }
}

/*

*/