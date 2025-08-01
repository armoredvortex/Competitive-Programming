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
    vector<pair<int, int>> v(n), v_cpy(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
        v_cpy[i] = {a, b};
    }

    sort(v.begin(), v.end());

    vector<pair<int, int>> selected;
    for (int i = 1; i < 2 * n; i++)
    {
        int maxb = -1;
        for (auto &e : v)
        {
            if (e.first == i)
            {
                if (e.second > maxb)
                {
                    maxb = e.second;
                }
            }
        }
        if (maxb != -1)
        {
            selected.push_back({i, maxb});
        }
    }

    vector<int> k;
    for (auto e : selected)
    {
        // cerr << e << "\n";

        for (int i = 0; i < n; i++)
        {
            if (e.first == v_cpy[i].first && e.second == v_cpy[i].second)
            {
                k.push_back(i + 1);
            }
        }
    }

    cout << k.size() << "\n";
    for (int i = 0; i < k.size(); i++)
    {
        cout << k[i] << " ";
    }
    cout << "\n";
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