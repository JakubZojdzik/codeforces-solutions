#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(a) cout << #a << " = " << a << '\n'

int h[107];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t, n, x;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        cin >> n >> x;
        for (int i = 0; i < n*2; i++)
        {
            cin >> h[i];
        }
        sort(h, h + n*2);
        bool ok = 1;
        for(int i = 0; i < n; i++)
        {
            // cout << h[i] + x << " >? " << h[n+i] << '\n';
            if(h[i] + x > h[n+i]) ok = 0;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}

/*
1
3 6
1 3 9 10 12 16

1
3 1
2 5 2 2 2 5
*/