/*
    Jakub Żojdzik
    21-07-2022
*/

#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.hpp"
#define dt cout << "HERE!\n"
#else
#define debug(...)
#define dt
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define nl cout << '\n'

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t, dol, gora;
    string a;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        cin >> a;
        vi pot;
        bool ok = 1;
        bool wolne = 1;
        dol = 0;
        gora = 0;
        for(int i = 0; i < (int)a.size(); i++)
        {
            if(a[i] == '(')
            {
                pot.push_back(1);
                dol++;
                gora++;
            }
            if(a[i] == ')')
            {
                pot.push_back(-1);
                gora--;
                dol--;
            }
            if(a[i] == '?')
            {
                if(wolne)
                    dol--;
                else dol++;
                gora++;
            }
            if(dol < 0) 
            {
                dol = gora;
                wolne = 0;
            }
            if(gora <= 1)
            {
                wolne = 1;
            }
            if(gora < 0) ok = 0;
            // debug(i, dol, gora);
        }
        if((dol == 0 || gora == 0) && ok)
        {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}

/*
1
??????
*/