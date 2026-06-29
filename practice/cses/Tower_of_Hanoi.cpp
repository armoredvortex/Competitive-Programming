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

void solve(ll n, ll a, ll b, ll c, vector<pair<ll, ll>> &ans)
{
    if (n == 1)
    {
        ans.push_back({a, c});
        return;
    }
    solve(n - 1, a, c, b, ans);
    ans.push_back({a, c});
    solve(n - 1, b, a, c, ans);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;

    vector<pair<ll, ll>> ans;
    solve(n, 1, 2, 3, ans);
    cout << ans.size() << '\n';
    for (auto e : ans)
    {
        cout << e.first << ' ' << e.second << '\n';
    }
}