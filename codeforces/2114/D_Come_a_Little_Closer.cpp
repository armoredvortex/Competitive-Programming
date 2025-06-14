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

    vector<pair<int, int>> v_x, v_y;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v_x.push_back({x, i});
        v_y.push_back({y, i});
    }

    if (n == 1)
    {
        cout << 1 << "\n";
        return;
    }

    sort(v_x.begin(), v_x.end());
    sort(v_y.begin(), v_y.end());

    vector<vector<long long int>> v;
    for (int i = 0; i < n; i++)
    {
        int minx, miny, maxx, maxy;
        if (v_x[0].second != i)
        {
            minx = v_x[0].first;
        }
        else
        {
            minx = v_x[1].first;
        }

        if (v_y[0].second != i)
        {
            miny = v_y[0].first;
        }
        else
        {
            miny = v_y[1].first;
        }

        if (v_x[n - 1].second != i)
        {
            maxx = v_x[n - 1].first;
        }
        else
        {
            maxx = v_x[n - 2].first;
        }

        if (v_y[n - 1].second != i)
        {
            maxy = v_y[n - 1].first;
        }
        else
        {
            maxy = v_y[n - 2].first;
        }

        v.push_back({minx, miny, maxx, maxy});
    }

    long long int min_a = LONG_LONG_MAX;
    int min_ind = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        auto pt = v[i];
        long long int area = (abs(pt[0] - pt[2]) + 1) * (abs(pt[1] - pt[3]) + 1);
        if (area < min_a)
        {
            min_a = area;
            min_ind = i;
        }
    }

    if (min_a == n - 1)
    {

        long long int extra_a = min(abs(v[min_ind][0] - v[min_ind][2]) + 1, abs(v[min_ind][1] - v[min_ind][3]) + 1);
        cout << min_a + extra_a << "\n";
    }
    else
    {
        cout << min_a << "\n";
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

// std::sort(v.begin(), v.end(), [](auto &left, auto &right) {
// return left.second < right.second;
// });