/*
    Jakub Żojdzik
    24-07-2022
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

int colors[100007];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ll t, n, m, k;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        cin >> n >> m >> k;
        for(int i = 0; i < k; i++)
        {
            cin >> colors[i];
        }
        bool wynik1 = 0, wynik2 = 0;

        // n to liczba poziomych rzedow
        // m to liczba kolumn
        // pionowe paski
        ll jeszcze = m;
        bool trojka = 0;
        for(int i = 0; i < k; i++)
        {
            if(colors[i] / n > 1)
                jeszcze -= colors[i] / n;
            if(colors[i] / n > 2) 
                trojka = 1;
        }
        if(jeszcze <= 0) wynik1 = 1;
        if(!trojka && m % 2 == 1) wynik1 = 0;
        // poziome paski
        jeszcze = n;
        trojka = 0;
        for(int i = 0; i < k; i++)
        {
            if(colors[i] / m > 1)
                jeszcze -= colors[i] / m;
            if(colors[i] / m > 2) trojka = 1;
        }
        if(jeszcze <= 0) wynik2 = 1;
        if(!trojka && n % 2 == 1) wynik2 = 0;

        if(wynik1 || wynik2) cout << "Yes\n";
        else cout << "No\n";
    }
}

/*
1
3 3 2
8 8
*/