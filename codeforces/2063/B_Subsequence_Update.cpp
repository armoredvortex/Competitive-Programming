
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif
#define dbg(v) cout << "Line(" << LINE << ") -> " << #v << " = " << (v) << endl;

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> v, v1, v2;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    for (int i = 0; i < r; i++)
    {
        v1.push_back(v[i]);
    }

    for (int i = l - 1; i < v.size(); i++)
    {
        v2.push_back(v[i]);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int count = r - l + 1;
    long long int total1 = 0;
    long long int total2 = 0;
    for (int i = 0; i < count; i++)
    {
        total1 += v1[i];
        total2 += v2[i];
    }

    long long int min = (total1 < total2) ? total1 : total2;

    cout << min << "\n";
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