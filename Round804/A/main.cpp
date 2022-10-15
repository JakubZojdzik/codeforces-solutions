#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << " = " << a << '\n'
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    ll t, n;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        if(n % 2 == 1)
        {
            cout << "-1\n";
            continue;
        }
        cout << "0 " << n/2 << " " << n/2 << '\n';
    }
}

/*


*/