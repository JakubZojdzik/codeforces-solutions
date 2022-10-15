/*
    Jakub Żojdzik
    04-08-2022
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
        int n;
        cin >> n;
        vi tab(n);
        cout << n << '\n';
        for(int i = 0; i < n; i++)
        {
            tab[i] = i+1;
        }
        for(int i = 0; i < n; i++)
        {
            for(int i = 0; i < n; i++)
            {
                cout << tab[i] << " ";
            }
            nl;
            swap(tab[i], tab[n-1]);
        }
    }
}

/*

*/