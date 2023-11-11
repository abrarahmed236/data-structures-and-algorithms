# Combinations (Problem 77)

> Note: Combinations are unordered. [1,2] is same as [2, 1].

Straightforward Backtracking for combinations

```cpp
class Solution {
    void select(int k, int N, vector<int>& curr, vector<vector<int>>& result) {
        if (curr.size() == k) {
            result.push_back(curr);
            return;
        }
        if (N == 0) return;
        curr.push_back(N);
        select(k, N - 1, curr, result);
        curr.pop_back();
        select(k, N - 1, curr, result);
    }

   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> curr;
        select(k, n, curr, result);
        return result;
    }
};
```

Alternate method for backtracking for combinations

```cpp
class Solution {
    void select(int curr, int k, int N, vector<int>& combo,
                vector<vector<int>>& combos) {
        if (combo.size() == k) {
            combos.push_back(combo);
            return;
        }
        for (int i = curr; i <= N; i++) {
            combo.push_back(i);
            select(i + 1, k, N, combo, combos);
            combo.pop_back();
        }
    }

   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combos;
        vector<int> combo;
        select(1, k, n, combo, combos);
        return combos;
    }
};
```

Fancy pants iterative method for backtracking for combinations

```cpp
class Solution {
   public:
    vector<vector<int>> combine(int N, int K) {
        vector<vector<int>> combos{};
        vector<int> combo(K, 0);

        for (int i = 0; i >= 0; ) {
            combo[i]++;
            if (combo[i] > N)
                --i;
            else if (i == K - 1)
                combos.push_back(combo);
            else {
                ++i;
                combo[i] = combo[i - 1];
            }
        }
        return combos;
    }
};
```
