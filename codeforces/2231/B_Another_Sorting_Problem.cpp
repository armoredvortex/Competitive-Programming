#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long k = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            k = max(k, a[i] - a[i + 1]);
        }
    }

    bool dp0 = true;
    bool dp1 = true;

    for (int i = 0; i < n - 1; i++)
    {
        long long diff = a[i + 1] - a[i];
        bool next_dp0 = false;
        bool next_dp1 = false;

        if (diff < 0)
        {
            next_dp0 = false;
            next_dp1 = dp0;
        }
        else if (diff < k)
        {
            next_dp0 = dp0;
            next_dp1 = dp0 || dp1;
        }
        else
        {
            next_dp0 = dp0 || dp1;
            next_dp1 = dp0 || dp1;
        }

        dp0 = next_dp0;
        dp1 = next_dp1;
    }

    if (dp0 || dp1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--)
        solve();
}