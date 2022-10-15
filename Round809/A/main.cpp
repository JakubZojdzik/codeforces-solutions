#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(a) cout << #a << " = " << a << '\n'

bool changed[57];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    
    int t, n, m, a;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        cin >> n >> m;
        for(int i = 0; i <= m; i++)
        {
            changed[i] = 0;
        }
        for(int i = 1; i <= n; i++)
        {
            cin >> a;
            if(changed[min(a, m+1-a)]) changed[max(a, m+1-a)] = 1;
            else changed[min(a, m+1-a)] = 1;
        }
        for(int i = 1; i <= m; i++)
        {
            if(changed[i]) cout << "A";
            else cout << "B";
        }
        cout << '\n';
    }
}

/*

*/