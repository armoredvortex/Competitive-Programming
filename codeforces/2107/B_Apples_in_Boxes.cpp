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
    vector<long long int> v;
    for (int i = 0; i < n; i++)
    {
        long long int a;
        cin >> a;
        v.push_back(a);
    }

    long long int m0 = *max_element(v.begin(), v.end());
    long long int m1 = *min_element(v.begin(), v.end());

    if (m0 - m1 <= k)
    {
        long long int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = (sum + v[i]) % 2;
        }
        if (sum == 1)
        {
            cout << "Tom" << "\n";
        }
        else
        {
            cout << "Jerry" << "\n";
        }
        return;
    }

    // cerr << "hi" << n << k << "\n";

    long long int m0_c = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == m0)
        {
            m0_c++;
        }
    }
    if (m0_c > 1)
    {
        cout << "Jerry" << "\n";
        return;
    }
    else
    {
        if (m0 - 1 - m1 > k)
        {
            cout << "Jerry" << "\n";
        }
        else
        {
            long long int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum = (sum + v[i]) % 2;
            }
            if (sum == 1)
            {
                cout << "Tom" << "\n";
            }
            else
            {
                cout << "Jerry" << "\n";
            }
        }
    }

    // cout << 'h' << "\n";
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