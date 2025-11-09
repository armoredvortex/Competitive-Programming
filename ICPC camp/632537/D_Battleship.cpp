#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    int m[11][11];

    for (int i = 0; i <= 10; i++)
    {
        for (int j = 0; j <= 10; j++)
        {
            m[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int d, l, r, c;

        cin >> d >> l >> r >> c;

        if (r > 10 || r <= 0 || c > 10 || c <= 0)
        {
            cout << 'N' << "\n";
            return 0;
        }

        if (d == 1)
        {
            if (r + l - 1 > 10)
            {
                cout << 'N' << "\n";
                return 0;
            }

            for (int k = 0; k < l; k++)
            {
                if (m[r + k][c] == 1)
                {
                    cout << 'N' << "\n";
                    return 0;
                }
                m[r + k][c] = 1;
            }
        }
        else
        {
            if (c + l - 1 > 10)
            {
                cout << 'N' << "\n";
                return 0;
            }

            for (int k = 0; k < l; k++)
            {
                if (m[r][c + k] == 1)
                {
                    cout << 'N' << "\n";
                    return 0;
                }
                m[r][c + k] = 1;
            }
        }
    }

    cout << 'Y' << "\n";
    return 0;
}