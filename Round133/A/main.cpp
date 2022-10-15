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
        int x;
        cin >> x;
        if(x == 1)
            cout << 2 << '\n';
        else if(x % 3 == 0)
            cout << x/3 << '\n';
        else if(x % 3 == 1)
        {
            cout << ((x-4) / 3) + 2 << '\n';
        }
        else cout << (x-2) / 3 + 1 << '\n';
    }
}

/*

*/