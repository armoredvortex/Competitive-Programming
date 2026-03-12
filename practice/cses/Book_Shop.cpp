#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
// vector<vector<ll>> memo;
unordered_map<pair<ll, ll>, ll> memo;

ll dp(vector<pair<ll, ll>> &lib, ll money, ll i)
{

    if (i == n || money == 0)
    {
        return 0;
    }

    if (memo[{i, money}] != 0)
    {
        return memo[{i, money}];
    }

    ll result = dp(lib, money, i + 1);

    if (money >= lib[i].first)
    {
        result = max(result, lib[i].second + dp(lib, money - lib[i].first, i + 1));
    }
    return memo[{i, money}] = result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll x;
    cin >> n >> x;

    vector<pair<ll, ll>> lib(n);
    for (int i = 0; i < n; i++)
        cin >> lib[i].first;
    for (int i = 0; i < n; i++)
        cin >> lib[i].second;

    // memo.assign(n, vector<ll>(x + 1, -1));

    cout << dp(lib, x, 0) << "\n";
    return 0;
}