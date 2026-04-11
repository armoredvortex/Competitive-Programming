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

string s;
vector<ll> calcPt(ll n, ll remain)
{
    ll x = 0, y = 0, z = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'E')
        {
            x++;
        }
        else if (s[i] == 'W')
        {
            x--;
        }
        else if (s[i] == 'N')
        {
            y++;
        }
        else if (s[i] == 'S')
        {
            y--;
        }
        else if (s[i] == 'U')
        {
            z++;
        }
        else if (s[i] == 'D')
        {
            z--;
        }
    }

    x *= n;
    y *= n;
    z *= n;

    ll xr = 0, yr = 0, zr = 0;
    for (int i = 0; i < remain; i++)
    {
        if (s[i] == 'E')
        {
            xr++;
        }
        else if (s[i] == 'W')
        {
            xr--;
        }
        else if (s[i] == 'N')
        {
            yr++;
        }
        else if (s[i] == 'S')
        {
            yr--;
        }
        else if (s[i] == 'U')
        {
            zr++;
        }
        else if (s[i] == 'D')
        {
            zr--;
        }
    }

    x += xr, y += yr, z += zr;

    return {x, y, z};
}

void solve()
{
    ll n;
    cin >> n;
    cin >> s;
    ll x, y, z;
    cin >> x >> y >> z;

    ll left = 0, right = 1e10;
    ll mid, ans = -1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        ll complete = mid / n;
        ll remain = mid % n;

        auto e = calcPt(complete, remain);
        ll manhat = abs(x - e[0]) + abs(y - e[1]) + abs(z - e[2]);

        if (mid >= manhat)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << ans << '\n';
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