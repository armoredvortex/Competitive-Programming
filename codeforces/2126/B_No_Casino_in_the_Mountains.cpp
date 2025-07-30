#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif
#define dbg(v) cout << "Line(" << LINE << ") -> " << #v << " = " << (v) << endl;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> sqs;
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            ct++;
        }
        else
        {
            if (ct)
            {
                sqs.push_back(ct);
            }
            ct = 0;
        }
    }
    if (ct)
    {
        sqs.push_back(ct);
    }
    // cerr << sqs << "\n";

    int total = 0;
    for (int i = 0; i < sqs.size(); i++)
    {
        while (sqs[i] >= k)
        {
            sqs[i] -= k + 1;
            total++;
        }
    }
    cout << total << "\n";
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