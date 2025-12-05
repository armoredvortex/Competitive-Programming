#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<int> get_digs(int x) {
  vector<int> res;
  while (x) {
    res.push_back(x % 10);
    x /= 10;
  }
  return res;
}

int main() {
  long long ans = 0;
  for (int i = 0; i < 36; i++) {
    long long a, b;
    cin >> a >> b;
    for (long long j = a; j <= b; j++) {
      string k = to_string(j);

      for (int l = 1; l <= k.size()/2; l++) {
        if (k.size() % l != 0) {
          continue;
        }

        int flag = 1;
        string s1 = k.substr(0, l);
        for (int kkk = 0; kkk < k.size(); kkk += l) {
          // cout << kkk << '-' << l << '\n';
          string si = k.substr(kkk, l);
          if (s1 != si) {
            flag = 0;
          }
        }
        if (flag) {
          ans += j;
          break;
        }
      }
    }
  }

  cout << ans;
}
