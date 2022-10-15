/*
    Jakub Żojdzik
    19-09-2022
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
        ll n, a, b;
        cin >> n >> a >> b;
        if(a+b == 0 || (a != 0 && b != 0))
        {
            cout << "-1\n";
            continue;
        }
        a = max(a, b);
        if((n-1) % a != 0)
        {
            cout << "-1\n";
            continue;
        }
        ll ludz = (n-1)/a, ter = 1;
        for(int i = 1; i <= ludz; i++)
        {
            for(int j = 1; j <= a; j++)
            {
                cout << ter << " ";
            }
            ter += a+1;
        }
        cout << '\n';
    }
}

/*

*/