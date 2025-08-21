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
    string a;
    cin >> a;

    int m;
    cin >> m;
    string b, c;
    cin >> b >> c;

    string s1, s2;
    for (int i = 0; i < m; i++)
    {
        if (c[i] == 'D')
        {
            s1 += b[i];
        }
        else
        {
            s2 = b[i] + s2;
        }
    }

    // cerr << s1 << "\n";
    // cerr << s2 << "\n";

    cout << s2 << a << s1 << "\n";
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