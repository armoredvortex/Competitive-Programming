class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr.back() - arr.size() < k){
            int miss = arr.back() - arr.size()-1;
            return k - miss + arr.back()-1;
        }

        int left = 0, right = arr.back();
        int mid;
        while(left < right){
            mid = left + (right - left)/2;

            auto e = upper_bound(arr.begin(), arr.end(), mid) - arr.begin();

            auto j = mid - e;
            if(j==k){
                while(binary_search(arr.begin(), arr.end(), mid)){
                    mid--;
                }
                return mid;
            } else if(j > k){
                right = mid;
            } else {
                left = mid+1;
            }

        }

        return -1;
    }
};