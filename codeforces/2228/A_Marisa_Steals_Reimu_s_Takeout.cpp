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

    vll v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans = 0;
    ans += count(v.begin(), v.end(), 0);
    int ct = count(v.begin(), v.end(), 1);
    int ct2 = count(v.begin(), v.end(), 2);

    int k = min(ct, ct2);
    ans += k;
    ct -= k;
    ct2 -= k;
    ans += ct / 3;
    ans += ct2 / 3;
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
}