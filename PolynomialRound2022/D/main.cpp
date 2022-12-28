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

int wier[100007];
vi bior[100007];
vi dawc[100007];


int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        int n, m;
        cin >> n >> m;
        bool x;
        int jed = 0;
        bool tab[n+1][m+1];
        for(int i = 0; i < n; i++)
        {
            wier[i] = 0;
            for(int j = 0; j < m; j++)
            {
                cin >> x;
                tab[i][j] = x;
                jed += x;
                wier[i] += x;
            }
        }

        if(jed % n != 0)
        {
            cout << "-1\n";
            continue;
        }
        int srod = jed / n;
        for(int j = 0; j < m; j++)
        {
            dawc[j].clear(); bior[j].clear();
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(wier[i] - srod < 0 && !tab[i][j])
                {
                    bior[j].pb(i);
                }
                if(wier[i] - srod > 0 && tab[i][j])
                {
                    dawc[j].pb(i);
                }
            }
        }

        for(int j = 0; j < m; j++)
        {
            debug(j, dawc[j], bior[j]);
        }

        dt;
        vector<tuple<int, int, int>> w;
        for(int j = 0; j < m; j++)
        {
            debug(j);
            while(sz(dawc[j]) && sz(bior[j]))
            {
                int w1 = dawc[j].back(), w2 = bior[j].back();
                if(!(srod - wier[w1]))
                {
                    dawc[j].pop_back();
                    continue;
                }
                if(!(srod - wier[w2]))
                {
                    bior[j].pop_back();
                    continue;
                }

                w.pb({w1, w2, j});
                wier[w1]--; wier[w2]++;
                debug(w1, w2, wier[w1], wier[w1]);
                dawc[j].pop_back(); bior[j].pop_back();
            }
        }
        cout << sz(w) << '\n';
        for(int i = 0; i < sz(w); i++)
        {
            cout << get<0>(w[i])+1 << " " << get<1>(w[i])+1 << " " << get<2>(w[i])+1 << '\n';
        }
    }
}

/*
1
3 4
1 1 1 0
0 0 1 0
1 0 0 1
*/