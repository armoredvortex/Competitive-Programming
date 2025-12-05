#include <bits/stdc++.h>
#include "debugging.h"

using namespace std;

int main()
{
    int sz = 140;
    vector<vector<char>> v(sz, vector<char>(sz, '.')), cpy(sz, vector<char>(sz, '.'));

    for (int i = 1; i < sz - 1; i++)
    {
        for (int j = 1; j < sz - 1; j++)
        {
            cin >> v[i][j];
            cpy[i][j] = v[i][j];
        }
    }

    int ans = 0;
    while (true)
    {
        int subans = 0;

        for (int i = 1; i < sz - 1; i++)
        {
            for (int j = 1; j < sz - 1; j++)
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
                    subans++;
                    cpy[i][j] = '.';
                }
            }
        }

        v = cpy;

        if (subans == 0)
        {
            break;
        }
        ans += subans;
    }
    cout << ans;
}