#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t, n, m;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int padding = ((((i + 1) / 2) % 2) == 1);
            for (int j = 0; j < m; j++)
            {
                if ((((j + 1 + 2 * padding) / 2) % 2) == 0)
                    cout << "1 ";
                else
                    cout << "0 ";
            }
            cout << '\n';
        }
    }
}