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
    ll n, k;
    cin >> n >> k;

    ll left = 1;
    vll resp;
    while (left + k - 1 <= n)
    {
        cout << "? " << left << '\n';
        cout.flush();
        ll a;
        cin >> a;
        resp.push_back(a);
        left += k;
    }

    ll total = 0;
    for (auto e : resp)
    {
        total ^= e;
    }

    if (n % k == 0)
    {
        cout << "! " << total << '\n';
        cout.flush();
    }
    else
    {
        cout << "? " << n - k + 1 - (n % k) / 2 << '\n';
        cout.flush();
        ll a;
        cin >> a;

        cout << "? " << n - k + 1 << '\n';
        cout.flush();
        ll b;
        cin >> b;

        total ^= (a ^ b);
        cout << "! " << total << '\n';
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}