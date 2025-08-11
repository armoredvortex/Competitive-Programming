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

    if (n == 2)
    {
        cout << "-1 2" << "\n";
        return;
    }
    cout << "-1 3 -1" << " ";

    if (n % 2 == 0)
    {
        for (int i = 0; i < n - 4; i++)
        {
            if (i % 2 == 0)
            {
                cout << 3 << " ";
            }
            else
            {
                cout << -1 << " ";
            }
        }
        cout << 2 << "\n";
    }
    else
    {
        for (int i = 0; i < n - 3; i++)
        {
            if (i % 2 == 0)
            {
                cout << 3 << " ";
            }
            else
            {
                cout << -1 << " ";
            }
        }
        cout << "\n";
    }

    // cout << "\n";
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