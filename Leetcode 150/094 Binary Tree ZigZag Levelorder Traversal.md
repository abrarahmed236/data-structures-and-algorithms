# Binary Tree ZigZag Level Order Traversal

Standard level order traversal with minor edits.

```cpp
class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool forward = true;
        vector<int> curr_lvl;
        curr_lvl.reserve(256);
        while (q.size() > 0) {
            curr_lvl.clear();
            const int lvl_size = q.size();
            for (int i = 0; i < lvl_size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                curr_lvl.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            if (!forward) reverse(curr_lvl.begin(), curr_lvl.end());
            forward = !forward;
            result.push_back(curr_lvl);
        }

        return result;
    }
};
```
