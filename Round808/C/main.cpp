#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(a) cout << #a << " = " << a << '\n'

int a[100007];
bool w[100007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    
    ll t, n, q;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        cin >> n >> q;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int akt = 0;
        for(int i = n-1; i >= 0; i--)
        {
            if(akt < a[i])
            {
                if(akt != q)
                {
                    akt++;
                    w[i] = 1;
                }
                else w[i] = 0;
            }
            else w[i] = 1;
        }
        for(int i = 0; i < n; i++)
        {
            cout << w[i];
        }
        cout << '\n';
    }
}

/*

*/