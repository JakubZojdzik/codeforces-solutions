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

bool byl[100];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t, n;
    string a, b;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        for(int i = 0; i < 100; i++)
        {
            byl[i] = 0;
        }
        int w = 0;
        cin >> a >> b;
        byl[a[0] - 'a'] = 1;
        if(!byl[a[1] - 'a'])
        {
            byl[a[1] - 'a'];
            byl[a[1] - 'a'] = 1;
            w++;
        }
        if(!byl[b[0] - 'a'])
        {
            byl[b[0] - 'a'];
            byl[b[0] - 'a'] = 1;
            w++;
        }
        if(!byl[b[1] - 'a'])
        {
            byl[b[1] - 'a'];
            byl[b[1] - 'a'] = 1;
            w++;
        }
        cout << w << '\n';
    }
}

/*

*/