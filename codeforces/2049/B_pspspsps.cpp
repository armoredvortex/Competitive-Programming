#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    // check if s comes after p
    int p_flag = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'p')
        {
            p_flag = 1;
        }
        if (p_flag)
        {
            if (s[i] == 's')
            {
                cout << "NO" << "\n"; // "NO"
                return;
            }
        }
    }

    int s_flag = 0;
    int s_index = -1;
    int p_flag2 = 0;
    int p_index = -1;
    for (int i = 0; i < s.size(); i++)
    {
        // take last s and first p
        if (s[i] == 's')
        {
            s_index = i;
            s_flag = 1;
        }
        if (s[i] == 'p' && !p_flag2)
        {
            p_index = i;
            p_flag2 = 1;
        }
    }
    if ((s_index == -1) || (p_index == -1))
    {
        cout << "YES" << "\n"; // "YES"
        return;
    }

    if (s_index > 0 && p_index < n - 1)
    {
        cout << "NO" << "\n"; // "NO"
        return;
    }

    cout << "YES" << "\n"; // "YES"
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
        solve();
}