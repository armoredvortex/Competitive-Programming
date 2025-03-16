#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif
#define dbg(v) cout << "Line(" << LINE << ") -> " << #v << " = " << (v) << endl;

void solve()
{
    int l, r;
    cin >> l >> r;
    if (l == 1 && r == 1)
    {
        cout << 1 << "\n";
        return;
    }
    if (l == r)
    {
        cout << 0 << "\n";
        return;
    }
    cout << r - l << "\n";

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