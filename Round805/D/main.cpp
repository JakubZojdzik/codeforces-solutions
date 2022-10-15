#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << " = " << a << '\n'
typedef long long ll;

ll wyst[30];
ll ign[30];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    ll t, p, akt, litera;
    string s;
    cin >> t;
    
    for(int T = 0; T < t; T++)
    {
        cin >> s >> p;
        akt = 0;
        for(int i = 0; i < 30; i++)
        {
            wyst[i] = 0;
            ign[i] = 0;
        }
        for(int i = 0; i < int(s.size()); i++)
        {
            akt += s[i] - 'a' + 1;
            wyst[s[i] - 'a' + 1]++;
        }
        litera = 26;
        while(akt > p)
        {
            if(wyst[litera] <= 0)
            {
                litera--;
                continue;
            }
            akt -= litera;
            wyst[litera]--;
            ign[litera]++;
        }
        for(int i = 0; i < int(s.size()); i++)
        {
            if(ign[s[i] - 'a' + 1]) ign[s[i] - 'a' + 1]--;
            else cout << s[i];
        }
        cout << '\n';
    }
}