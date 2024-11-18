#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    cin.ignore();
    char str[15];
    cin >> str;
    cin.ignore();
    int x = 0, y = 0;

    while (1)

    {

        for (int i = 0; i < n; i++)
        {
            // cout << "X:" << x << " Y:" << y << "\n"; // "X:"<< x<< " Y:"<< y

            switch (str[i])
            {
            case 'N':
                y++;
                break;

            case 'E':
                x++;
                break;

            case 'S':
                y--;
                break;

            case 'W':
                x--;
                break;

            default:
                break;
            }
            if (x < -30 || x > 30 || y < -30 || y > 30)
            {
                cout << "NO" << "\n"; // "NO"
                return;
            }
            if ((x == a) && (y == b))
            {
                cout << "YES" << "\n"; // "YES"
                return;
            }
        }

        if ((x == 0) && (y == 0))
        {
            cout << "NO" << "\n"; // "NO"
            return;
        }
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