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
typedef pair<int, int> pii;
typedef vector<int> vi;

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define nl cout << '\n'

ll base = 1;
ll tree[2000007];
pair<ll, ll> obc[2000007]; // baza, inkrement
pair<ll, ll> maszty[1000007];

void add(ll p, ll k, ll x, ll inkr, ll v = 1, ll a = 0, ll b = base - 1) // na przedziale [p, k] dodaj x z inkrementem inkr, zaczynając od v który jest nad przedziałem [a, b]
{
    if (a > k || b < p)
        return;
    if (p <= a && k >= b)
    {
        ll pierw = x + (a - p) * inkr;
        ll ost = pierw + (b - a) * inkr;
        tree[v] += (b - a + 1) * (pierw + ost) / 2;
        obc[v].first += pierw;
        obc[v].second += inkr;
    }
    else
    {
        ll l = v << 1, r = (v << 1) + 1, mid = (a + b) >> 1;

        ll asrod = obc[v].first + ((b - a + 1) / 2) * obc[v].second;
        tree[l] += ((obc[v].first * 2 + ((b - a + 1) / 2 - 1) * obc[v].second) * (b - a + 1) / 2) / 2;
        tree[r] += ((asrod + obc[v].first + (b - a) * obc[v].second) * (b - a + 1) / 2) / 2;
        obc[l].first += obc[v].first;
        obc[l].second += obc[v].second;
        obc[r].first += asrod;
        obc[r].second += obc[v].second;
        obc[v] = {0, 0};

        add(p, k, x, inkr, l, a, mid);
        add(p, k, x, inkr, r, mid + 1, b);

        tree[v] = tree[l] + tree[r];
    }
}

ll query(ll p, ll k, ll v = 1, ll a = 0, ll b = base - 1) // na przedziale [p, k] dodaj x, zaczynając od v który jest nad przedziałem [a, b]
{
    if (a > k || b < p)
        return 0;
    if (p <= a && k >= b)
    {
        return tree[v];
    }
    else
    {
        ll l = v << 1, r = (v << 1) + 1, mid = (a + b) >> 1;

        ll asrod = obc[v].first + ((b - a + 1) / 2) * obc[v].second;
        tree[l] += ((obc[v].first * 2 + ((b - a + 1) / 2 - 1) * obc[v].second) * (b - a + 1) / 2) / 2;
        tree[r] += ((asrod + obc[v].first + (b - a) * obc[v].second) * (b - a + 1) / 2) / 2;
        obc[l].first += obc[v].first;
        obc[l].second += obc[v].second;
        obc[r].first += asrod;
        obc[r].second += obc[v].second;
        obc[v] = {0, 0};
        return query(p, k, l, a, mid) + query(p, k, r, mid + 1, b);
    }
}

ll silnia[200007];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    ll t;
    cin >> t;
    silnia[0] = 1;
    silnia[1] = 1;
    for(int i = 2; i < 200004; i++)
    {
        silnia[i] = silnia[i-1] * i;
    }

    for(int T = 0; T < t; T++)
    {
        string s;
        cin >> s;
        cout << ((s.size() * (s.size()-1) * (s.size() - 2)) / 6) << '\n'; 
    }
}

/*

*/