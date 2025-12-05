#include <bits/stdc++.h>

using namespace std;

int main() {
  int ans = 0;

  int pos = 50;
  // 4629
  for (int i = 0; i < 4629; i++) {
    char c;
    cin >> c;

    int off;
    cin >> off;

    int k = off;
    if (c == 'L') {
      k = -1 * off;
    }

    pos = (pos + k + 10000) % 100;
    if (pos == 0) {
      ans++;
    }
  }

  cout << ans << '\n';
}
