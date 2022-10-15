#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << " = " << a << '\n'
typedef long long ll;

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    
    ll t, n, a, b;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        cin >> n;
        map<ll, int> wyst; 
        for(int i = 0; i < n; i++)
        {
            cin >> a;
            a /= (1 << __builtin_ctz(a));
            while(a > 0)
            {
                wyst[a]--;
                a /= 2;
            }
        }
        for(int i = 0; i < n; i++)
        {
            cin >> b;
            b /= (1 << __builtin_ctz(b));
            while(b > 0)
            {
                wyst[b]++;
                b /= 2;
            }
        }
        bool wynik = true;
        for(auto [nr, val] : wyst)
        {
            if(val < 0) wynik = false;
        }
        if(wynik) cout << "YES\n";
        else cout << "NO\n";
    }
}

/*
1
4
2 4 5 24
1 4 6 11


*/