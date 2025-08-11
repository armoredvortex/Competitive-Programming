#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif
#define dbg(v) cout << "Line(" << LINE << ") -> " << #v << " = " << (v) << endl;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    int total = 0;
    int max_dec = 0;
    int max_inc = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] - b[i] > 0)
        {
            total += a[i] - b[i];
        }
    }

    cout << total + 1 << "\n";

    // if (max_inc > max_dec)
    // {
    //     cout << max_inc << "\n";
    // }
    // else
    // {
    //     cout << max_dec + 1 << "\n";
    // }
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