#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int flag = 1;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (abs(a - i) > 1)
        {
            flag = 0;
        }
    }

    if (flag)
    {
        cout << "YES" << "\n"; // "YES"
    }
    else
    {
        cout << "NO" << "\n"; // "NO"
    }
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
    {
        solve();
    }

    return 0;
}