/*
    Jakub Żojdzik
    31-07-2022
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

    int t, n, m;
    string a, b;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        cin >> n >> m >> a >> b;
        bool ok = true, ok2 = false;
        for(int i = 0; i < m-1; i++)
        {
            if(a[n-1-i] != b[m-1-i]) ok = false;
        }
        if(ok)
        {
            for(int i = 0; i < n - m + 1; i++)
            {
                if(a[i] == b[0]) ok2 = true;
            }
        }

        if(ok && ok2) cout << "YES\n";
        else cout << "NO\n";
    }
}

/*
1
6 2
001001
11
*/ 