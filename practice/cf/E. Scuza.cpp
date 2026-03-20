#include <algorithm>
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

void solve() {
  ll n, q;
  cin >> n >> q;

  vll v(n);
  for (ll i = 0; i < n; i++) {
    cin >> v[i];
  }

  ll mk = v[0];
  vll ans(n), pre(n);
  pre[0] = v[0];
  ans[0] = v[0];
  for (ll i = 1; i < n; i++) {
    pre[i] = v[i] + pre[i - 1];
  }

  for (ll i = 1; i < n; i++) {
    ans[i] = max(v[i], ans[i - 1]);
  }
  for (ll i = 0; i < q; i++) {
    ll qi;
    cin >> qi;

    ll k = upper_bound(ans.begin(), ans.end(), qi) - ans.begin() - 1;
    if (k < 0) {
      cout << "0 ";
      continue;
    }
    cout << pre[k] << ' ';
    cerr << k << ' ';
  }
  cerr << '\n';
  cout << '\n';
  // cerr << pre;
  // cerr << ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--)
    solve();
}
