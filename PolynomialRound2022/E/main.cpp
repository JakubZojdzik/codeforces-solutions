/*
    Jakub Żojdzik
    28-12-2022
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

vi kraw[200007];
int a1[200007], a2[200007];
int parent[200007];
int pre[200007];
bitset<200007> tree1, tree2;
int n, d;
vi S;

void setup(int v = 1, int from = 1)
{
    parent[v] = from;
    if(sz(S) >= d)
    {
        pre[v] = S[sz(S)-d];
    }
    else
    {
        pre[v] = 1;
    }
    S.push_back(v);
    for(int i = 0; i < sz(kraw[v]); i++)
    {
        if(kraw[v][i] != from)
        {
            setup(kraw[v][i], v);
        }
    }
    S.pop_back();
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int a, b;
    cin >> n >> d;

    for(int i = 0; i < n-1; i++)
    {
        cin >> a >> b;
        kraw[a].pb(b);
        kraw[b].pb(a);
    }
    int m1, m2;
    cin >> m1;
    for(int i = 0; i < m1; i++)
    {
        cin >> a1[i];
    }
    cin >> m2;
    for(int i = 0; i < m2; i++)
    {
        cin >> a2[i];
    }

    setup();

    tree1[1] = 1;
    tree2[1] = 1;
    for(int i = 0; i < m1; i++)
    {
        int akt = a1[i];
        while(akt != 1)
        {
            if(tree1[akt]) break;
            tree1[akt] = 1;
            akt = parent[akt];
        }
        akt = pre[a1[i]];
        while(akt != 1)
        {
            if(tree2[akt]) break;
            tree2[akt] = 1;
            akt = parent[akt];
        }
    }
    for(int i = 0; i < m2; i++)
    {
        int akt = a2[i];
        while(akt != 1)
        {
            if(tree1[akt]) break;
            tree2[akt] = 1;
            akt = parent[akt];
        }
        akt = pre[a2[i]];
        while(akt != 1)
        {
            if(tree1[akt]) break;
            tree1[akt] = 1;
            akt = parent[akt];
        }
    }

    cout << (tree1.count() + tree2.count() - 2) * 2 << '\n';
}

/*
9 2
1 2
2 4
4 5
1 3
3 6
3 7
7 8
8 9
3 4 5 6
2 3 9
*/