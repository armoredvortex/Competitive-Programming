// subarray sum equals k

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    vector<int> prefix(nums.size() + 1, 0);

    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      prefix[i + 1] = prefix[i] + nums[i]
    }

    unordered_map<int, int> m;
    m[0]++;
    for (int i = 1; i < prefix.size(); i++) {
      auto e = prefix[i];
      ans += m[e - k];
      m[e]++;
    }

    return ans;
  }
};
