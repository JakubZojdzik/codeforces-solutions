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

ll c[300007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ll t, n, m;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> c[j];
            }

            ll temp = 0;
            for (int j = 0; j < m-2; j++)
            {
                temp += c[j+2] - c[j];
            }
            debug(i, temp);

            dt;
            temp = 0;
            for (int j = 0; j < m-1; j++)
            {
                temp += c[j+1] - c[j];
            }
            debug(i, temp);
            nl; nl;
        }
    }
}

/*
7
3 9
0 1 2 0 0 2 1 1 0
0 1 1 1 2 0 0 2 0
0 1 2 0 0 1 2 1 0
3 7
25 15 20 15 25 20 20
26 14 20 14 26 20 20
25 15 20 15 20 20 25
3 9
25 15 20 15 25 20 20 20 20
26 14 20 14 26 20 20 20 20
25 15 20 15 25 15 20 20 25
3 11
25 15 20 15 25 20 20 20 20 20 20
26 14 20 14 26 20 20 20 20 20 20
25 15 20 15 25 20 15 20 20 20 25
3 13
25 15 20 15 25 20 20 20 20 20 20 20 20
26 14 20 14 26 20 20 20 20 20 20 20 20
25 15 20 15 25 20 20 15 20 20 20 20 25
3 15
25 15 20 15 25 20 20 20 20 20 20 20 20 20 20
26 14 20 14 26 20 20 20 20 20 20 20 20 20 20
25 15 20 15 25 20 20 20 15 20 20 20 20 20 25
3 9
909459 479492 676924 224197 162866 164495 193268 742456 728277
948845 455424 731850 327890 304150 237351 251763 225845 798316
975446 401170 792914 272263 300770 242037 236619 334316 725899
*/