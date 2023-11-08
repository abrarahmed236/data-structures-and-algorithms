# Spiral Matrix (Problem 54)

```cpp
class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& M) {
        int left = 0, right = M[0].size() - 1;
        int up = 0, down = M.size() - 1;
        auto cond = [&left, &right, &up, &down]() {
            return (left <= right && up <= down);
        };

        vector<int> result;
        while (cond()) {
            for (int i = left; i <= right; i++) result.push_back(M[up][i]);
            up++;
            if (!cond()) break;
            for (int i = up; i <= down; i++) result.push_back(M[i][right]);
            right--;
            if (!cond()) break;
            for (int i = right; i >= left; i--) result.push_back(M[down][i]);
            down--;
            if (!cond()) break;
            for (int i = down; i >= up; i--) result.push_back(M[i][left]);
            left++;
            if (!cond()) break;
        }

        return result;
    }
};
```