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

constexpr ll MOD = 998244353; 

vector<ll> kraw[1007];
vector<ll> kraw2[1007];
ll val[1007];
ll moc[1007];
ll wchodz[1007];
ll seen[1007];
vector<ll> rzad[1007];
queue<ll> pocz;

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t, n, m, x, y;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> val[i];
            seen[i] = 0;
            moc[i] = 0;
            wchodz[i] = 0;
            kraw[i].clear();
            kraw2[i].clear();
            rzad[i].clear();
        }
        while(!pocz.empty()) pocz.pop();
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            kraw[y].pb(x);
            kraw2[x].pb(y);
            moc[x]++;
            wchodz[y]++;
        }
        ll start;
        for (int i = 1; i <= n; i++)
        {
            if (moc[i] == 0)
                start = i;
            if(wchodz[i] == 0)
                pocz.push(i);
        }

        queue<ll> kol;
        kol.push(start);
        // debug(start);
        seen[start] = 1;
        ll wiersz = 2;
        while (!kol.empty())
        // for(int Q = 0; Q < 10; Q++)
        {
            ll s = kol.size();
            // cout << "s = " << s << '\n';
            for (int i = 0; i < s; i++)
            {
                ll w = kol.front();
                kol.pop();
                // cout << "w = " << w << ", kol.front = " << kol.front() << '\n';
                for (int j = 0; j < (ll)kraw[w].size(); j++)
                {
                    // cout << "dodaje " << kraw[w][j] << '\n';
                    kol.push(kraw[w][j]);
                    seen[kraw[w][j]] = wiersz;
                    // debug(seen[kraw[w][j]], kraw[w][j]);
                }
            }
            wiersz++;
            wiersz = (wiersz % MOD);
        }





        while (!pocz.empty())
        // for(int Q = 0; Q < 10; Q++)
        {
            ll s = pocz.size();
            // cout << "s = " << s << '\n';
            for (int i = 0; i < s; i++)
            {
                ll w = pocz.front();
                pocz.pop();
                // cout << "w = " << w << ", kol.front = " << kol.front() << '\n';
                for (int j = 0; j < (ll)kraw[w].size(); j++)
                {
                    // cout << "dodaje " << kraw[w][j] << '\n';
                    pocz.push(kraw[w][j]);
                    val[kraw[w][j]] += val[w];
                    // seen[kraw[w][j]] = wiersz;
                    // debug(seen[kraw[w][j]], kraw[w][j]);
                }
            }
        }

        // for(int i = wiersz; i >= 1; i--)
        // {
        //     for(int j = 0; j < rzad[i].size(); j++)
        //     {
        //         int akt = rzad[i][j];
        //         for(int k = 0; k < kraw2[akt].size(); k++)
        //         {
        //             val[kraw2[akt][k]] = (val[akt] % val[kraw2[akt][k]]) % MOD;
        //         }
        //     }
        // }

        ll wynik = 0;
        for (int i = 0; i < n; i++)
        {
            if(val[i])
                wynik = max(wynik, (seen[i] + val[i] - 1) % MOD);
        }
        cout << wynik << '\n';
    }
}

/*
1
6 9
10 10 10 10 10 10
1 2
1 3
2 3
4 3
6 3
3 5
6 5
6 1
6 2


1
5 5
1 0 0 0 0
1 2
2 3
3 4
4 5
1 5


1
3 2
1 1 1
1 2
2 3
*/