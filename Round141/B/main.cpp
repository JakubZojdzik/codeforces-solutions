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
        vi num;
        for(int i = 1; i <= (n*n)/2; i++)
        {
            num.pb(i);
            num.pb(n*n-i+1);
        }
        if(n % 2 == 1) num.pb((n*n)/2+1);

        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 1)
            {
                for(int j = i*n; j < i*n+n; j++)
                {
                    cout << num[j] << " ";
                }
            }
            else
            {
                for(int j = i*n+n-1; j >= i*n; j--)
                {
                    cout << num[j] << " ";
                }
            }
            nl;
        }
    }
}

/*

*/