#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif
#define dbg(v) cout << "Line(" << LINE << ") -> " << #v << " = " << (v) << endl;

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0 << "\n";
        return;
    }

    if (b % a == 0 || a % b == 0)
    {
        cout << 1 << "\n";
        return;
    }
    cout << 2 << "\n";
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