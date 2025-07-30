#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif
#define dbg(v) cout << "Line(" << LINE << ") -> " << #v << " = " << (v) << endl;

void solve()
{
    int x;
    cin >> x;

    int smallest = 10;
    while (x)
    {
        int dig = x % 10;
        if (dig < smallest)
        {
            smallest = dig;
        }
        x /= 10;
    }
    cout << smallest << "\n";
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