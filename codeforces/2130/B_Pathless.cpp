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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int a = count(v.begin(), v.end(), 0);
    int b = count(v.begin(), v.end(), 1);
    int c = count(v.begin(), v.end(), 2);

    int total = accumulate(v.begin(), v.end(), 0);
    if (s == total)
    {
        cout << -1 << "\n";
        return;
    }
    if (s < total)
    {
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    s -= total;

    for (int i = 0; i < 600; i++)
    {
        for (int j = 0; j < 600; j++)
        {
            if (2 * i + 3 * j == s)
            {
                cout << -1 << "\n";
                return;
            }
        }
    }

    for (int i = 0; i < a; i++)
    {
        cout << 0 << " ";
    }

    for (int i = 0; i < c; i++)
    {
        cout << 2 << " ";
    }

    for (int i = 0; i < b; i++)
    {
        cout << 1 << " ";
    }
    cout << "\n";
    return;

    // if (a)
    // {
    //     if (s % 3 == 0)
    //     {
    //         cout << -1 << "\n";
    //         return;
    //     }
    //     if (s % 2 == 0)
    //     {
    //         cout << -1 << "\n";

    //         return;
    //     }
    // }

    cout << 'h' << "\n";
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