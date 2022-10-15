#include <bits/stdc++.h>
using namespace std;

bool occur[200007];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t, n, akt, base;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        cin >> n;
        cout << "2\n";
        for(int i = 0; i <= n; i++) occur[i] = 0;
        akt = 1;
        base = 1;
        while(1)
        {
            cout << akt << " ";
            occur[akt] = 1;
            if((akt<<1) <= n)
            {
                akt <<= 1;
            }
            else
            {
                while(occur[base]) base++;
                if(base > n) break;
                akt = base;
            }
        }
        cout << "\n";
    }
}