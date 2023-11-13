# Validate Binary Search Tree (Problem 98)

Flatten the BST onto an array, to quickly test sortedness.

```cpp
class Solution {
    vector<int> flat;
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->left);
        flat.push_back(root->val);
        flatten(root->right);
    }

   public:
    bool isValidBST(TreeNode* root) {
        flatten(root);
        for (int i = 1; i < flat.size(); i++)
            if (flat[i - 1] >= flat[i]) return false;
        return true;
    }
};
```

Remember previously seen element in Inorder Traversal
```cpp
class Solution {
    TreeNode* prev = nullptr;

   public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        bool valid = isValidBST(root->left);
        if (valid && prev) {
            if (prev->val >= root->val) return false;
        }
        prev = root;
        return valid && isValidBST(root->right);
    }
};
```

Alternate way to remember previously seen node
```cpp
class Solution {
    bool isValid(TreeNode* root, TreeNode*& prev) {
        if (!root) return true;
        bool valid = isValid(root->left, prev);
        if (valid && prev) {
            if (prev->val >= root->val) return false;
        }
        prev = root;
        return valid && isValid(root->right, prev);
    }

   public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return isValid(root, prev);
    }
};
```