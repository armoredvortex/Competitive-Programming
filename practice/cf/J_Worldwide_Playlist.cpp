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

    ll n, d;
    cin >> n >> d;

    vll a(n);
    vll b(n);

    map<int, int> mp;
    map<int, int> prio;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        prio[b[i]] = i;
    }

    int prev = 0;
    int ans = 0;
    for (auto e : b)
    {
        ans += (n + mp[e] - prev) % n;
        prev = mp[e] + 1;
    }

    cout << ans << '\n';

    for (int i = 0; i < d; i++)
    {
        int c, x, y;
        cin >> c >> x >> y;
        x--;
        y--;

        if (c == 1)
        {
            
        }
        else
        {
        }
    }
}