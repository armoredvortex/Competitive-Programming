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

    vector<long long int> v;
    while (n)
    {
        v.push_back(n % 3);
        n /= 3;
    }

    map<long long int, long long int> m;
    for (int i = 0; i < 30; i++)
    {
        m[i] = pow(3, i + 1) + i * pow(3, i - 1);
    }

    reverse(v.begin(), v.end());

    long long int avail_deals = k - accumulate(v.begin(), v.end(), 0ll);

    if (avail_deals < 0)
    {
        cout << -1 << "\n";
        return;
    }
    // cerr << v << "\n";

    for (int i = 0; i < v.size() - 1; i++)
    {
        long long int can_avail = avail_deals / 2;
        long long int real_avail = min(can_avail, v[i]);
        v[i] -= real_avail;
        v[i + 1] += 3 * real_avail;
        avail_deals -= 2 * real_avail;
        // while ((avail_deals >= 2) && (v[i] > 0))
        // {
        //     v[i]--;
        //     v[i + 1] += 3;
        //     avail_deals -= 2;
        // }
    }

    // cerr << v << "\n";

    // cerr << avail_deals << "\n";

    // cerr << v << "\n";

    // cerr << m << "\n";

    long long int total = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int k = v.size() - i - 1;

        total += v[i] * m[k];
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