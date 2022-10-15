/*
    Jakub Żojdzik
    01-08-2022
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

int moz[50];

int licz(int x)
{
    int w = 0, dziel = 1;
    while (x > 0)
    {
        if (x % 2 == 1)
        {
            w += dziel;
        }
        dziel++;
        x /= 2;
    }
    return w;
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t, s;
    cin >> t;
    for (int i = 0; i < 512; i++)
    {
        moz[licz(i)] = i;
    }
    dt;
    for (int T = 0; T < t; T++)
    {
        cin >> s;
        if (s == 0)
            cout << "0\n";
        else
        {
            string w = "";
            int dziel = 1, x = moz[s];
            dt;
            while (x > 0)
            {
                if (x % 2 == 1)
                {
                    w = w + char(dziel + '0');
                }
                dziel++;
                x /= 2;
            }
            cout << w << '\n';
        }
    }
}

/*

*/