# Binary Tree right side View (Problem 199)

Solution required level order traversal and remembering the previous element
traversed. One implementation uses the queue.

```cpp
class Solution {
   public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int prev;
        while (q.size()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                prev = node->val;

            } else {
                result.push_back(prev);
                if (q.size()) q.push(nullptr);
            }
        }
        return result;
    }
};
```

Another way is to traverse the tree recursively and to save the right most
element on each level.

```cpp
class Solution {
    void solver(TreeNode* root, vector<int>& result, int level) {
        if (!root) return;
        if (result.size() == level) result.push_back(root->val);
        solver(root->right, result, level + 1);
        solver(root->left, result, level + 1);
    }

   public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        solver(root, result, 0);
        return result;
    }
};
```
