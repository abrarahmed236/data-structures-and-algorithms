# Container with most water (Problem 11)

Simple two pointer solution.

```cpp
class Solution {
   public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int water;
        int result = 0;

        while (i < j) {
            if (height[i] < height[j]) {
                water = height[i] * (j - i);
                i++;
            } else {
                water = height[j] * (j - i);
                j--;
            }
            if (water > result) result = water;
        }

        return result;
    }
};
```
