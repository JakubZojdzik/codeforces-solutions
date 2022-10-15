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

bool czasy[20007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t, n, h, m;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        cin >> n >> h >> m;
        int moj = 60*h + m;
        for(int i = 0; i <= 2000; i++)
        {
            czasy[i] = 0;
        }
        for(int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            czasy[60*x + y] = 1;
        }
        bool jest = 0;
        for(int i = moj; i < 1440; i++)
        {
            if(czasy[i])
            {
                cout << (i - moj) / 60 << " " << (i - moj) - (((i - moj) / 60) * 60) << '\n';
                jest = 1;
                break;
            }
        }
        if(jest) continue;;
        for(int i = 0; i < moj; i++)
        {
            if(czasy[i])
            {
                int temp = 1440 - moj + i;
                cout << temp / 60 << " " << temp - (temp / 60) * 60 << '\n';
                break;
            }
        }
    }
}

/*

*/