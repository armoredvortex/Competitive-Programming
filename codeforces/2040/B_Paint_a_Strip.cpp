#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << "\n"; // 1
        return;
    }
    if (n <= 4)
    {
        cout << 2 << "\n"; // 2
        return;
    }
    int i = 4;
    int s = 4;
    int result = 2;

    while (i < n)
    {
        i = 2 * (s + 1);
        s = i;
        result++;
    }
    cout << result << "\n"; // result
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