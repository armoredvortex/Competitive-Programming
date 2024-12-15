#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = 0;
    }
    int counter = 1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (arr[a] == 0)
        {
            cout << a << " ";
            arr[a] = 1;
        }
        else
        {
            if (arr[counter] == 1)
            {
                for (int i = counter; i <= n; i++)
                {
                    counter++;
                    if (arr[counter] == 0)
                    {
                        break;
                    }
                }
            }
            cout << counter << " ";
            arr[counter] = 1;
            counter++;
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