# Contains Duplicate II (Problem 219)

Using unordered_set
```cpp
class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> myset;
        for (int i = 0; i < nums.size(); i++) {
            if (myset.count(nums[i])) return true;
            myset.insert(nums[i]);
            if(i>=k) myset.erase(nums[i-k]);
        }
        return false;
    }
};
```