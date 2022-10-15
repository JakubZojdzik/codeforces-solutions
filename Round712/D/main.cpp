#include <bits/stdc++.h>
using namespace std;

int board[107][107];

int main()
{
    int n, a, wpis;
    pair<int, int> jed = {1, 1}, dwa = {1, 2};
    int done = 0;
    cin >> n;
    for (int i = 1; i <= n * n; i++)
    {
        cin >> a;
        if (!done)
        {
            if (a != 1)
            {
                board[jed.first][jed.second] = 1;
                cout << "1 " << jed.first << " " << jed.second << '\n';
                cout.flush();
                jed.second += 2;
                if(jed.second > n)
                {
                    if(board[jed.first][1] == 1)
                    {
                        jed.second = 2;
                    }
                    else
                    {
                        jed.second = 1;
                    }
                    jed.first++;
                }
                if(jed.first > n) done = 1;
            }
            else
            {
                board[dwa.first][dwa.second] = 2;
                cout << "2 " << dwa.first << " " << dwa.second << '\n';
                cout.flush();
                dwa.second += 2;
                if(dwa.second > n)
                {
                    if(board[dwa.first][1] == 2)
                    {
                        dwa.second = 2;
                    }
                    else
                    {
                        dwa.second = 1;
                    }
                    dwa.first++;
                }
                if(dwa.first > n) done = 2;
            }
        }
        else // done
        {
            if(done == 1)
            {
                wpis = 2;
                if(a == 2) wpis = 3;
                board[dwa.first][dwa.second] = wpis;
                cout << wpis << " " << dwa.first << " " << dwa.second << '\n';
                cout.flush();
                dwa.second += 2;
                if(dwa.second > n)
                {
                    if(board[dwa.first][1] != 1)
                    {
                        dwa.second = 2;
                    }
                    else
                    {
                        dwa.second = 1;
                    }
                    dwa.first++;
                    if(dwa.first > n) return 0;
                }
            }
            else
            {
                wpis = 1;
                if(a == 1) wpis = 3;
                board[jed.first][jed.second] = 1;
                cout << wpis << " " << jed.first << " " << jed.second << '\n';
                cout.flush();
                jed.second += 2;
                if(jed.second > n)
                {
                    if(board[jed.first][1] != 2)
                    {
                        jed.second = 2;
                    }
                    else
                    {
                        jed.second = 1;
                    }
                    jed.first++;
                    if(jed.first > n) return 0;
                }
            }
        }
    }
}