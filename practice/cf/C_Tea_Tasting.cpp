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
    ll n;
    cin >> n;
    vll a(n), b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vll pre(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        pre[i + 1] += b[i];
        pre[i + 1] += pre[i];
    }

    vll inc(n, 0), dec(n, 0), ext(n, 0);

    for (ll i = 0; i < n; i++)
    {
        auto it = lower_bound(pre.begin(), pre.end(), a[i] + pre[i]);
        ll idx = it - pre.begin();
        if (idx - 1 <= i)
        {
            ext[i] += a[i];
            continue;
        }
        if (it == pre.end())
        {
            inc[i]++;
            dec[n - 1]++;
        }
        else if (*it == a[i] + pre[i])
        {
            inc[i]++;
            dec[idx - 1]++;
        }
        else
        {
            inc[i]++;
            dec[idx - 2]++;
            ext[idx - 1] += a[i] + pre[i] - *(--it);
        }
    }

    // cerr << inc << '\n'
    //      << dec << '\n'
    //      << ext << '\n';

    ll curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr += inc[i];
        cout << curr * b[i] + ext[i] << ' ';
        curr -= dec[i];
    }
    cout << '\n';
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