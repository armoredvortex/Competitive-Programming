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
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int k = v[0];
    int flag = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i] != k)
        {
            flag = 0;
        }
    }
    if (flag)
    {
        cout << "No" << "\n";
    }
    else
    {
        cout << "Yes" << "\n";
        int m = *max_element(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            if (v[i] == m)
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 2 << " ";
            }
        }
        cout << "\n";
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