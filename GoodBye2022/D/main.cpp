/*
    Jakub Żojdzik
    30-12-2022
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

constexpr ll MOD = 998244353;

ll a[100007], b[100007];
set<ll> ust;
ll par[100007], roz[100007];
ll wiel1[100007], wiel2[100007];
bitset<100007> jed;

int f(int a)
{
    if(par[a] == a) return a;
    return (par[a] = f(par[a]));
}

void u(int a, int b)
{
    a = f(a);
    b = f(b);
    if(a != b)
    {
        if(roz[a] > roz[b]) swap(a, b);
        par[a] = b;
        roz[b] += roz[a];
    }
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        ll n;
        cin >> n;
        rep(i, 1, n)
            cin >> a[i];
        rep(i, 1, n)
            cin >> b[i];

        rep(i, 1, n)
        {
            par[i] = i;
            roz[i] = 1;
        }
        rep(i, 1, n)
            u(a[i], b[i]);

        rep(i, 1, n)
        {
            wiel1[i] = 0;
            wiel2[i] = 0;
        }
        rep(i, 1, n)
        {
            wiel1[f(a[i])]++;
            wiel2[f(i)]++;
        }
        bool ok = 1;
        jed.reset();
        rep(i, 1, n)
        {
            debug(i, wiel1[i], wiel2[i]);
            if(wiel1[f(i)] != wiel2[f(i)]) ok = 0;
            if(a[i] == b[i]) jed[f(a[i])] = 1;
        }
        if(!ok)
        {
            cout << "0\n";
            continue;
        }

        ll res = 1;
        rep(i, 1, n)
        {
            if(i != par[i]) continue;
            if(jed[i]) res = (res * n) % MOD;
            else res = (res * 2) % MOD;
        }

        cout << res << '\n';
    }
}

/*
1
3
1 2 2
1 3 3
*/