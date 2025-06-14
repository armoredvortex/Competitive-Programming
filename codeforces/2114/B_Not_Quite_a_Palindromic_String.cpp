#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif
#define dbg(v) cout << "Line(" << LINE << ") -> " << #v << " = " << (v) << endl;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            a++;
        }
        else
        {
            b++;
        }
    }

    int diff = (a > b) ? (a - b) : (b - a);
    int forced_p = diff >> 1;

    if (forced_p > k)
    {
        cout << "NO" << "\n";
        return;
    }
    int rem_p = k - forced_p;
    if (rem_p % 2 == 0)
    {
        cout << "YES" << "\n";
    }
    else
    {
        cout << "NO" << "\n";
    }
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