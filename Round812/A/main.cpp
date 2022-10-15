/*
    Jakub Żojdzik
    14-08-2022
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
    for (int T = 0; T < t; T++)
    {
        int n, a, b, q = 0, w = 0, e = 0, r = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            if (a > 0)
            {
                q = max(q, a);
            }
            if (a < 0)
            {
                w = max(w, -a);
            }
            if (b > 0)
            {
                e = max(e, b);
            }
            if (b < 0)
            {
                r = max(r, -b);
            }
        }
        cout << (q + w + e + r) * 2 << '\n';
    }
}

/*

*/