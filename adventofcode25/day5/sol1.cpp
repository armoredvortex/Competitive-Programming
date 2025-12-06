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

    vector<pair<ll, ll>> ranges;
    for (ll i = 0; i < 187; i++)
    {
        ll a, b;
        cin >> a >> b;

        ranges.push_back({a, b});
    }

    ll ans = 0;
    for (ll i = 0; i < 1000; i++)
    {
        ll ing;
        cin >> ing;

        for (auto e : ranges)
        {
            if (ing >= e.first && ing <= e.second)
            {
                ans++;
                // cout << ing << '\n';
                break;
            }
        }
    }

    cout << ans << '\n';
}
