#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif
#define dbg(v) cout << "Line(" << LINE << ") -> " << #v << " = " << (v) << endl;

void solve()
{
    float n, k, p;
    cin >> n >> k >> p;

    int req = ceil(abs(k) / p);
    if (req > n)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << req << "\n";
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