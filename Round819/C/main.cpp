/*
    Jakub Żojdzik
    06-09-2022
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

int closing[100007];
vi kraw[100007];
bool seen[100007];

void dfs(int a)
{
    seen[a] = 1;
    for(int i = 0; i < sz(kraw[a]); i++)
    {
        if(!seen[kraw[a][i]])
        {
            dfs(kraw[a][i]);
        }
    }
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        stack<int> op;
        rep(i, 0, 2*n)
        {
            closing[i] = -1;
        }
        for(int i = 0; i < 2*n; i++)
        {
            if(s[i] == '(')
            {
                op.push(i+1);
            }
            else
            {
                closing[i+1] = op.top();
                op.pop();
            }
        }
        rep(i, 0, 2*n)
        {
            kraw[i].clear();
        }
        rep(i, 1, 2*n)
        {
            if(s[i-1] == ')')
            {
                kraw[i].pb(closing[i]);
                kraw[closing[i]].pb(i);
                debug(i, closing[i]);
                if(i < 2*n && s[i] == '(')
                {
                    kraw[i].pb(i+1);
                    kraw[i+1].pb(i);
                    debug(i, i+1);
                }
            }
        }

        int w = 0;
        rep(i, 0, 2*n) seen[i] = 0;
        rep(i, 1, 2*n)
        {
            if(!seen[i])
            {
                w++;
                dfs(i);
            }
        }
        cout << w << '\n';
    }
}

/*
1
4
(())(())

*/