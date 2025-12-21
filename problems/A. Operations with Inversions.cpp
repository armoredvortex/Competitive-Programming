// problem-url: https://codeforces.com/contest/2176/problem/A
// problem: A. Operations with Inversions
// time limit: 1000 ms

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
  for (ll i = 0; i < n; i++) {
    cin >> v[i];
  }

  ll pss = v[0];
  ll ct = 1;
  for (ll i = 1; i < n; i++) {
    if (v[i] >= pss) {
      pss = v[i];
      ct++;
    }
  }

  cout << n - ct << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--)
    solve();
}
