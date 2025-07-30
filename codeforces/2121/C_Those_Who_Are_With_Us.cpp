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
    vector<vector<int>> v(n);

    int m0 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            v[i].push_back(a);
            if (a > m0)
            {
                m0 = a;
            }
        }
    }

    int m0x, m0y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == m0)
            {
                m0x = i;
                m0y = j;
                break;
            }
        }
    }

    vector<pair<int, int>> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == m0)
            {
                k.push_back({i, j});
            }
        }
    }

    // for (int i = 0; i < k.size(); i++)
    // {
    //     cerr << k[i].first << " " << k[i].second << "\n";
    // }

    if (k.size() < 3)
    {
        cout << m0 - 1 << "\n";
        return;
    }

    vector<int> x(n, 0), y(m, 0);
    for (int i = 0; i < k.size(); i++)
    {
        x[k[i].first]++;
        y[k[i].second]++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == m0)
            {
                if (x[i] + y[j] == k.size() + 1)
                {
                    cout << m0 - 1 << "\n";
                    return;
                }
            }
            else
            {
                if (x[i] + y[j] == k.size())
                {
                    cout << m0 - 1 << "\n";
                    return;
                }
            }
        }
    }
    cout << m0 << "\n";
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