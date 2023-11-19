# Flatten Binary Tree to Linked List (Problem 114)

Use an auxilliary vector to remember the order of elements visited in pre-order
traversal.

```cpp
class Solution {
    void get_flat(TreeNode* root, vector<TreeNode*>& result) {
        if (!root) return;
        result.push_back(root);
        get_flat(root->left, result);
        get_flat(root->right, result);
    }

   public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> flat_vec;
        get_flat(root, flat_vec);
        flat_vec.push_back(nullptr);
        for (int i = 0; i < flat_vec.size() - 1; i++) {
            flat_vec[i]->left = nullptr;
            flat_vec[i]->right = flat_vec[i + 1];
        }
    }
};
```

Just remember the previously seen element.  
Note: we need to remember the left and right elements for parent node because we
will be overwriting them through the children.

```cpp
class Solution {
    void get_flat(TreeNode* root, TreeNode*& prev) {
        if (!root) return;
        if (prev) {
            prev->left = nullptr;
            prev->right = root;
        }
        prev = root;
        TreeNode *left = root->left, *right = root->right;
        get_flat(left, prev);
        get_flat(right, prev);
    }

   public:
    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        get_flat(root, prev);
    }
};
```
