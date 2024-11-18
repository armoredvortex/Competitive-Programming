#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int counter[n];
    for (int i = 0; i < n; i++)
    {
        counter[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        counter[a - 1]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += counter[i] / 2;
    }
    cout << ans << "\n"; // ans
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}