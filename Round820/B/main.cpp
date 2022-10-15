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
        string s, w;
        cin >> s;
        for(int i = n-1; i >= 0; i--)
        {
            // debug(i, s[i]);
            if(s[i] == '0')
            {
                // debug(i, "tu");
                int a;
                a = (s[i-2]-'0') * 10;
                a += (s[i-1]-'0');
                w = char(a+'a'-1) + w;
                i -= 2;
            }
            else
            {
                w = char(int(s[i] - '0')+'a'-1) + w; 
            }
            // debug(w);
        }
        cout << w << '\n';
    }
}

/*
1
6
315045
*/