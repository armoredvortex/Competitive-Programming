// problem-url: https://codeforces.com/problemset/problem/1541/B
// problem: B. Pleasant Pairs
// time limit: 2000 ms

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
  ll n;
  cin >> n;

  vll v(n);
  map<ll, ll> m;
  for (ll i = 0; i < n; i++) {
    cin >> v[i];
    m[v[i]] = i + 1;
  }

  sort(all(v));

  ll ans = 0;
  for (ll i = 0; i < v.size(); i++) {
    for (ll j = i + 1; j < v.size(); j++) {
      ll e1 = v[i];
      ll e2 = v[j];
      if (e1 * e2 >= 2 * n) {
        break;
      }

      if (m[e1] + m[e2] == e1 * e2) {
        ans++;
      }
    }
  }

  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--)
    solve();
}
