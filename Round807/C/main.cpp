#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(a) cout << #a << " = " << a << '\n'

map<ll, ll> prog;

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ll t, n, c, q, l, r, k;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        cin >> n >> c >> q;
        string s;
        cin >> s;
        prog.clear();
        ll roz = n;
        for (int i = 0; i < c; i++)
        {
            cin >> l >> r;
            prog[-(roz + 1)] = l;
            roz += r - l + 1;
        }
        // for (auto [key, val] : prog)
        // {
        //     cout << key << " = " << val << '\n';
        // }

        for (int i = 0; i < q; i++)
        {
            cin >> k;
            if(k <= n)
            {
                cout << s[k-1] << '\n';
                continue;
            }
            pair<ll, ll> akt;
            do
            {
                akt = *prog.lower_bound(-k);
                k = akt.second + k + akt.first;
            } while(k > n);
            cout << s[k-1] << '\n';
        }

    }
}

/*
1
4 3 3
mark
1 4
5 7
3 8
1
10
12
7 3 3


1
7 3 3
creamii
2 3
3 4
2 9
9
11
12
*/