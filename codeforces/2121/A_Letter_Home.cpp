#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif
#define dbg(v) cout << "Line(" << LINE << ") -> " << #v << " = " << (v) << endl;

void solve()
{
    int n, s;
    cin >> n >> s;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    int m0 = *min_element(x.begin(), x.end());
    int m1 = *max_element(x.begin(), x.end());

    if (s > m1)
    {
        cout << s - m0 << "\n";
        return;
    }
    if (s < m0)
    {
        cout << m1 - s << "\n";
        return;
    }

    cout << abs(m0 - m1) + min(abs(m0 - s), abs(m1 - s)) << "\n";
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