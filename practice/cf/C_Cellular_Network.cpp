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

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m;
    cin >> n >> m;

    vll a(n), b(m);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll r = 0;
    ll left = 0;
    for (ll i = 0; i < n; i++)
    {
        while (left < m - 1 && b[left] < a[i])
        {
            left++;
        }

        if (left > 0)
        {
            r = max(r, min(abs(b[left] - a[i]), abs(b[left - 1] - a[i])));
        }
        else
        {
            r = max(r, abs(b[left] - a[i]));
        }
        // r = max(r, abs(b[left] - a[i]));

        // if (left > 0)
        // {
        //     r = min(r, abs(b[left - 1] - a[i]));
        // }
    }
    cout << r << '\n';
    return 0;
}