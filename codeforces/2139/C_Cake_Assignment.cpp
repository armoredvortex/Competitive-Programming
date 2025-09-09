#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif
#define dbg(v) cout << "Line(" << LINE << ") -> " << #v << " = " << (v) << endl;

void solve()
{
    long long int k, x;
    cin >> k >> x;

    vector<int> v;
    for (int i = 0; i < k + 1; i++)
    {
        v.push_back(x % 2);
        x /= 2;
    }

    reverse(v.begin(), v.end());

    int r = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 1)
        {
            r = i;
        }
    }

    vector<int> ops(r);
    for (int i = 0; i < r; i++)
    {
        if (v[i] == 1)
        {
            ops[i] = 2;
        }
        else
        {
            ops[i] = 1;
        }
    }

    reverse(ops.begin(), ops.end());
    cout << ops.size() << "\n";

    for (auto &e : ops)
    {
        cout << e << ' ';
    }
    cout << "\n";

    // cerr << v << "\n";

    // cerr << r << "\n";
    // cerr << ops << "\n";

    // vector<int> ops;
    // for (int i = 0; i < r; i++)
    // {
    //     // if ()
    // }
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