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
    vector<long long int> a(n), a_cpy(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        a_cpy[i] = a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    if (a.back() != b.back())
    {
        cout << "NO" << "\n";
        return;
    }

    for (int i = n - 2; i >= 0; i--)
    {

        if (a[i] == b[i])
        {
            continue;
        }
        if ((a[i] ^ a_cpy[i + 1]) == b[i])
        {
            a[i] = (a[i] ^ a_cpy[i + 1]);
            continue;
        }
        else
        {
            a[i] = a[i] ^ a[i + 1];
            if (a[i] == b[i])
            {
                continue;
            }
        }

        cout << "NO" << "\n";
        return;
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