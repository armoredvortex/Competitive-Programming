#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif
#define dbg(v) cout << "Line(" << LINE << ") -> " << #v << " = " << (v) << endl;

void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> xi(m), yi(n);

    for (int i = 0; i < n; i++)
    {
        cin >> yi[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> xi[i];
    }

    cout << n + m << "\n";
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