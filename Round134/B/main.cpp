/*
    Jakub Żojdzik
    27-08-2022
*/

#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.hpp"
#define dt cout << "HERE!\n"
#else
#define debug(...)
#define dt
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define nl cout << '\n'

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;
        if((sx - d <= 1 && sx + d >= n) || (sy - d <= 1 && sy + d >= m) || (sx - d <= 1 && sy - d <= 1) || (sx + d >= n && sy + d >= m))
        {
            cout << "-1\n";
        }
        else 
        {
            cout << n + m - 2 << '\n';
        }
    }
}

/*

*/