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
    string s;
    cin >> s;

    set<char> c;

    c.insert(s[0]);
    c.insert(s[n - 1]);
    int flag = 1;
    for (int i = 1; i < n - 1; i++)
    {
        if (c.find(s[i]) == c.end())
        {
            c.insert(s[i]);
        }
        else
        {
            flag = 0;
            break;
        }
    }

    if (!flag)
    {
        cout << "Yes" << "\n";
    }
    else
    {
        cout << "No" << "\n";
    }
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