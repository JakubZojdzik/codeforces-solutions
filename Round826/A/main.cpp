/*
    Jakub Żojdzik
    11-10-2022
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

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ll t;
    cin >> t;
    rep(T, 1, t)
    {
        string a, b;
        cin >> a >> b;
        if(a[0] == 'M')
        {
            if(b[0] == 'M')
            {
                cout << "=\n";
            }
            else if(b.back() == 'S')
            {
                cout << ">\n";
            }
            else
            {
                cout << "<\n";
            }
            continue;
        }
        else if(b[0] == 'M')
        {
            if(a[0] == 'M')
            {
                cout << "=\n";
            }
            else if(a.back() == 'S')
            {
                cout << "<\n";
            }
            else
            {
                cout << ">\n";
            }
        }
        else if(b.back() == 'S' && a.back() == 'L')
        {
            cout << ">\n";
        }
        else if(b.back() == 'L' && a.back() == 'S')
        {
            cout << "<\n";
        }
        else if(b.back() == 'S' && a.back() == 'S')
        {
            if(sz(a) > sz(b)) cout << "<\n";
            else if(sz(a) == sz(b)) cout << "=\n";
            else cout << ">\n";
        }
        else if(b.back() == 'L' && a.back() == 'L')
        {
            if(sz(a) > sz(b)) cout << ">\n";
            else if(sz(a) == sz(b)) cout << "=\n";
            else cout << "<\n";
        }

    }
}

/*

*/