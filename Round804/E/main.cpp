#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << " = " << a << '\n'

int exist[5000007];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t, n, m, a, wmin;
    priority_queue<int> stos;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        cin >> n >> m;
        wmin = INT_MAX;
        while (!stos.empty())
            stos.pop();
        for(int i = 0; i <= m; i++)
        {
            exist[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (!exist[a])
                stos.push(a);
            exist[a]++;
            wmin = min(wmin, a);
        }
        int wyn;
        while (1)
        {
            bool akcja = false;
            int pot1 = -1, pot2 = INT_MAX;
            wyn = stos.top() - wmin;
            int x = stos.top();
            // cout << "probuje zamienic " << x << '\n';
            stos.pop();
            exist[x]--;
            for (int i = 2; i * i <= x; i++)
            {
                if ((x % i == 0) && max(stos.top(), pot1) - min(wmin, pot2) <= wyn)
                {
                    pot1 = x / i;
                    pot2 = i;
                    // cout << "zmieniam " << x << " na " << pot1 << ", " << pot2 << '\n';
                    wyn = max(stos.top(), pot1) - min(wmin, pot2);
                    // debug(wyn);
                    akcja = true;
                }
            }
            if (!akcja)
                break;

            if (!exist[pot1])
                stos.push(pot1);
            if (!exist[pot2])
                stos.push(pot2);
            exist[pot1]++;
            exist[pot2]++;
            wmin = min(wmin, pot2);
        }
        cout << wyn << '\n';
    }
}

/*
1
2 5
1 5

*/