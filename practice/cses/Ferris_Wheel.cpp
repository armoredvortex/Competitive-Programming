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

    ll n, x;
    cin >> n >> x;

    vector<ll> weights(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    sort(all(weights));
    reverse(all(weights));

    ll i = 0, r = n - 1;

    while (weights[i] > x)
    {
        i++;
    }

    ll ans = 0;
    while (i < r)
    {
        if (weights[i] + weights[r] > x)
        {
            ans++;
            i++;
        }
        else
        {
            ans++;
            i++;
            r--;
        }
    }
    if (i == r)
    {
        ans++;
    }

    cout << ans << '\n';
}