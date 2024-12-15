#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    for (int i = s.size() - 1; i > -1; i--)
    {
        if (s[i] == 'p')
        {
            cout << 'q';
        }
        else if (s[i] == 'q')
        {
            cout << 'p';
        }
        else
        {
            cout << s[i];
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