# Symmetric Tree (Problem 101)

Check if left subtree is mirror of right subtree.

```cpp
class Solution {
    bool isMirror(TreeNode* n1, TreeNode* n2) {
        if (!n1 && !n2) return true;
        if (!n1 || !n2) return false;
        if (n1->val != n2->val) return false;
        return isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left);
    }

   public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
};
```
