#include <bits/stdc++.h>
using namespace std;

int perm[100007], pref[100007], suf[100007], seen[100007], wynik[100007];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t, n;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            seen[i] = 0;
            wynik[i] = -1;
            cin >> perm[i];
        }
        int wsk = 0;
        for(int i = 0; i < n; i++)
        {
            seen[perm[i]] = 1;
            while (seen[wsk])
            {
                wsk++;
            }
            pref[i] = wsk;
        }
        for(int i = 0; i <= n; i++) seen[i] = 0;
        wsk = 0;
        for(int i = n-1; i >= 0; i--)
        {
            seen[perm[i]] = 1;
            while (seen[wsk])
            {
                wsk++;
            }
            suf[i] = wsk;
        }

        // for(int i = 0; i < n; i++)
        // {
        //     cout << i << ": " << pref[i] << '\n';
        // }
        // cout << '\n';
        // for(int i = 0; i < n; i++)
        // {
        //     cout << i << ": " << suf[i] << '\n';
        // }

        for(int i = 1; i < n; i++)
        {
            if(pref[i] > pref[i-1])
                wynik[i] = pref[i-1];
        }
        for(int i = n-2; i >= 0; i--)
        {
            if(suf[i] > suf[i+1])
                wynik[i] = suf[i+1];
        }

        for(int i = 0; i < n; i++)
        {
            cout << wynik[i] << '\n';
        }
    }
}


/*
1
6
1 2 4 0 5 3
*/