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

bool comp(pair<ll, ll> a, pair<ll, ll> b) {
  return (a.second - a.first) > (b.second - b.first);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  vector<pair<ll, ll>> ranges;
  ll n;
  cin >> n;
  for (ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;

    ranges.push_back({a, b});
  }

  sort(ranges.begin(), ranges.end(), comp);

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    auto e1 = ranges[i];

    ll l = e1.first, r = e1.second;
    for (int j = 0; j < i; j++) {
      auto e2 = ranges[j];

      if (e2.first <= l && e2.second >= r) {
        l = 0;
        r = -1;
        break;
      } else if (e2.first <= l && e2.second >= l) {
        l = e2.second + 1;
      } else if (e2.first <= r && e2.second >= r) {
        r = e2.first - 1;
      }

      if (r < l) {
        l = 0;
        r = -1;
        break;
      }
    }

    ans += r - l + 1;
  }

  cout << ans << '\n';
}
