# Combination Sum (Problem 39)

Basic Backtracking

```cpp
class Solution {
   public:
    void util(int target, vector<int>& curr_cand, int idx,
              vector<int>& candidates, vector<vector<int>>& result) {
        if (target < 0) return;
        if (target == 0) {
            result.push_back(curr_cand);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            curr_cand.push_back(candidates[i]);
            util(target - candidates[i], curr_cand, i, candidates, result);
            curr_cand.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr_cand;
        util(target, curr_cand, 0, candidates, result);
        return result;
    }
};
```
