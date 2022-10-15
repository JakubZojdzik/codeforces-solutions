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

ll a[200007], b[200007], odp[200007], blok[200007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        for(int i = 0; i < n; i++)
        {
            odp[i] = lower_bound(b, b+n, a[i]) - b;
            cout << b[odp[i]] - a[i] << " ";
        }
        cout << '\n';

        int akt = n;
        for(int i = n-1; i >= 0; i--)
        {
            blok[i] = akt;
            // debug(i, blok[i]);
            if(odp[i] == i) akt = i;
        }
        for(int i = 0; i < n; i++)
        {
            cout << b[blok[i]-1] - a[i] << " ";
        }
        cout << '\n';
    }
}

/*
3
2 3 5
7 11 13


1 5
2 2 7 8 9
2 3 8 8 9

*/