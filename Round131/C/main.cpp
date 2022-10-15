#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(a) cout << #a << " = " << a << '\n'

ll tasks[400007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    ll t, n, m, a;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        cin >> n >> m;
        for (int i = 0; i <= n; i++)
        {
            tasks[i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> a;
            tasks[a]++;
        }
        ll pocz = 0, kon = 2 * m, srod = (pocz + kon) / 2, res = 0;
        while (pocz + 1 < kon)
        {
            res = 0;
            for (int i = 1; i <= n; i++)
            {
                if (srod >= tasks[i])
                {
                    res += tasks[i] + (srod - tasks[i]) / 2;
                }
                else
                {
                    res += srod;
                }
            }
            if (res >= m)
                kon = srod;
            else
                pocz = srod;
            srod = (pocz + kon) / 2;
        }
        cout << kon << '\n';
    }
}
