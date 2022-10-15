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

int a[100007];
bool jest[100007];
int pos[100007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        int n, w = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            jest[i] = 0;
            pos[a[i]] = i;
        }
        for(int i = n-1; i >= 1; i--)
        {
            if(a[i] > a[i+1])
            {
                for(int j = 1; j <= i; j++)
                {
                    i = max(i, pos[a[j]]);
                    if(!jest[a[j]]) w++;
                    jest[a[j]] = 1;
                }
                break;
            }
        }
        cout << w << '\n';
    }
}

/*
1
4
2 4 1 2
*/