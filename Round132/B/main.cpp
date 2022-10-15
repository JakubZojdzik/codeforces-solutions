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

ll teren[100007];
ll pref[100007], suf[100007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ll n, m, s, t;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> teren[i];
    }
    for(int i = 1; i < n; i++)
    {
        pref[i] = pref[i-1] + min(ll(0), teren[i+1] - teren[i]);
    }
    for(int i = n; i >= 1; i--)
    {
        suf[i] = suf[i+1] + min(ll(0), teren[i] - teren[i+1]);
    }
    for(int i = 0; i < n; i++)
    {
        debug(i, pref[i], suf[i]);
    }
    for(int M = 0; M < m; M++)
    {
        cin >> s >> t;
        if(s < t)
        {
            cout << -(pref[t-1] - pref[s-1]) << '\n';
        }
        else
        {
            cout << -(suf[t] - suf[s]) << '\n';
        }
    }
}

/*

*/