#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(a) cout << #a << " = " << a << '\n'

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    
    ll t, n, a;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        cin >> n;
        bool juz = 0;
        ll wynik = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a;
            if(a) juz = 1;
            if(juz && a == 0 && i != n-1)
            {
                wynik++;
            }
            if(i != n-1) wynik += a;
        }
        cout << wynik << '\n';
    }
}