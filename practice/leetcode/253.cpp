/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
  int minMeetingRooms(vector<Interval> &intervals) {
    multiset<pair<int, int>> m;
    for (auto e : intervals) {
      m.insert({e.start, e.end});
    }

    // for(auto e: m){
    //     cout << e.first << ' ' << e.second << '\n';
    // }

    int ans = 0;

    auto it = m.begin();
    while (!m.empty()) {
      cout << (*it).first << ' ' << (*it).second << ' ' << ans << '\n';

      if (m.lower_bound({(*it).second, 0}) == m.end()) {
        m.erase(it);
        ans++;
        it = m.begin();
      } else {
        auto k = m.lower_bound({(*it).second, 0});
        m.erase(it);
        it = k;
      }
    }

    return ans;
  }
};
