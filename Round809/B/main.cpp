#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(a) cout << #a << " = " << a << '\n'

int ciag[100007][2];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    
    int t, n, c;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        cin >> n;
        for(int i = 0; i <= n; i++)
        {
            ciag[i][0] = 0;
            ciag[i][1] = 0;
        }
        for(int i = 1; i <= n; i++)
        {
            cin >> c;
            if(i % 2 == 0)
            {
                ciag[c][0] = ciag[c][1]+1;
            }
            if(i % 2 == 1)
            {
                ciag[c][1] = ciag[c][0]+1;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            cout << max(ciag[i][0], ciag[i][1]) << " ";
        }
        cout << '\n';
    }
}

/*
1
6
3 3 3 1 3 3
*/