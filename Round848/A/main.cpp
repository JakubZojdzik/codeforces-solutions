/*
    Jakub Żojdzik
    01-02-2023
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

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        int n, xd, sum = 0, popr = 0;
        cin >> n;
        bool x1 = 0, x2 = 0, x3 = 0;
        rep(i, 0, n-1)
        {
            cin >> xd;
            if(i >= 1)
            {
                if(xd == popr && xd == -1) x1 = 1;
                if(xd != popr) x3 = 1;
            }
            sum += xd;
            popr = xd;
        }
        if(x1) cout << sum + 4;
        else if(x3) cout << sum;
        else cout << sum-4;
        nl;
    }
}

/*

*/