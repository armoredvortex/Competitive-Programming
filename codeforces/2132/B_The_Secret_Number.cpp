#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif
#define dbg(v) cout << "Line(" << LINE << ") -> " << #v << " = " << (v) << endl;

long long binpow(long long a, long long b)
{
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

void solve()
{
    long long int n;
    cin >> n;

    vector<long long int> v;
    for (long long int i = 1; i < 19; i++)
    {
        long long int z = binpow(10, i) + 1;

        long long int x = n / z;

        if (x * z == n)
        {
            v.push_back(x);
        }
    }

    sort(v.begin(), v.end());
    if (v.size() == 0)
    {
        cout << 0 << "\n";
        return;
    }
    else
    {
        cout << v.size() << "\n";

        for (long long int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
    }

    cout << "\n";
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