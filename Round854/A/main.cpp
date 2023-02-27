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

int p[50007];
int res[50007];
bitset<500007> seen;

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    rep(T, 1, t)
    {
        int n, m;
        cin >> n >> m;
        seen.reset();
        int w = m;
        int akt = n;
        bool kon = 0;
        rep(i, 1, m)
        {
            cin >> p[i];
            if(kon) continue;
            if(seen[p[i]])
                w--;
            else
            {
                // cout << "wyrzucam " << akt << " w i=" << i << ", nowy to " << akt - 1 << '\n';
                res[akt] = i;
                akt--;
            }
            if(akt < 1)
                kon = 1;
            seen[p[i]] = 1;
        }
        // cout << "w = " << w << '\n';
        if(kon)
        {
            rep(i, 1, n)
            {
                cout << res[i] << ' ';
            }
            nl;
            continue;
        }
        rep(i, 1, n-w)
        {
            cout << "-1 ";
        }
        rep(i, n-w+1, n)
        {
            cout << res[i] << ' ';
        }
        nl;
    }
}

/*
1
4 5
5 9 9 5 7
*/