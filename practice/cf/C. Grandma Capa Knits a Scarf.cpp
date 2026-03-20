// problem-url: https://codeforces.com/problemset/problem/1582/C
// problem: C. Grandma Capa Knits a Scarf
// time limit: 1000 ms

#include <bits/stdc++.h>
#include <climits>
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

  string s;
  cin >> s;

  ll ans = LONG_LONG_MAX;
  for (ll i = 0; i < 26; i++) {
    char c = 'a' + i;
    ll sub = 0;
    ll left = 0, right = n - 1;
    while (left < right) {
      // cerr << left << ':' << right << '\n';
      // cerr << s[left] << ':' << s[right] << ':' << c << '\n';
      if (s[left] == s[right]) {
        left++;
        right--;
      } else {
        if (s[left] != c && s[right] != c) {
          sub = LONG_LONG_MAX;
          break;
        }
        if (s[left] == c) {
          while (s[left] == c && left < right) {
            left++;
            sub++;
          }
        }
        if (s[right] == c) {
          while (s[right] == c && left < right) {
            right--;
            sub++;
          }
        }
      }
    }
    ans = min(ans, sub);
  }

  if (ans == LONG_LONG_MAX) {
    cout << -1 << '\n';
    return;
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
