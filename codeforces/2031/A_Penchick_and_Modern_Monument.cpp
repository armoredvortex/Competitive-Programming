#include <bits/stdc++.h>
using namespace std;

void printArray(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(ptr + i) << " ";
    }
}
void solve()
{
    int n;
    cin >> n;
    int *counter = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        (*(counter + h - 1)) += 1;
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if ((*(counter + i)) > max)
        {
            max = (*(counter + i));
        }
    }

    int ans = n - max;
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

    return 0;
}