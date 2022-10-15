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

int tab[2007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        int n, w1 = -1, najw = -1, najm = 2000;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> tab[i];
        }
        for(int i = 1; i < n; i++)
        {
            najw = max(najw, tab[i]);
        }
        for(int i = 0; i < n-1; i++)
        {
            najm = min(najm, tab[i]);
        }
        w1 = tab[n-1] - tab[0];
        for(int i = 0; i < n-1; i++)
        {
            w1 = max(w1, tab[i] - tab[i+1]);
        }
        w1 = max(w1, najw - tab[0]);
        w1 = max(w1, tab[n-1] - najm);
        cout << w1 << '\n';
    }
}

/*

*/