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
    ll left = 1, right = 1000;
    ll ans, mid1, mid2;
    while (left < right)
    {
        mid1 = left + (right - left) / 3;
        mid2 = left + 2 * (right - left) / 3;
        cout << "? " << mid1 << ' ' << mid2 << '\n';
        cout.flush();

        ll sz;
        cin >> sz;
        if (sz == mid1 * mid2)
        {
            left = mid2 + 1;
        }
        else if (sz == mid1 * (mid2 + 1))
        {
            left = mid1 + 1;
            right = mid2;
        }
        else
        {
            right = mid1;
        }
    }
    cout << "! " << right << '\n';
    cout.flush();
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