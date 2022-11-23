/*
    Jakub Żojdzik
    23-11-2022
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

int used[100007];
bitset<100007> on;

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    rep(T, 1, m)
    {
        char c;
        int v;
        cin >> c >> v;
        if(c == '+')
        {
            if(on[v])
            {
                cout << "Already on\n";
                continue;
            }
            int zle = 0;
            for(int i = 2; i*i <= v; i++)
            {
                if(v % i != 0) continue;
                zle = max(zle, used[i]);
                zle = max(zle, used[v/i]);
            }
            if(v != 1)
                zle = max(zle, used[v]);
            if(zle)
            {
                cout << "Conflict with " << zle << " \n";
                continue;
            }
            for(int i = 1; i*i <= v; i++)
            {
                if(v % i != 0) continue;
                used[i] = v;
                used[v/i] = v;
            }
            on[v] = 1;
            cout << "Success\n";
        }
        else if(c == '-')
        {
            if(!on[v])
            {   
                cout << "Already off\n";
                continue;
            }
            for(int i = 1; i*i <= v; i++)
            {
                if(v % i != 0) continue;
                used[i] = 0;
                used[v/i] = 0;
            }
            on[v] = 0;
            cout << "Success\n";
        }
    }
}

/*
7 5
+ 7
+ 6
+ 4
+ 3
- 7
*/