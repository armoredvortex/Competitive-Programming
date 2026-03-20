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

pair<ll, ll> dir(char c)
{
    if (c == 'U')
    {
        return {0, 1};
    }
    else if (c == 'D')
    {
        return {0, -1};
    }
    else if (c == 'R')
    {
        return {1, 0};
    }
    else
    {
        return {-1, 0};
    }
}

double dist(pair<ll, ll> p1, pair<ll, ll> p2)
{
    // return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p2.second - p1.second) * (p2.second - p1.second));
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll x1, y1;
    ll x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<ll, ll>> offset(n + 1);

    // offset[0] = dir(s[0]);
    offset[0] = {0, 0};

    for (ll i = 0; i < n; i++)
    {
        offset[i + 1] = {offset[i].first + dir(s[i]).first, offset[i].second + dir(s[i]).second};
    }

    ll left = 0, right = 1e15;
    ll ans = -1;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;

        ll complete = mid / n;
        ll extra = mid % n;
        pair<ll, ll> pos = {x1 + offset.back().first * complete + offset[extra].first, y1 + offset.back().second * complete + offset[extra].second};

        // cerr << pos << ' ' << mid << '\n';
        if (dist(pos, {x2, y2}) <= mid)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ans;
    return 0;
}