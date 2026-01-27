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

    map<ll, ll> m;
    for (ll i = 0; i < n; i++)
    {
        m[a[i]] = i;
    }

    ll left = 0;
    for (ll i = 0; i < n; i++)
    {
        auto e = b[i];
        ll k = 0;
        while (m[b[i]] != -1)
        {
            m[a[left]] = -1;
            left++;
            k++;
        }

        cout << k << ' ';
    }

    cout << '\n';
}