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

    vector<int> v;
    while (n)
    {
        v.push_back(n % 3);
        n /= 3;
    }

    map<int, long long int> m;
    for (int i = 0; i < 30; i++)
    {
        m[i] = pow(3, i + 1) + i * pow(3, i - 1);
        // cerr << m[i] << "\n";
    }

    // cerr << v << "\n";

    long long int total = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int k = v.size() - i - 1;

        total += v[k] * m[k];
    }

    cout << total << "\n";

    // cerr << v << "\n";
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