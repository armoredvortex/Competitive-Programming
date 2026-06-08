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

bool isPal(ll x)
{
    vll digits;
    while (x)
    {
        digits.push_back(x % 10);
        x /= 10;
    }
    vll dcp = digits;
    reverse(dcp.begin(), dcp.end());
    if (dcp == digits)
    {
        return true;
    }
    return false;
}

void solve()
{
    ll n;
    cin >> n;
    if (n % 12 == 10)
    {
        if (n > 262)
        {
            cout << 262 << ' ' << n - 262 << '\n';
        }
        else
        {
            for (ll i = 0; i <= n; i++)
            {
                if (isPal(i) && ((n - i) % 12 == 0))
                {
                    cout << i << ' ' << n - i << '\n';
                    return;
                }
            }
            cout << -1 << '\n';
        }
    }
    else
    {
        cout << n % 12 << ' ' << n - n % 12 << '\n';
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