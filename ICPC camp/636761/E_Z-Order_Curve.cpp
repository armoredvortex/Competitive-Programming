#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
  ll l, r;
  cin >> l >> r;

  while (true) {
    ll x = log2(l);
    ll y = log2(r);

    ll k = max(pow(2, x), pow(2, y));
    if (l - k < 0 || r - k < 0) {
      break;
    } else {
      l -= k;
      r -= k;
    }
  }

  cout << l << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}