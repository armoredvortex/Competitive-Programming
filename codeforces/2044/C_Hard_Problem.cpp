#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    int total = 2 * m;

    int seated = 0;
    if (a <= m)
    {
        seated += a;
    }
    else
    {
        seated += m;
    }
    if (b <= m)
    {
        seated += b;
    }
    else
    {
        seated += m;
    }

    int empty = total - seated;
    if (empty > c)
    {
        seated += c;
    }
    else
    {
        seated += empty;
    }

    cout << seated << "\n"; // seated
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