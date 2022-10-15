/*
    Jakub Żojdzik
    08-09-2022
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

int a[200007], b[200007];

int dig(int x)
{
    int w = 0;
    while(x > 0)
    {
        w++;
        x /= 10;
    }
    return w;
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        int n, a, b;
        cin >> n;
        priority_queue<int> queA, queB;
        rep(i, 1, n) 
        {
            cin >> a;
            queA.push(a);
        }
        rep(i, 1, n) 
        {
            cin >> b;
            queB.push(b);
        }
        int w = 0;
        while((!queA.empty()))
        {
            if(queA.top() == queB.top())
            {
                queA.pop();
                queB.pop();
            }
            else if(queA.top() > queB.top())
            {
                queA.push(dig(queA.top()));
                queA.pop();
                w++;
            }
            else
            {
                queB.push(dig(queB.top()));
                queB.pop();
                w++;
            }
        }
        cout << w << '\n';
    }
}

/*
1
10
75019 709259 5 611271314 9024533 81871864 9 3 6 4865
9503 2 371245467 6 7 37376159 8 364036498 52295554 169



*/