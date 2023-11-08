# Rotate Image (Problem 48)

```cpp
class Solution {
   public:
    void rotate(vector<vector<int>>& M) {
        int N = M.size();

        auto lmb = [&M, &N](int i, int j) {
            int temp = M[i][j];
            M[i][j] = M[N - 1 - j][i];
            M[N - 1 - j][i] = M[N - 1 - i][N - 1 - j];
            M[N - 1 - i][N - 1 - j] = M[j][N - 1 - i];
            M[j][N - 1 - i] = temp;
        };

        for (int i = 0; i < N / 2; i++) {
            for (int j = i; j < N - i - 1; j++) {
                lmb(i, j);
            }
        }
    }
};
```