/*
    Jakub Żojdzik
    08-01-2023
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

int a[60];

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
        rep(i, 0, n-1)
        {
            cin >> a[i];
        }

        sort(a, a+n);
        if(a[0] == a[n-1])
        {
            cout << "NO\n";
            continue;
        }
        else
        {
            cout << "YES\n" << a[0] << " ";
            for(int i = n-1; i >= 1; i--)
            {
                cout << a[i] << " ";
            }
            nl;
        }
    }
}

/*
4
4
3 3 6 6
2
10 10
5
1 2 3 4 5
3
1 4 4
*/