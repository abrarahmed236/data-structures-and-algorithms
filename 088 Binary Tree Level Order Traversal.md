# Binary Tree Level Order Traversal (Problem 102)

Level Size Implementation. Highly recommended.

```cpp
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> Q;
        Q.push(root);
        while (Q.size() > 0) {
            const int lvl_size = Q.size();
            vector<int> curr_level;
            for (int i = 0; i < lvl_size; i++) {
                TreeNode* curr = Q.front();
                Q.pop();
                if (curr->left) Q.push(curr->left);
                if (curr->right) Q.push(curr->right);
                curr_level.push_back(curr->val);
            }
            result.push_back(curr_level);
        }
        return result;
    }
};
```

Dummy element implementation. Messy and inflexible for complex problems.

```cpp
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> Q;
        Q.push(root);
        Q.push(nullptr);
        vector<int> curr_lvl;
        while (Q.size() > 0) {
            TreeNode* curr = Q.front();
            Q.pop();

            if (curr != nullptr) {
                curr_lvl.push_back(curr->val);
                if (curr->left) Q.push(curr->left);
                if (curr->right) Q.push(curr->right);
            } else {
                if (Q.size()) Q.push(nullptr);
                result.push_back(curr_lvl);
                curr_lvl.clear();
            }
        }

        return result;
    }
};
```
