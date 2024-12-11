#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }
    if (n == 1)
    {
        cout << "YES" << "\n"; // "NO"
        cout << "1" << "\n";   // "1"

        return;
    }
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            int difference = abs(arr[j] - arr[i]) % k;
            if (difference == 0)
            {
                flag = 0;
                break;
            }
            flag = 1;
        }
        if (flag)
        {
            cout << "YES" << "\n"; // "YES"
            cout << i + 1 << "\n"; // index + 1
            return;
        }
    }
    cout << "NO" << "\n"; // "NO"
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