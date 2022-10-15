#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(a) cout << #a << " = " << a << '\n'

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    
    ll q, n;
    string s, t;
    cin >> q;
    for(ll Q = 0; Q < q; Q++)
    {
        cin >> n >> s >> t;
        vector<ll> wysts, wystt;
        ll wynik = 0;
        for(ll i = 0; i < n-1; i++)
        {
            if(s[i] != s[i+1]) wysts.push_back(i);
            if(t[i] != t[i+1]) wystt.push_back(i);
        }
        if(s[0] != t[0] || wysts.size() != wystt.size())
        {
            cout << "-1\n";
            continue;
        }
        else
        {
            for(ll i = 0; i < (ll)wysts.size(); i++)
            {
                wynik += abs(wystt[i] - wysts[i]);
            }
        }
        cout << wynik << '\n';
    }
}

/*
4
4
0100
0010
4
1010
0100
5
01001
00011
6
000101
010011

*/