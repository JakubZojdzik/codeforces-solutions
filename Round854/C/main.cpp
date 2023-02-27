/*
    Jakub Żojdzik
    --DATE--
*/

#include <bits/stdc++.h>
#define dt
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<long long, long long>> vpll;

#define fi first
#define se second
#define pb push_back
#define rep(ind, x, y) for(ll ind = (ll)x; ind <= (ll)y; ind++)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define nl cout << '\n'

int seen[1000];


int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    string s;
    rep(T, 1, t)
    {
        cin >> s;
        for (int i = 'a'; i <= 'z'; i++)
        {
            seen[i] = 0;
        }
        string l, r;
        sort(s.begin(), s.end());
        for (int i = 0; i < sz(s); i++)
        {
            seen[s[i]]++;
        }
        int ind;
        char akt = 0;
        for (ind = 0; ind < sz(s) - 1; ind += 2)
        {
            if (seen[s[ind]] % 2 == 1)
            {
                akt = s[ind];
                break;
            }
            if (s[ind] == s[ind + 1])
            {
                l += s[ind];
                r += s[ind];
            }
        }
        if(akt != 0)
        {
            for (; ind < sz(s); ind++)
            {
                if(s[ind] != akt)
                    break;
                if (ind % 2 == 0)
                    l += s[ind];
                else
                    r += s[ind];
            }
            if(sz(l) < sz(r))
                swap(l, r);

            if(sz(s) - ind == 2 && s[sz(s)-1] == s[sz(s)-2])
            {
                l.pop_back();
                cout << l;
                for (int i = 0; i < (sz(s) - ind) / 2; i++)
                    cout << s.back();
                cout << s[0];
                for (int i = 0; i < (sz(s) - ind) / 2; i++)
                    cout << s.back();
                cout << r << '\n';
                continue;
            }
        }

        for (int i = ind; i < sz(s); i++)
        {
            r += s[i];
        }
        cout << l;
        for (int i = sz(r)-1; i >= 0; i--)
            cout << r[i];
        nl;
    }
}

/*
1
abbcc


*/