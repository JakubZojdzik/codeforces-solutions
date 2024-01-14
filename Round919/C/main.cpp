/*
    Jakub Żojdzik
    13-01-2024
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
typedef vector<long long> vl;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<long long, long long>> vpll;

#define fi first
#define se second
#define pb push_back
#define rep(i, x, y) for (ll i = (ll)x; i <= (ll)y; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define nl '\n'

int a[200007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int res = 1;
        for (int i = 2; i <= n; i++)
        {
            if (n % i == 0)
            {
                int proba = 0;
                for (int j = 0; j < n - n / i; j++)
                {
                    int nast = abs(a[j + n / i] - a[j]);
                    proba = __gcd(proba, nast);
                }

                if (proba != 1)
                {
                    res++;
                }
            }
        }

        cout << res << '\n';
    }
}

/*
1
4
1 2 1 4
*/
