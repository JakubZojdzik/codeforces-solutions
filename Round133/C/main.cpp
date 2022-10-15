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

ll board[3][200007];
ll val[3][200007];
ll zygzak[3][200007];
pair<ll, ll> blokada[200007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ll t;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        ll m;
        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> board[1][i];
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> board[2][i];
        }

        zygzak[1][1] = 0;
        zygzak[2][1] = board[2][1];
        for (int i = 2; i <= m; i++)
        {
            if (i % 2 == 1)
            {
                zygzak[1][i] = max(board[1][i], zygzak[1][i - 1] + 1);
                zygzak[2][i] = max(board[2][i], zygzak[1][i] + 1);
            }
            else
            {
                zygzak[2][i] = max(board[2][i], zygzak[2][i - 1] + 1);
                zygzak[1][i] = max(board[1][i], zygzak[2][i] + 1);
            }
        }

        if(board[1][m] + 1 > board[2][m]) blokada[m] = {1, m};
        else blokada[m] = {2, m};
        for(int i = m-1; i >= 1; i--)
        {
            ll dist = 0;
            if(blokada[m+1].first == 1) dist = blokada[m+1].second - i;
            else dist = m - i + m - blokada[m+1].second + 1;
            if(board[1][i] + dist > board[blokada[m+1])
            {
                blokada[m] = board[1][i] + dist;
            }
        }
        
    }
}

/*

*/