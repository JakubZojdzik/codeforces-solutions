/*
    Jakub Żojdzik
    08-01-2023
*/

#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.hpp"
#else
#define debug(...)
#define dt
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<long long, long long>> vpll;

#define fi first
#define se second
#define pb push_back
#define rep(i, x, y) for(ll i = (ll)x; i <= (ll)y; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define nl cout << '\n'

ll a[500007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        ll n, m;
        cin >> n >> m;
        priority_queue<ll> pq;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            pq.push(-a[i]);
        }

        ll akt = m, pos = 0;
        while(akt >= 0 && !pq.empty())
        {
            if(akt + pq.top() >= 0)
            {
                pos++;
                akt += pq.top();
            }
            else break;
            pq.pop();
        }
        if(pos >= n)
        {
            cout << 1 << '\n';
            continue;
        }
        if(pos <= 0)
        {
            cout << n+1 << '\n';
            continue;
        }

        while(!pq.empty())
        {
            pq.pop();
        }
        for(int i = 0; i < n; i++)
        {
            if(i != pos)
                pq.push(-a[i]);
        }
        akt = m - a[pos];
        if(akt < 0)
        {
            cout << n - pos + 1 << '\n';
            continue;
        }
        ll temp = 1;
        while(akt >= 0 && !pq.empty())
        {
            if(akt + pq.top() >= 0)
            {
                temp++;
                akt += pq.top();
            }
            else break;
            pq.pop();
        }

        if(temp >= pos)
        {
            cout << n - pos << '\n';
        }
        else cout << n - pos + 1 << '\n';
    }
}

/*
1
4 0
0 1 1 1


1
5 0
1 1 1 1 1

3 2
1 2 3
*/