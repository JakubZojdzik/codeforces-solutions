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

vector<ll> ruch[650];
vector<ll> nowe;

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ll n, k;
    cin >> n >> k;
    for(int i = 1; i <= 650; i++)
    {
        ll x = k+i;
        while(x <= 200007)
        {
            ruch[i].pb(x); // sum mniej wiecej 10^6
            x += k+i;
        }
    }
    ll sum = 0;
    for(int i = 1; i <= 650; i++)
    {
        sum += ruch[i].size();
        debug(i, ruch[i].size());
    }
    debug(sum);


    ll ost = k;
    // while(ost <= 200002)
    // {
    //     nowe.push_back(ost);
    //     ost += k + 1;
    // }
    for(int i = 1; i <= n; i++)
    {
        if(i == ost) 
        {
            nowe.pb(ost);
            ost += k+1;
        }
    }
}

/*

*/