int quickSelect(vector<int> &arr, int lo, int hi, int k) {
  int pivot = arr[hi];
  int i = lo, j = hi - 1;

  while (i <= j) {
    if (arr[i] > pivot) {
      swap(arr[i], arr[j]);
      j--;
    } else {
      i++;
    }
  }
  swap(arr[i], arr[hi]);

  if (i == k) {
    return arr[i];
  } else if (i < k) {
    return quickSelect(arr, i + 1, hi, k);
  } else {
    return quickSelect(arr, lo, i - 1, k);
  }
}

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    k--;
    return quickSelect(nums, 0, nums.size() - 1, nums.size() - k - 1);
  }
};
