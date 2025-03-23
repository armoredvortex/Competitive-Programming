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
    if (n % 2 == 0)
    {
        if (k % 2 == 0)
        {
            if (n % k == 0)
            {
                cout << n / k << "\n";
            }
            else
            {
                cout << n / k + 1 << "\n";
            }
        }
        else
        {
            if (n % (k - 1) == 0)
            {
                cout << n / (k - 1) << "\n";
            }
            else
            {
                cout << n / (k - 1) + 1 << "\n";
            }
        }
    }
    else
    {
        if (k % 2 == 0)
        {
            cout << n / k + 1 << "\n";
        }
        else
        {
            if (n - k == 0)
            {
                cout << 1 << "\n";
            }
            else
            {
                if ((n - k) % (k - 1) == 0)
                {
                    cout << (n - k) / (k - 1) + 1 << "\n";
                }
                else
                {
                    cout << (n - k) / (k - 1) + 2 << "\n";
                }
            }
        }
    }
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