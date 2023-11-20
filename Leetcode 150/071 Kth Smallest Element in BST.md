# Kth smallest element in BST (Problem 230)

Decent Naive solution
```cpp
class Solution {
   public:
    int get_size(TreeNode* root) {
        if (root == nullptr) return 0;
        return get_size(root->left) + get_size(root->right) + 1;
    }
    int kthSmallest(TreeNode* root, int k) {
        int left_size = get_size(root->left);
        if (left_size == k - 1)
            return root->val;
        else if (left_size > k - 1)
            return kthSmallest(root->left, k);
        else
            return kthSmallest(root->right, k - left_size - 1);
    }
};
```