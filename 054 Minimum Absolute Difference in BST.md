# Minimum Absolute Difference in BST (Problem 530)

O(N) solution using tree traversal and returning an info struct
```cpp
class Solution {
    typedef struct info {
        int max, min, diff;
    } info;
    info get_info(TreeNode *root) {
        if (!root) return {-200000, 200000, INT_MAX};
        info left_info = get_info(root->left);
        info right_info = get_info(root->right);
        int new_max = max(root->val, right_info.max);
        int new_min = min(root->val, left_info.min);
        int new_diff =
            min(root->val - left_info.max, right_info.min - root->val);
        int old_diff = min(left_info.diff, right_info.diff);
        return {new_max, new_min, min(new_diff, old_diff)};
    }

   public:
    int getMinimumDifference(TreeNode *root) {
        if (!root) return 0;
        return get_info(root).diff;
    }
};
```

Recursive inorder traversal while remembering the previously seen element
```cpp
class Solution {
    int min_dif = INT_MAX, val = -1;

   public:
    int getMinimumDifference(TreeNode* root) {
        if (root->left != NULL) getMinimumDifference(root->left);
        if (val >= 0) min_dif = min(min_dif, root->val - val);
        val = root->val;
        if (root->right != NULL) getMinimumDifference(root->right);
        return min_dif;
    }
};
```

Inorder traversal but with separate traveral function to speed things up 
```cpp
class Solution {
    TreeNode* prev;
    int min_dif = INT_MAX;
    void InorderTraversal(TreeNode* root) {
        if (!root) return;
        InorderTraversal(root->left);
        if (prev != nullptr) min_dif = min(min_dif, root->val - prev->val);
        prev = root;
        InorderTraversal(root->right);
    }

   public:
    int getMinimumDifference(TreeNode* root) {
        prev = nullptr;
        InorderTraversal(root);
        return min_dif;
    }
};
```

Find minDiff for each node
```cpp
class Solution {
    int find_max(TreeNode* root) {
        if (root == nullptr) return INT_MIN;
        while (root->right) root = root->right;
        return root->val;
    }
    int find_min(TreeNode* root) {
        if (root == nullptr) return INT_MAX;
        while (root->left) root = root->left;
        return root->val;
    }
    int getMinDiff(TreeNode* root) {
        if (root == nullptr) return INT_MAX;
        int min_dif = INT_MAX;

        if (root->left)
            min_dif = min(min_dif, root->val - find_max(root->left));
        if (root->right)
            min_dif = min(min_dif, find_min(root->right) - root->val);
        min_dif = min(min_dif, getMinDiff(root->left));
        min_dif = min(min_dif, getMinDiff(root->right));

        return min_dif;
    }

   public:
    int getMinimumDifference(TreeNode* root) { return getMinDiff(root); }
};
```