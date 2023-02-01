#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> p(n, 0);
    for (int t = n - k; t < n; p[t++] = 1);
    for(auto x : p) cout << x << " ";
    cout << '\n';

    do {
        for (bool x : p) cout << x; cout << endl;
    } while (next_permutation(p.begin(), p.end()));
    return 0;
}