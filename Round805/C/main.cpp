#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << " = " << a << '\n'
typedef long long ll;

map<ll, pair<ll, ll>> places;

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    ll t, n, k, u, a, b;
    cin >> t;
    
    for(int T = 0; T < t; T++)
    {
        cin >> n >> k;
        places.clear();
        for(ll i = 0; i < n; i++)
        {
            cin >> u;
            if(places.find(u) != places.end())
            {
                places[u].first = min(places[u].first, i);
                places[u].second = max(places[u].second, i);
            }
            else
            {
                places[u].first = i;
                places[u].second = i;
            }
        }
        for(int i = 0; i < k; i++)
        {
            cin >> a >> b;
            if(places.find(a) == places.end() || places.find(b) == places.end()) cout << "NO\n";
            else if(places[a].first < places[b].second) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}