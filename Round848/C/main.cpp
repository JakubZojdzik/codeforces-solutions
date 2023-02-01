/*
    Jakub Żojdzik
    01-02-2023
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

bitset<1000> jest;
bitset<1000> uzyt;
int ind[1000];
vi litera;

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        ll n, k, res = 0;
        cin >> n >> k;
        k = min(k, n);
        string a, b;
        cin >> a >> b;
        uzyt.reset();
        litera.clear();
        ll itr = 0;
        for(int i = 0; i < sz(a); i++)
        {
            if(!uzyt[a[i]])
            {
                ind[a[i]] = itr;
                litera.pb(a[i]);
                // cout << "ind[" << a[i] << "] = " << itr << '\n';
                // cout << "litera[" << itr << "] = " << a[i] << '\n';
                itr++;
            }
            uzyt[a[i]] = 1;
        }
        ll mn = sz(litera);
        vector<int> p(mn, 0);
        for (int t = mn - k; t < mn; p[t++] = 1);
        do {
            // rozpatrujemy podzbiór
            itr = 0;
            for (bool x : p)
            {
                // cout << x;
                jest[itr] = x;
                itr++;
            }
            // nl;
            ll w = 0, zrzedu = 0;
            for(int i = 0; i < n; i++)
            {
                if(a[i] == b[i] || jest[ind[a[i]]])
                {
                    zrzedu++;
                    continue;
                }
                w += (zrzedu*zrzedu + zrzedu) / 2;
                zrzedu = 0;
            }
            w += (zrzedu*zrzedu + zrzedu) / 2;
            // cout << "w: " << w << '\n';
            res = max(res, w);
        } while (next_permutation(p.begin(), p.end()));

        cout << res << '\n';
    }
}

/*
1
4 1
abcd
axcb




6
3 1
abc
abd
3 0
abc
abd
3 1
xbb
xcd
4 1
abcd
axcb
3 10
abc
abd
10 3
lkwhbahuqa
qoiujoncjb


1
3 1
abc
abd
*/