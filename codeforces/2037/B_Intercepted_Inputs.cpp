#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int k;
    cin >> k;

    int product = k - 2;
    vector<int> arr;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    int n, m;
    for (int i = 0; i < k; i++)
    {
        if ((product % arr[i]) == 0)
        {
            n = arr[i];
            m = (product / arr[i]);
            if (binary_search(arr.begin(), arr.end(), m))
            {
                break;
            }
        }
    }

    cout << n << " " << m << "\n";
    // if (binary_search(arr.begin(), arr.end(), 3))
    // {
    //     cout << "hi" << "\n"; // "hi"
    // }
    // for (int i = k - 1; i >= 0; i--)
    // {
    //     cout << arr[i] << " ";
    // }

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