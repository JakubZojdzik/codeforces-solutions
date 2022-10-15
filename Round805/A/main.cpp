#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << " = " << a << '\n'
typedef long long ll;

ll pwr[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    // cout << pwr[upper_bound(pwr, pwr+10, 100) - pwr - 1] << '\n';
    // cout << pwr[upper_bound(pwr, pwr+10, 78) - pwr - 1] << '\n';
    // cout << pwr[upper_bound(pwr, pwr+10, 1) - pwr - 1] << '\n';
    // cout <<  << '\n';
    // return 0;
    ll t, n;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        cin >> n;
        cout << n - pwr[upper_bound(pwr, pwr+10, n) - pwr - 1] << '\n';
    }
}