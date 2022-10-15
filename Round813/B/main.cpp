/*
    Jakub Żojdzik
    13-08-2022
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

int pos[100007];

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
        for(int i = n; i >= 1; i--)
        {
            pos[i] = i-1;
            pos[i-1] = i;
            i--;
        }
        if(n % 2 == 1) pos[1] = 1;
        for(int i = 1; i <= n; i++)
        {
            cout << pos[i] << '\n';
        }
    }
}

/*

*/