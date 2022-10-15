/*
    Jakub Żojdzik
    01-08-2022
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

// "Mam bardzo długi kod, ale jest fajny lubię go" ~ Jakub Żółdzik
ll sumy[1007];
constexpr int mod = 1000000007;
ll potegi[1009];
pair<ll, ll> miejsca[20];
vector<tuple<ll, ll, ll>> przedz;

bool czy_rowne(ll p1, ll k1, ll p2, ll k2)
{
    if (p1 > p2)
    {
        swap(p1, p2);
        swap(k1, k2);
    }
    ll pier;
    ll drug;
    if (p1 - 1 >= 0)
        pier = sumy[k1] - sumy[p1 - 1];
    else
        pier = sumy[k1];

    if (p2 - 1 >= 0)
        drug = sumy[k2] - sumy[p2 - 1];
    else
        drug = sumy[k2];

    if (pier < 0)
        pier += mod;
    if (drug < 0)
        drug += mod;
    return (pier * static_cast<long long>(potegi[p2 - p1]) % mod == drug % mod);
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    potegi[0] = 1;
    for (int i = 1; i < 1009; i++)
    {
        potegi[i] = (potegi[i - 1] * 31) % mod;
    }
    string napis;
    for (int T = 0; T < t; T++)
    {
        cin >> napis;
        int rozmiar = napis.size();
        int n;
        cin >> n;
        string temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            napis = napis + temp;
            if (i == 0)
                miejsca[i] = {rozmiar, temp.size() + rozmiar - 1};
            else
                miejsca[i] = {miejsca[i - 1].second + 1, miejsca[i - 1].second + temp.size()};
        }
        sumy[0] = int(napis[0]) - 'a' + 1;
        for (int i = 1; i < (int)napis.size(); i++)
        {
            sumy[i] = (sumy[i - 1] + ((napis[i] - 'a' + 1) * potegi[i])) % mod;
        }

        przedz.clear();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < rozmiar; j++)
            {
                if (j + miejsca[i].second - miejsca[i].first > rozmiar - 1)
                    break;
                if (czy_rowne(j, j + miejsca[i].second - miejsca[i].first, miejsca[i].first, miejsca[i].second))
                {
                    przedz.pb({j, j + miejsca[i].second - miejsca[i].first, i + 1});
                }
            }
        }
        przedz.pb({rozmiar, rozmiar+1, n+1});
        sort(all(przedz));
        ll prawy = -1, kand = -1, wynik = -1, poz = -1;
        vector<pair<ll, ll>> wyp;
        for (int i = 0; i < (int)przedz.size(); i++)
        {
            debug(i, prawy);
            if (get<0>(przedz[i]) <= prawy + 1)
            {
                if(kand < get<1>(przedz[i]))
                {
                    kand = get<1>(przedz[i]);
                    poz = i;
                }
                debug("lepszy", kand);
            }
            else
            {
                debug("zmieniam");
                prawy = kand;
                if (wynik == -1)
                    wynik = 1;
                else
                    wynik++;
                if (get<0>(przedz[i]) > prawy + 1 || prawy == -1)
                {
                    wynik = -1;
                    break;
                }
                wyp.pb({get<2>(przedz[poz]), get<0>(przedz[poz])});
                i--;
            }
        }
        if (wynik == -1)
        {
            cout << wynik << '\n';
            continue;
        }
        cout << wynik << '\n';
        for (auto w : wyp)
        {
            cout << w.first << " " << w.second + 1 << '\n';
        }
    }
}
