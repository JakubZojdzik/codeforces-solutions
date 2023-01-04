/*
    Jakub Żojdzik
    04-01-2023
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

int a[200007];

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
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int akt = 0;
        pii najm = {INT_MAX, -1};
        for(int i = 0; i < m; i++)
        {
            akt += a[i];
            najm = min(najm, {akt, i});
        }
        priority_queue<int> pq;
        for(int i = najm.se+1; i < m; i++)
        {
            if(a[i] > 0) pq.push(i);
        }
        while((!pq.empty()) && (akt > 0))
        {
            akt -= a[pq.top()];
            a[pq.top()] = -a[pq.top()];
            pq.pop();
        }
    }
}

/*

*/