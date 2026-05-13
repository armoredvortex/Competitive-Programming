#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;

    if ((y + x) % 2)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    if (x == y)
    {
        for (int i = 0; i < 2 * x - 1; i++)
        {
            cout << i + 1 << ' ' << i + 2 << '\n';
        }
    }
    else
    {
        int done = 1;
        for (int i = 0; i < 2 * x; i++)
        {
            cout << i + 1 << ' ' << i + 2 << '\n';
            done = max(done, i + 2);
        }

        int remaining = x + y - (2 * x + 1);
        for (int i = 0; i < remaining; i++)
        {
            cout << 1 << ' ' << done + i + 1 << '\n';
        }
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}