# Set Matrix Zeroes (Problem 73)

Intuitive solution

```cpp
class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i_max = matrix.size();
        int j_max = matrix[0].size();

        vector<int> i_zeroes(i_max, 0);
        vector<int> j_zeroes(j_max, 0);

        for (int i = 0; i < i_max; i++) {
            for (int j = 0; j < j_max; j++) {
                if (!matrix[i][j]) {
                    i_zeroes[i] = 1;
                    j_zeroes[j] = 1;
                }
            }
        }

        for (int i = 0; i < i_max; i++) {
            for (int j = 0; j < j_max; j++) {
                if (i_zeroes[i] || j_zeroes[j]) matrix[i][j] = 0;
            }
        }
    }
};
```

Can you do this in constant space ?
