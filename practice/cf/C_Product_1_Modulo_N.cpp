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

    vector<int> possible;
    for (ll i = 1; i < n; i++)
    {
        if (gcd(i, n) == 1)
        {
            possible.push_back(i);
        }
    }

    ll pt = 0, pt2 = 0;
    ll num = 1;
    vll ans;
    while (pt < possible.size())
    {
        num = num * possible[pt] % n;
        if (num == 1)
        {
            while (pt2 != pt + 1)
            {
                // cout << possible[pt2] << ' ';
                ans.push_back(possible[pt2]);
                pt2++;
            }
        }
        pt++;
    }
    cout << ans.size() << '\n';
    for (auto e : ans)
    {
        cout << e << ' ';
    }
    cout << '\n';
}