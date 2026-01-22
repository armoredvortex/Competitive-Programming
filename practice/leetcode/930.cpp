class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> prefix(nums.size() + 1);
        prefix[0] = 0;
        for(int i=0; i<nums.size(); i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int ans = 0;
        for(int left=0; left< nums.size(); left++){
            int e = prefix[left];
            int req = goal + e;
            cout << e << ' ' << req << '\n';
            auto it1 = lower_bound(prefix.begin()+left+1, prefix.end(), req);
            auto it2 = upper_bound(prefix.begin()+left+1, prefix.end(), req);

            ans += it2 - it1;
        }

        return ans;
    }
};

//  1 0 1 0 1
// 0 1 1 2 2 3