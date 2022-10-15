#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(a) cout << #a << " = " << a << '\n'

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ll t, n, l, r;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        cin >> n >> l >> r;
        vector<ll> wynik;
        for(int i = 1; i <= n; i++)
        {
            if((r / i) * i < l) break;
            wynik.push_back((r / i) * i);
        }
        if((int)wynik.size() < n) cout << "NO";
        else
        {
            cout << "YES\n";
            for(ll w : wynik)
            {
                cout << w << " ";
            }
        }
        cout << '\n';
    }
}