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

ll a[200007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        dt;
        int n;
        cin >> n;
        int grupa = -1;
        bool ok = 1, rowne = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i > 0 && a[i] != a[i - 1])
                rowne = 0;
            if (a[i] % 10 == 0 || a[i] % 10 == 5)
            {
                if (grupa == 0)
                    ok = 0;
                grupa = 1;
            }
            else
            {
                if (grupa == 1)
                    ok = 0;
                grupa = 0;
            }
        }
        dt;
        if (!ok)
        {
            cout << "No\n";
            continue;
        }
        if (rowne)
        {
            cout << "Yes\n";
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] % 10 == 1)
                a[i] += 1;
            if (a[i] % 10 == 3)
                a[i] += 3;
            if (a[i] % 10 == 5)
                a[i] += 5;
            if (a[i] % 10 == 7)
                a[i] += 7;
            if (a[i] % 10 == 9)
                a[i] += 9;
        }

        rowne = 1;
        if (grupa == 1)
        {
            for (int i = 1; i < n; i++)
            {
                if (a[i] != a[i - 1])
                    rowne = 0;
            }
            if (!rowne)
                cout << "No\n";
            else
                cout << "yes\n";
            continue;
        }

        ll najw = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 10 == 4)
                a[i] += 18;
            if (a[i] % 10 == 8)
                a[i] += 14;
            if (a[i] % 10 == 6)
                a[i] += 6;
        }

        for (int i = 0; i < n - 1; i++)
        {
            if ((a[i] - a[i + 1]) % 20 != 0)
            {
                ok = 0;
                break;
            }
        }
        if (ok)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

/*
1
2
6 11
*/