class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    long long left = 1;
    long long right = LONG_LONG_MAX;
    long long mid;
    while (left < right) {
      mid = left + (right - left) / 2;

      long long hrs = 0;
      for (auto e : piles) {
        hrs += ceil((1.0 * e) / mid);
      }

      if (hrs > h) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};
