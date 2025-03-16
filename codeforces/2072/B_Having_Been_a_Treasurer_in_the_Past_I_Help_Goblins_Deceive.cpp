#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif
#define dbg(v) cout << "Line(" << LINE << ") -> " << #v << " = " << (v) << endl;

void solve()
{
    long long int n;
    string s;
    cin >> n;
    cin >> s;

    long long int a = 0, b = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '-')
        {
            a++;
        }
        else
        {
            b++;
        }
    }

    if (a <= 1)
    {
        cout << 0 << "\n";
        return;
    }
    if (b == 0)
    {
        cout << 0 << "\n";
        return;
    }
    if (a % 2 == 0)
    {
        long long int o = (a / 2) * (a / 2) * b;
        cout << o << "\n";
        return;
    }
    else
    {
        long long int o = (a / 2) * (a / 2 + 1) * b;
        cout << o << "\n";
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}