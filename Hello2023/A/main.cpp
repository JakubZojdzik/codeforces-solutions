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

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        int n;
        string s;
        cin >> n >> s;

        int w = -1;
        for(int i = 0; i < n-1; i++)
        {
            if(s[i] == 'R' && s[i+1] == 'L')
            {
                w = 0;
                break;
            }
            if(s[i] == 'L' && s[i+1] == 'R')
            {
                w = i+1;
                break;
            }
        }
        cout << w << '\n';
    }
}

/*
6
2
LL
2
LR
2
RL
2
RR
7
LLRLLLR
7
RRLRRRL
*/