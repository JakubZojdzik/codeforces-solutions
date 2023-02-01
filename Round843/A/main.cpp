/*
    Jakub Żojdzik
    10-01-2023
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

string a;

bool war(int p, int q)
{
    string x = a.substr(0, p+1);
    string y = a.substr(p+1, q-p);
    string z = a.substr(q+1, sz(a)-q-1);
    if(strcmp(y.c_str(), x.c_str()) >= 0 && strcmp(y.c_str(), z.c_str()) >= 0) return 1;
    if(strcmp(y.c_str(), x.c_str()) <= 0 && strcmp(y.c_str(), z.c_str()) <= 0) return 1;
    return 0;
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        cin >> a;
        bool roz = 0;
        for(int i = 1; i < sz(a); i++)
        {
            roz = max(roz, (a[i] == a[i-1]));
        }
        if(!roz)
        {
            cout << a[0] << " " << a[1] << " ";
            for(int i = 2; i < sz(a); i++)
            {
                cout << a[i];
            }
            nl;
            continue;
        }
        if(sz(a) == 3)
        {
            cout << a[0] << " " << a[1] << " " << a[2] << '\n';
            continue;
        }
        if(a[0] == a[1])
        {
            cout << a[0] << " " << a[1] << " ";
            for(int i = 2; i < sz(a); i++)
            {
                cout << a[i];
            }
            nl;
            continue;
        }
        if(a[sz(a)-1] == a[sz(a)-2])
        {
            for(int i = 0; i < sz(a)-2; i++)
            {
                cout << a[i];
            }
            cout << " " << a[sz(a)-1] << " " << a[sz(a)-2] << "\n";
            continue;
        }

        int i;
        for(i = 0; i < sz(a); i++)
        {
            if(a[i] == a[0]) cout << a[i];
            else
            {
                cout << " " << a[i];
                break;
            }
        }
        i++;
        for(; i < sz(a); i++)
        {
            if(a[i] == a[0] || i == sz(a)-1)
            {
                cout << " " << a[i];
                break;
            }
            else cout << a[i];
        }
        i++;
        for(; i < sz(a); i++)
        {
            cout << a[i];
        }
        nl;
    }
}

/*

*/