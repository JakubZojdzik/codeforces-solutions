#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(a) cout << #a << " = " << a << '\n'

ll h[100007];
ll pp[100007], np[100007], ps[100007], ns[100007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ll t, n, w;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> h[i];
        }
        for (int i = 0; i <= n + 2; i++)
        {
            pp[i] = 0;
            ps[i] = 0;
            np[i] = 0;
            ns[i] = 0;
        }
        if (n % 2 == 1)
        {
            w = 0;
            for (int i = 2; i < n; i += 2)
            {
                w += max(ll(0), max(h[i - 1], h[i + 1]) - h[i] + 1);
            }
        }
        else
        {
            for (int i = 2; i <= n - 2; i += 2)
            {
                pp[i] = max(ll(0), max(h[i - 1], h[i + 1]) - h[i] + 1) + pp[i - 2];
            }
            for (int i = 3; i <= n - 1; i += 2)
            {
                np[i] = max(ll(0), max(h[i - 1], h[i + 1]) - h[i] + 1) + np[i - 2];
            }
            for (int i = n - 2; i >= 2; i -= 2)
            {
                ps[i] = max(ll(0), max(h[i - 1], h[i + 1]) - h[i] + 1) + ps[i + 2];
            }
            for (int i = n - 1; i >= 3; i -= 2)
            {
                ns[i] = max(ll(0), max(h[i - 1], h[i + 1]) - h[i] + 1) + ns[i + 2];
            }

            w = LONG_LONG_MAX;
            for (int i = 1; i <= n - 1; i += 2)
            {
                if (i % 2 == 1)
                {
                    w = min(w, pp[i - 1] + ns[i + 2]);
                }
                else
                {
                    w = min(w, np[i - 1] + ps[i + 2]);
                }
            }
        }

        cout << w << '\n';
    }
}

/*
1
6
3 1 4 5 5 2
*/