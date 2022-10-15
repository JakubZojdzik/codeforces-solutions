#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(a) cout << #a << " = " << a << '\n'

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    
    ll t, n, a, x;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        cin >> n;
        cin >> x;
        bool ok = 1;
        for(int i = 1; i < n; i++)
        {
            cin >> a;
            if(a % x != 0) ok = 0;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}

/*

*/