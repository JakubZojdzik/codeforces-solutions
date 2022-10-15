#include <bits/stdc++.h>
using namespace std;

constexpr int LIMIT = 500007;

int b[LIMIT];
pair<int, int> przedz[LIMIT], sum[LIMIT];
int nowy[LIMIT];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t, n;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
            if (b[i] == 0)
            {
                przedz[i] = {b[i] + 1, n};
                nowy[b[i] + 1]++;
                nowy[n]--;
            }
            else
            {
                przedz[i] = {i / (b[i] + 1) + 1, i / b[i]}; // obustronnie domknięty
                nowy[i / (b[i] + 1) + 1]++;
                nowy[i / b[i]]--;
            }
        }
        sum[1] = {nowy[1], 1};
        for(int i = 2; i <= n; i++)
        {
            sum[i].first = nowy[i] + sum[i-1].first;
            sum[i].second = i;
        }
        sort(sum+1, sum+n+1);
         
    }
}