#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif
#define dbg(v) cout << "Line(" << LINE << ") -> " << #v << " = " << (v) << endl;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    pair<int, int> curr = {0, 0};

    long long int points = 0;
    for (int i = 0; i < n; i++)
    {
        if (curr.second == v[i].second)
        {
            int diff = v[i].first - curr.first;
            if (diff % 2 == 1)
            {
                points += diff - 1;
            }
            else
            {
                points += diff;
            }
        }
        else
        {
            int diff = v[i].first - curr.first;
            if (diff % 2 == 1)
            {
                points += diff;
            }
            else
            {
                points += diff - 1;
            }
        }

        curr = v[i];
    }

    points += m - v.back().first;
    cout << points << "\n";
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