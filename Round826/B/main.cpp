/*
    Jakub Żojdzik
    11-10-2022
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
#define rep(i, x, y) for (ll i = (ll)x; i <= (ll)y; i++)
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
        int n;
        cin >> n;
        if (n == 3)
        {
            cout << "-1\n";
            continue;
        }
        if (n % 2 == 0)
        {
            for (int i = n; i >= 1; i--)
            {
                cout << i << " ";
            }
            nl;
        }
        else
        {
            cout << n << " " << n-1 << " ";
            for (int i = 1; i <= n-2; i++)
            {
                cout << i << " ";
            }
            nl;
        }
    }
}

/*

*/