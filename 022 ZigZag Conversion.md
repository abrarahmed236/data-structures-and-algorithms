# [ZigZag Conversion (Problem 6)](https://leetcode.com/problems/zigzag-conversion/)


Simulate
```cpp
class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> matrix(numRows, string(s.size(), ' '));
        enum Dir { DOWN, UP };
        int i = 0, N = s.size();
        int r = numRows, c = r * 2 - 1;
        int X = 0, Y = 0;
        Dir dir = DOWN;
        while (i < N) {
            matrix[X][Y] = s[i];
            if (dir == DOWN) {
                X++;
            } else {
                X--;
                Y++;
            }

            i++;
            if (X == numRows - 1 && dir == DOWN) {
                dir = UP;
            } else if (X == 0 && dir == UP) {
                dir = DOWN;
            }
        }
        string result;
        for (int j = 0; j < numRows; j++) {
            for (int i = 0; i < s.size(); i++) {
                if (matrix[j][i] != ' ') result.push_back(matrix[j][i]);
            }
        }
        return result;
    }
};
```

```cpp
class Solution {
   public:
    string convert(string s, int numRows) {
        vector<string> ss(numRows, "");
        int N = s.size();
        if (numRows == 1) return s;
        if (N > 0) ss[0].push_back(s[0]);
        int n = 1;
        while (n < N) {
            for (int i = 1; i < numRows && n < N; i++, n++)
                ss[i].push_back(s[n]);
            for (int i = numRows - 2; i >= 0 && n < N; i--, n++)
                ss[i].push_back(s[n]);
        }
        string result;
        for (int i = 0; i < numRows; i++) result += ss[i];
        return result;
    }
};
```