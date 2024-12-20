#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }

    // check all zeroes
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        cout << 0 << "\n"; // 1
        return;
    }

    // check no zeroes
    int flag2 = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            flag2 = 0;
            break;
        }
    }
    if (flag2)
    {
        cout << 1 << "\n"; // 1
        return;
    }

    // count islands
    int island_c = 0;
    int island = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            if (!island)
            {
                island_c++;
            }
            island = 1;
        }
        if (arr[i] == 0)
        {
            if (island)
            {
                island = 0;
            }
        }
    }
    if (island_c > 1)
    {
        cout << 2 << "\n"; // 2
        return;
    }
    else
    {
        cout << 1 << "\n"; // 1
        return;
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