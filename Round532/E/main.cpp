/*
    Jakub Żojdzik
    29-08-2022
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

vector<pair<ll, ll>> kraw[100007], reverted[100007];
vector<tuple<ll, ll, ll>> inp;
bool seen[100007];
ll ingoing[100007];
ll layer[100007];
stack<ll> S;
ll n, m, a, b, c;

void dfs(ll a, ll lvl)
{
    seen[a] = true;
    for(ll i = 0; i < ll(kraw[a].size()); i++)
        if((!seen[kraw[a][i].fi]) && kraw[a][i].se > lvl)
            dfs(kraw[a][i].fi, lvl);
    S.push(a);
}

void dfs2(ll a, ll lvl)
{
    seen[a] = true;
    for(ll i = 0; i < ll(reverted[a].size()); i++)
        if(!seen[reverted[a][i].fi] && reverted[a][i].se > lvl)
            dfs2(reverted[a][i].fi, lvl);
}

bool is_cycle(ll lvl)
{
    while(!S.empty()) S.pop();
    for(ll i = 1; i <= n; i++) seen[i] = false;
    for(ll i = 1; i <= n; i++) if(!seen[i]) dfs(i, lvl);
    for(ll i = 1; i <= n; i++) seen[i] = false;
    ll res = 0;
    while(!S.empty())
    {
        ll v = S.top();
        debug(v, res, lvl);
        S.pop();
        if(!seen[v]) 
        {
            res++;
            dfs2(v, lvl);
        }
    }
    return (res < n);
}


int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        kraw[a].push_back({b, c});
        reverted[b].push_back({a, c});
        inp.pb({a, b, c});
    }

    ll p, k, s;
    p = 0;
    k = 1e9 + 7;
    if(!is_cycle(0))
    {
        cout << "0 0\n";
        return 0;
    }
    while (p + 1 < k)
    {
        s = (p + k) / 2;
        if (is_cycle(s))
        {
            p = s;
        }
        else
        {
            k = s;
        }
    }
    debug(k);
    queue<ll> q;
    for(ll i = 1; i <= n; i++)
    {
        seen[i] = 0;
    }
    for(ll i = 0; i < m; i++)
    {
        if(get<2>(inp[i]) > k)
            ingoing[get<1>(inp[i])]++;
    }
    for(ll i = 1; i <= n; i++)
    {
        debug(i, ingoing[i]);
        if(ingoing[i] == 0)
        {
            q.push(i);
        }
    }

    ll act = 0;
    while(!q.empty())
    {
        ll top = q.front();
        layer[top] = act;
        debug(top, layer[top]);
        act++;
        q.pop();
        for(ll i = 0; i < ll(kraw[top].size()); i++)
        {
            if (kraw[top][i].se <= k)
                continue;
            ingoing[kraw[top][i].fi]--;
            if(ingoing[kraw[top][i].fi] <= 0)
            {
                q.push(kraw[top][i].fi);
            }
        }
    }

    vi w;
    for(ll i = 0; i < m; i++)
    {
        if(get<2>(inp[i]) <= k)
        {
            if(layer[get<0>(inp[i])] > layer[get<1>(inp[i])])
            {
                w.pb(i+1);
            }
        }
    }
    cout << k << " " << w.size() << '\n';
    for(auto x : w)
    {
        cout << x << " ";
    }
    nl;
}

/*
10 16
1 4 8
1 2 8
10 4 1
9 10 1
10 8 1
1 3 2
7 1 7
10 6 7
1 6 8
9 1 4
10 3 3
1 5 7
10 2 9
10 5 3
10 7 7
1 8 7
*/