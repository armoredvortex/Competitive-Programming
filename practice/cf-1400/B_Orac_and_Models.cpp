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

void factor(vector<ll> &v, ll n)
{
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if (n / i != i)
            {
                v.push_back(n / i);
            }
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vll ans(n);
    for (ll i = 0; i < n; i++)
    {
        vector<ll> factors;
        factor(factors, i + 1);

        ans[i] = 1;
        for (auto e : factors)
        {
            // cerr << e << ' ';
            if (v[e - 1] < v[i])
            {
                ans[i] = max(ans[i], 1 + ans[e - 1]);
            }
        }
        // cerr << '\n';
    }

    cout << *max_element(ans.begin(), ans.end()) << '\n';
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