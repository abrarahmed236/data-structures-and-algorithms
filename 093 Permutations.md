# Permutations (Problem 46)

Using recursive backtracking

```cpp
class Solution {
    void util(unordered_set<int>& st, vector<int>& curr, vector<int>& nums,
              vector<vector<int>>& result) {
        if (st.empty()) {
            result.push_back(curr);
        } else {
            for (int n : nums) {
                if (st.count(n)) {
                    curr.push_back(n);
                    st.erase(n);
                    util(st, curr, nums, result);
                    st.insert(n);
                    curr.pop_back();
                }
            }
        }
    }

   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        unordered_set<int> st(nums.begin(), nums.end());
        util(st, curr, nums, result);
        return result;
    }
};
```

Using next_permutation ...  
Recommended method if feasible.

```cpp
class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        do {
            result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        return result;
    }
};
```

Using fancy pants swapping method.

```cpp
// later
```
