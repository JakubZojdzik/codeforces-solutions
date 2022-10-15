#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << " = " << a << '\n'
typedef long long ll;

bool letters[1000];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    int t;
    string s;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        cin >> s;
        vector<int> occ;
        int wynik = 1;
        for(int i = 0; i <= 900; i++) letters[i] = 0;
        for (int i = 0; i < int(s.size()); i++)
        {
            if (!letters[int(s[i])])
            {
                if (occ.size() == 3)
                {
                    wynik++;
                    // cout << "mam " << char(occ[0]) << ", " << char(occ[1]) << ", " << char(occ[2]) << ", wynik = " << wynik << '\n';
                    letters[occ[0]] = 0;
                    letters[occ[1]] = 0;
                    letters[occ[2]] = 0;
                    occ.clear();
                }
                occ.push_back(int(s[i]));
                letters[int(s[i])] = 1;
            }
        }
        cout << wynik << '\n';
    }
}