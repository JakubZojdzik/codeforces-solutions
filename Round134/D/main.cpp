/*
    Jakub Żojdzik
    27-08-2022
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
typedef vector<int> vi;

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define nl cout << '\n'

pii a[100007], b[100007];

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
            cin >> a[i].se;
            a[i].fi = 0;
        }
        for(int i = 0; i < n; i++)
        {
            cin >> b[i].se;
            b[i].fi = 0;
        }
        a[n].fi = -1;
        b[n].fi = -1;
        int x1, y1, x0, y0, w = 0;
        vi poz;
        int grp = 0;
        for(int i = 30; i >= 0; i--)
        {
            x1 = 0; y1 = 0; x0 = 0; y0 = 0;
            bool ok = 1;
            sort(a, a+n);
            sort(b, b+n);
            
            for(int j = 0; j < n; j++)
            {
                if(a[j].se & (1 << i))
                    x1++;
                else
                    x0++;

                if(b[j].se & (1 << i))
                    y1++;
                else
                    y0++;
                if(j == n-1 || a[j+1].fi != a[j].fi)
                {
                    if(x1 != y0 || x0 != y1)
                    {
                        ok = 0;
                        break;
                    }
                }
            }
            if(ok)
            {
                debug(i);
                // cout << "Swierzo po sorcie:\n";
                // for(int j = 0; j < n; j++)
                //     cout << "a[" << j << "] = (" << a[j].se << ", " << a[j].fi << ")\n";
                // for(int j = 0; j < n; j++)
                //     cout << "b[" << j << "] = (" << b[j].se << ", " << b[j].fi << ")\n";
                w += pow(2, i);
                int ter_grp = a[0].fi;
                for(int j = 0; j < n; j++)
                {
                    if(a[j].se & (1 << i))
                    {
                        a[j].fi = grp+1;
                        // cout << "a[" << j << "] = grp+1 = " << grp+1 << '\n';
                    }
                    if(!(b[j].se & (1 << i)))
                    {
                        b[j].fi = grp+1;
                        // cout << "b[" << j << "] = grp+1 = " << grp+1 << '\n';
                    }
                    if(a[j+1].fi != ter_grp)
                    {
                        ter_grp = a[j+1].fi;
                        grp++;
                        // cout << "zmiana grupy w " << j << " grp=" << grp << '\n';
                    }
                }
                debug(grp);
                // for(int j = 0; j < n; j++)
                // {
                //     cout << "a[" << j << "] = (" << a[j].se << ", " << a[j].fi << ")\n";
                // }
                // for(int j = 0; j < n; j++)
                // {
                //     cout << "b[" << j << "] = (" << b[j].se << ", " << b[j].fi << ")\n";
                // }
            }
        }
        
        cout << w << '\n';
    }
}

/*
1
5
1 0 0 3 3
2 3 2 1 0

1
8
28 14 12 27 10 8 27 27
5 23 17 2 21 19 6 22
odp: 12


1
5
4 2 7 11 25
27 29 24 20 6
odp: 31


1
8
0 1 2 3 4 5 6 7
7 6 5 4 3 2 1 0
*/