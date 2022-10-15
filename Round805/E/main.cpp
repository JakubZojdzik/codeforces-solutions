#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << " = " << a << '\n'
typedef long long ll;

struct biit
{
    unsigned int val : 2;
};

vector<int> idx[200002];
vector<int> kraw[200002];
biit seen[200007];
int kolor = 1;
int cnt[200007];

void chng()
{
    if(kolor == 1) kolor = 2;
    else kolor = 1;
}

void dfs(int a)
{
    seen[a].val = kolor;
    for(int i = 0; i < int(kraw[a].size()); i++)
    {
        if(!seen[kraw[a][i]].val)
        {
            chng();
            dfs(kraw[a][i]);
            chng();
        }
    }
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    int t, n, a, b;
    cin >> t;
    
    for(int T = 0; T < t; T++)
    {
        cin >> n;
        bool xd = 0;
        for(int i = 0; i <= n; i++)
        {
            idx[i].clear();
            kraw[i].clear();
            seen[i].val = 0;
            cnt[i] = 0;
        }
        for(int i = 0; i < n; i++)
        {
            cin >> a >> b;
            cnt[a]++; cnt[b]++;
            if(a == b || cnt[a] > 2 || cnt[b] > 2) xd = 1;
            if(!xd)
            {
                for(int j = 0; j < int(idx[a].size()); j++)
                {
                    kraw[i].push_back(idx[a][j]);
                    kraw[idx[a][j]].push_back(i);
                }
                for(int j = 0; j < int(idx[b].size()); j++)
                {
                    kraw[i].push_back(idx[b][j]);
                    kraw[idx[b][j]].push_back(i);
                }
                idx[a].push_back(i);
                idx[b].push_back(i);
            }
        }
        if(xd)
        {
            cout << "nO\n";
            continue;
        }
        xd = 1;
        for(int i = 0; i < n; i++)
        {
            if(!seen[i].val)
                dfs(i);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < int(kraw[i].size()); j++)
            {
                if(seen[i].val == seen[kraw[i][j]].val)
                {
                    xd = 0;
                    break;
                }
            }
        }
        if(xd)
            cout << "yEs\n";
        else
            cout << "No\n";
    }
}

/*
1
4
1 2
4 3
2 1
3 4
*/