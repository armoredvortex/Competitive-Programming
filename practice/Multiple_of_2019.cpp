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

    string s;
    cin >> s;

    vector<ll> sfx(s.size() + 1, 0);
    ll cur = 1;
    for (ll i = s.size() - 1; i >= 0; i--)
    {
        sfx[i] = ((s[i] - '0') * cur + sfx[i + 1]) % 2019;
        cur = (cur * 10) % 2019;
    }

    ll ans = 0;
    map<ll, ll> mp;
    for (auto e : sfx)
    {
        ans += mp[e];
        mp[e]++;
    }
    cout << ans;
    return 0;
}