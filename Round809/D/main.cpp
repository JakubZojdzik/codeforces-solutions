#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(a) cout << #a << " = " << a << '\n'

bool exists[3003];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    
    int t, n, k, gora, dol, a;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        gora = -1;
        dol = -1;
        cin >> n >> k;
        for(int i = 0; i < n; i++)
        {
            cin >> a;
            if(gora == -1)
            {
                gora = a;
                dol = a;
            }
            
        }
    }
}

/*

*/