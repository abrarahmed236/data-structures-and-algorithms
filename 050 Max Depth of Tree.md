# Max Depth of Tree (Problem 104)

Straight forward solution

```cpp
class Solution {
   public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
```

Can use level order traversal too ...