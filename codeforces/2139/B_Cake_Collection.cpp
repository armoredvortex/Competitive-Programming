#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif
#define dbg(v) cout << "Line(" << LINE << ") -> " << #v << " = " << (v) << endl;

void solve()
{
    long long int n, m;
    cin >> n >> m;
    vector<long long int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.rbegin(), v.rend());

    long long int total = 0;

    for (long long int i = 0; i < n; i++)
    {
        if (m - i > 0)
        {
            total += v[i] * (m - i);
        }
    }

    cout << total << "\n";
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