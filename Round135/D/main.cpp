/*
    Jakub Żojdzik
    08-09-2022
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

string s;
int dp[2007][2007];

bool dyn(int a, int b)
{
    if(dp[a][b] != -1)
    {
        return dp[a][b];
    }
    if(a == b-1)
    {
        dp[a][b] = (s[a] != s[b]);
        return (s[a] != s[b]);
    }
    bool x1, x2, x3;

    if(s[a] == s[b]) x2 = dyn(a+1, b-1);
    else x2 = 1;

    if(!x2) 
    {
        dp[a][b] = 0;
        return 0;
    }

    if(s[a] == s[a+1]) x1 = dyn(a+2, b);
    else x1 = 1;

    if(s[b] == s[b-1]) x3 = dyn(a, b-2);
    else x3 = 1;

    
    if(!x2)
    {
        dp[a][b] = 0;
        return 0;
    }
    if((!x1) && (!x3))
    {
        dp[a][b] = 0;
        return 0;
    }
    dp[a][b] = 1;
    return 1;
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        cin >> s;
        rep(i, 0, sz(s))
            rep(j, 0, sz(s))
                dp[i][j] = -1;

        if((sz(s) & 1) == 0)
        {
            int x = dyn(0, sz(s)-1);
            switch (x)
            {
            case 0:
                cout << "Draw\n";
                break;
            
            case 1:
                cout << "Alice\n";

            default:
                break;
            }
        }
        else
        {
            cout << "Bob\n";
        }
    }
}

/*
1
baaa

1
abba

1
bbaa
*/