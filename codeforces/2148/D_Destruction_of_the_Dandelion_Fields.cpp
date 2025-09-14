#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif
#define dbg(v) cout << "Line(" << LINE << ") -> " << #v << " = " << (v) << endl;

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> odd, even;

    for (int i = 0; i < n; i++)
    {
        long long int a;
        cin >> a;
        if (a % 2 == 0)
        {
            even.push_back(a);
        }
        else
        {
            odd.push_back(a);
        }
    }

    long long int total = 0;
    if (odd.size() != 0)
    {
        total += accumulate(even.begin(), even.end(), 0ll);
    }

    sort(odd.rbegin(), odd.rend());
    for (int i = 0; i < (odd.size() + 1) / 2; i++)
    {
        total += odd[i];
    }

    cout << total << "\n";
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