# Sum Root to Leaf Numbers (Problem 129)

Straightforward backtracking.

```cpp
class Solution {
    void util(TreeNode* root, int curr, int& sum) {
        curr *= 10;
        curr += root->val;
        if (!root->left && !root->right) {
            sum += curr;
        } else {
            if (root->left) util(root->left, curr, sum);
            if (root->right) util(root->right, curr, sum);
        }
    }

   public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        util(root, 0, sum);
        return sum;
    }
};
```
