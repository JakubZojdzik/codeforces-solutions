#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t, a, b, c, d, x;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        cin >> a >> b >> c >> d;
        x = a + b + c + d;
        if(x == 0)
        {
            cout << "0\n";
        }
        else if(x == 1 || x == 2 || x == 3)
        {
            cout << "1\n";
        }
        else cout << "2\n";
    }
}