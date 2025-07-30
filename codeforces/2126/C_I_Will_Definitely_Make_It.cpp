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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int curr_height = v[k - 1];
    sort(v.begin(), v.end());
    int st_index = lower_bound(v.begin(), v.end(), curr_height) - v.begin();
    int water = 1;
    // cout << v << "\n";
    // cout << st_index << "\n";

    for (int i = st_index; i < n - 1; i++)
    {
        // cout << v[i + 1] - v[i] << "\n";
        // cout << v[i] - water + 1 << "\n";

        if (v[i + 1] - v[i] > v[i] - water + 1)
        {
            cout << "NO" << "\n";
            return;
        }
        water += v[i + 1] - v[i];
    }
    cout << "YES" << "\n";
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