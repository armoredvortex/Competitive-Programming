#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int f = 0;
    map<int, int> m;
    for (auto &x : v)
    {
        cin >> x;
        m[x]++;
        if (m[x] > 1)
            f = 1;
    }
    if (v.size() % 2 == 0 && f == 0)
    {
        cout << "Bob";
        return;
    }
    cout << "Alice";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }

    return 0;
}