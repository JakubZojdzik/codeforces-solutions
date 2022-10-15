#include <bits/stdc++.h>
using namespace std;

int R[2][1000007];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int rewq;
    cin >> rewq;
    string s;
    for (int qwerty = 0; qwerty < rewq; qwerty++)
    {
        cin >> s;
        int N = s.size();
        int i, j, rp, k, zapas = 0;
        for (int i = 0; i < N / 2; i++)
        {
            if (s[i] == s[N - i - 1])
                zapas++;
            else
                break;
        }
        s = "@" + s + "#";

        for (int t = 0; t <= 1; t++)
        {
            R[t][0] = 0;
            rp = 0;
            i = 1;
            while (i <= N)
            {
                while (s[i - rp - 1] == s[i + t + rp])
                    rp++;
                R[t][i] = rp;
                k = 1;
                while ((R[t][i - k] != rp - k) && (k < rp))
                {
                    R[t][i + k] = min(R[t][i - k], rp - k);
                    k++;
                }
                rp = max(rp - k, 0);
                i += k;
            }
        }
        s = s.substr(1, N);
        int val = 0;
        pair<int, int> center;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j <= 1; j++)
            {
                rp = R[j][i];

                if (i - rp - 1 <= zapas && val < min(N, 2 * i + j - 2) && i - rp - 1 <= N - (rp + i + j - 1))
                {
                    val = min(N, 2 * i + j - 2);
                    center = {j, i};
                }
                if (N - (rp + i + j - 1) <= zapas && val < min(N, 2 * N - 2 * i - j + 2) && i - rp - 1 >= N - (rp + i + j - 1))
                {
                    val = min(N, 2 * N - 2 * i - j + 2);
                    center = {j, i};
                }
            }
        }
        j = center.first;
        i = center.second;
        if (i - R[j][i] - 1 <= zapas && i - R[j][i] - 1 <= N - (R[j][i] + i + j - 1))
        {
            cout << s.substr(0, R[j][i] + i + j - 1) + s.substr(N - (i - R[j][i])+1, i - R[j][i]) << '\n';
        }
        else
        {
            cout << s.substr(0, N - (R[j][i] + i + j - 1)) + s.substr(i - R[j][i] - 1, N - (i - R[j][i] - j - 1)) << '\n';
        }
    }
}
