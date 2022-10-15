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

ll a[200007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ll t, n, x;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        cin >> n >> x;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        ll dol = max((ll)0, a[0] - x), gora = a[0] + x, wynik = 0;
        for(int i = 1; i < n; i++)
        {
            if(dol <= a[i]+x && gora >= a[i]-x)
            {
                dol = max(dol, a[i]-x);
                gora = min(gora, a[i]+x);
            }
            else
            {
                wynik++;
                dol = max((ll)0, a[i] - x);
                gora = a[i] + x;
            }
        }
        cout << wynik << '\n';
    }
}

/*
1
8 2
2 4 6 8 6 4 12 14
*/