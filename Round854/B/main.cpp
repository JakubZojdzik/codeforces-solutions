/*
    Jakub Żojdzik
    --DATE--
*/

#include <bits/stdc++.h>
#define dt
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<long long, long long>> vpll;

#define fi first
#define se second
#define pb push_back
#define rep(i, x, y) for(ll i = (ll)x; i <= (ll)y; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define nl cout << '\n'

int a[107];
int n;

bool rozne()
{
    for (int i = 1; i < n; i++)
    {
        if(a[i] != a[i+1])
            return 1;
    }
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
        cin >> n;
        int najm = 1e9 + 17, ind = 0;
        rep(i, 1, n)
        {
            cin >> a[i];
            if(najm > a[i])
            {
                najm = a[i];
                ind = i;
            }
        }
        if(!rozne())
        {
            cout << "0\n";
            continue;
        }
        if(najm == 1)
        {
            cout << "-1\n";
            continue;
        }

        vpii res;
        bool xd = 0;
        int tmp = 1e9+17, tmpind = 0;
        while (rozne())
        {
            for (int i = 1; i <= n; i++)
            {
                // cout << "i=" << i << '\n';
                while (a[i] != najm)
                {
                    res.pb({i, ind});
                    a[i] = (a[i] + najm - 1) / najm;
                    if(a[i] < najm)
                    {
                        break;
                    }
                    // cout << "a[i]=" << a[i] << '\n';
                }
                if(a[i] == 1)
                {
                    xd = 1;
                    break;
                }
                if(tmp > a[i])
                {
                    tmp = a[i];
                    tmpind = i;
                }
            }
            if(xd)
                break;
            najm = tmp;
            ind = tmpind;
        }

        if(xd)
        {
            cout << "-1\n";
            continue;
        }
        cout << sz(res) << '\n';
        for(auto x : res)
        {
            cout << x.fi << " " << x.se << '\n';
        }
    }
}

/*
1
2
2 1

*/