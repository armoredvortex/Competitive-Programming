#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

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

    if (n == 1)
    {
        cout << max(a[0], b[0]) << '\n';
        return 0;
    }

    long long dp[n][2];

    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[1][0] = a[1] + b[0];
    dp[1][1] = b[1] + a[0];
    for (ll i = 2; i < n; i++)
    {
        dp[i][0] = a[i] + max(dp[i - 1][1], dp[i - 2][1]);
        dp[i][1] = b[i] + max(dp[i - 1][0], dp[i - 2][0]);
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]);
    // for (auto e : dp)
    // {
    //     cerr << e[0] << ' ';
    // }
    // cerr << '\n';
    // for (auto e : dp)
    // {
    //     cerr << e[1] << ' ';
    // }
    // cerr << '\n';
}