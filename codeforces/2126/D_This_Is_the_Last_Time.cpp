#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif
#define dbg(v) cout << "Line(" << LINE << ") -> " << #v << " = " << (v) << endl;

void solve()
{
    long long int n, k;
    cin >> n >> k;

    vector<vector<long long int>> v;
    for (int i = 0; i < n; i++)
    {
        long long int l, r, re;
        cin >> l >> r >> re;
        v.push_back({re, l, r});
    }

    sort(v.begin(), v.end());
    long long int max = k;
    // for (auto e : v)
    // {
    //     cerr << e << "\n";
    // }
    for (auto e : v)
    {
        if (k >= e[1] && k <= e[2])
        {
            if (e[0] >= k)
            {
                k = e[0];
            }
        }
    }
    cout << k << "\n";
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