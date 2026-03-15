#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<double> c(n), p(n);

    for (int i = 0; i < n; i++)
    {
        cin >> c[i] >> p[i];
    }

    double ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        double skip = ans;
        double take = c[i] + ans * (1.0 - (1.0 * p[i]) / 100);

        ans = max(skip, take);
    }

    cout << fixed << setprecision(8);
    cout << ans << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}