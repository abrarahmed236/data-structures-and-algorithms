# [Trapping Rain Water (Problem 42)](https://leetcode.com/problems/trapping-rain-water/)

```cpp
class Solution {
   public:
    int trap(vector<int>& height) {
        vector<int> left = height;
        vector<int> right = height;
        for (int i = 1; i < left.size(); i++) {
            left[i] = max(left[i], left[i - 1]);
        }
        for (int i = right.size() - 2; i >= 0; i--) {
            right[i] = max(right[i], right[i + 1]);
        }
        for (int i = 0; i < left.size(); i++) {
            left[i] = min(left[i], right[i]);
        }
        int sum = 0;
        for (int i = 0; i < left.size(); i++) {
            sum += left[i] - height[i];
        }
        return sum;
    }
};
```

```cpp
class Solution {
   public:
    int trap(vector<int>& height) {
        // find global peak index (gpi)
        int gpi = 0;
        int sum = 0;
        int pph = 0;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] > height[gpi]) gpi = i;
        }

        // scan from left towards global peak index
        for (int i = 0; i < gpi; i++) {
            if (height[i] < pph) {
                sum += pph - height[i];
            } else {
                pph = height[i];
            }
        }

        // scan from right towards global peak index
        pph = 0;
        for (int i = height.size() - 1; i > gpi; i--) {
            if (height[i] < pph) {
                sum += pph - height[i];
            } else {
                pph = height[i];
            }
        }

        return sum;
    }
};
```

```cpp
class Solution {
   public:
    int trap(vector<int>& height) {
        int leftMax = INT_MIN;
        int rightMax = INT_MIN;
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {
                leftMax = max(height[left], leftMax);
                ans += leftMax - height[left];
                left++;
            } else {
                rightMax = max(height[right], rightMax);
                ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};
```