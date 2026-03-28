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

const int MOD = 1000000007;
void solve()
{
    ll n;
    cin >> n;
    ll c = 2;
    for (ll i = 2; i <= n; i++)
    {
        c = (4 * c) % MOD;
    }
    cout << c << '\n';
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

// n-1 cuts allowed,
// n-1C0 + n-1C1 + n-1C2 + ... = 2^n-1

// 2x1 horizontal piece
// n-2 * 1 + n-3*2 + n-4*3 + ...