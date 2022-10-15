#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t, n, jed, teraz, par, sumA, sumB;
    string s, a, b;
    bool blad;
    cin >> t;
    for(int qwer = 0; qwer < t; qwer++)
    {
        cin >> n >> s;
        jed = 0;
        teraz = 0;
        par = 0;
        a = ""; b = "";
        // cout << "test " << qwer << '\n';
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1') jed++;
        }
        // cout << jed << " jedynek\n";
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
            {
                if(teraz < jed/2)
                {
                    a += '(';
                    b += '(';
                }
                else
                {
                    a += ')';
                    b += ')';
                }
                teraz++;
            }
            else
            {
                if(par)
                {
                    a += '(';
                    b += ')';
                }
                else
                {
                    a += ')';
                    b += '(';
                }
                par = (par + 1) % 2;
            }
        }
        // cout << "a = " << a << "\nb = " << b << '\n';
        sumA = 0; sumB = 0; blad = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] == '(') sumA++;
            if(a[i] == ')') sumA--;
            if(b[i] == '(') sumB++;
            if(b[i] == ')') sumB--;
            if(sumA < 0 || sumB < 0) break;
        }
        if(sumA != 0 || sumB != 0)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n" << a << '\n' << b << '\n';
    }
}