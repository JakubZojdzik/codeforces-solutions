/*
    Jakub Żojdzik
    12-09-2022
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

pair<char, int> nap[200007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        string s;
        cin >> s;
        vpii w;
        rep(i, 1, sz(s)-2)
        {
            if(s[i] >= min(s[0], s[sz(s)-1]) && s[i] <= max(s[0], s[sz(s)-1]))
            {
                w.pb({s[i], i});
            }
        }
        sort(all(w));
        cout << abs(s[sz(s)-1] - s[0]) << " " << sz(w)+2 << '\n';
        cout << "1 ";
        if(s[0] <= s[sz(s)-1])
        {
            for(auto x : w)
            {
                cout << x.se+1 << ' ';
            }
        }
        else
        {
            for(int i = sz(w)-1; i >= 0; i--)
            {
                cout << w[i].se+1 << " ";
            }
        }
        cout << sz(s) << '\n';
    }
}

/*
1
baaa

1
logic
*/