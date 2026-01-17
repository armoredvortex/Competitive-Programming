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

    vector<ll> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll ans = 0;
    set<ll> bag;

    ll left = 0, right = 0;

    // while (right < n)
    // {
    // }

    ll k = bag.size();
    ans += k * (k - 1) / 2;

    cout << ans;
}

// 1 2 3 1 4 2 5
// x x x
//   x x x x