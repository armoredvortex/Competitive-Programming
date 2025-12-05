#include <bits/stdc++.h>
#include "debugging.h"

using namespace std;

int main()
{
    vector<vector<char>> v(140, vector<char>(140, '.')), cpy(140, vector<char>(140, '.'));

    for (int i = 1; i < 139; i++)
    {
        for (int j = 1; j < 139; j++)
        {
            cin >> v[i][j];
            cpy[i][j] = v[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i < 139; i++)
    {
        for (int j = 1; j < 139; j++)
        {
            if (v[i][j] != '@')
            {
                continue;
            }
            int ct = 0;
            for (int i1 = -1; i1 <= 1; i1++)
            {
                for (int j1 = -1; j1 <= 1; j1++)
                {
                    if (i1 == 0 && j1 == 0)
                    {
                        continue;
                    }

                    if (v[i + i1][j + j1] == '@')
                    {
                        ct++;
                    }
                }
            }
            if (ct < 4)
            {
                ans++;
                cpy[i][j] = 'x';
            }
        }
    }

    cout << cpy;

    cout << ans << '\n';
}