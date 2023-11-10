# Average of Levels in Binary Tree (Problem 637)

```cpp
class Solution {
   public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (root == nullptr) return result;
        double sum = 0, count = 0;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while (q.size()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr != nullptr) {
                count++;
                sum += curr->val;
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            } else {
                result.push_back(sum / count);
                sum = 0;
                count = 0;
                if (q.size()) q.push(nullptr);
            }
        }
        return result;
    }
};
```

Alternate Level Order Implementation
```cpp
class Solution {
   public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == nullptr) return {};
        vector<double> result;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size() > 0) {
            const int lvl_len = q.size();
            double sum = 0;

            for (int i = 0; i < lvl_len; i++) {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }
            result.push_back(sum / lvl_len);
        }
        return result;
    }
};
```