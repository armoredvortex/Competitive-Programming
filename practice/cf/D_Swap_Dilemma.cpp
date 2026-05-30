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

    vll a_sort = a, b_sort = b;
    sort(a_sort.begin(), a_sort.end());
    sort(b_sort.begin(), b_sort.end());

    if (a_sort != b_sort)
    {
        cout << "NO\n";
        return;
    }

    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        if (mp.find(b[i]) != mp.end())
        {
            cout << "YES\n";
            return;
        }
        mp[b[i]] = i;
    }
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        int j = mp[a[i]];
        if (i != j)
        {
            sum++;
        }
        mp[b[i]] = j;
        mp[b[j]] = i;
        swap(b[i], b[j]);
    }
    if (sum % 2 == 0)
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