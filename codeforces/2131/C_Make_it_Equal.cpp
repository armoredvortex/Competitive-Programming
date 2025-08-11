#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif
#define dbg(v) cout << "Line(" << LINE << ") -> " << #v << " = " << (v) << endl;

void solve()
{
    long long int n, k;
    cin >> n >> k;
    vector<long long int> s(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    multiset<long long int> t;
    for (int i = 0; i < n; i++)
    {
        long long int a;
        cin >> a;
        a %= k;
        t.insert(a);
    }

    for (int i = 0; i < n; i++)
    {
        long long int a1 = s[i] % k;
        if (t.find(a1) != t.end())
        {
            t.erase(t.find(a1));
            continue;
        }

        long long int a2 = k - (s[i] % k);
        if (t.find(a2) != t.end())
        {
            t.erase(t.find(a2));
            continue;
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