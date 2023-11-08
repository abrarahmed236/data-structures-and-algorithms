# Two Sum (Problem 1)


Straight forward n^2 solution
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[i]+nums[j]==target)
                    return {i, j};
            }
        }
    }
};
```


O(n) solution with unordered_map
```cpp
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]=i;
        }
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << endl;
            if (mp.find(target - nums[i]) != mp.end()) {
                if (mp[target - nums[i]] != i)
                    return {i, mp[target - nums[i]]};
            }
        }
        return {-1, -1}; // dummy value
    }
};
```