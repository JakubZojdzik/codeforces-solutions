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

int a[200007];
int wyst[200007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t, n, najw;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        cin >> n;
        najw = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            najw = max(najw, a[i]);
        }
        for(int i = 0; i <= najw; i++)
        {
            wyst[i] = 0;
        }
        bool jest = 0;
        for(int i = n-1; i >= 0; i--)
        {
            wyst[a[i]]++;
            if(wyst[a[i]] >= 2)
            {
                cout << i+1 << '\n';
                jest = 1;
                break;
            }
        }
        if(!jest) cout << "0\n";
    }
}

/*

*/