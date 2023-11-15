# Binary Tree Maximum Path Sum (Problem 124)

Rough Solution needs cleanup

```cpp
#define watch(x) \
    if (debug) cout << (#x) << ": " << (x) << endl
#define mark(x) \
    if (debug) cout << x << endl

class Solution {
    const static bool debug = false;
    const static int min_val = -1 * 300000;
    int max_(vector<int> V) { return *max_element(V.begin(), V.end()); }
    int maxPath(TreeNode* root) {
        if (!root) return min_val;
        if (!root->left && !root->right) return root->val;
        int left = min_val;
        int right = min_val;
        if (root->left) left = root->val + maxPath(root->left);
        if (root->right) right = root->val + maxPath(root->right);
        mark("\nmaxPath");
        watch(root->val);
        watch(left);
        watch(right);
        int result = max(root->val, max(left, right));
        watch(result);
        mark("");
        return result;
    }
    int maxPathSum_(TreeNode* root) {
        if (!root) return min_val;
        int left_path = maxPath(root->left);
        int right_path = maxPath(root->right);
        int max_left = maxPathSum_(root->left);
        int max_right = maxPathSum_(root->right);
        mark("\nmaxPathSum");
        watch(root->val);
        watch(left_path);
        watch(right_path);
        watch(max_left);
        watch(max_right);
        int result =
            max_({root->val, root->val + left_path, root->val + right_path,
                  root->val + left_path + right_path, max_left, max_right});
        watch(result);
        mark("");
        return result;
    }

   public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        return maxPathSum_(root);
    }
};
```

Improved complexity with tabulation.

```cpp
class Solution {
    const static int min_val = -1 * 300000;
    unordered_map<TreeNode*, int> pathDP;
    unordered_map<TreeNode*, int> pathSumDP;
    int max_(vector<int> V) { return *max_element(V.begin(), V.end()); }
    int maxPath(TreeNode* root) {
        if (pathDP.count(root)) return pathDP[root];
        if (!root->left && !root->right) return root->val;
        int left = min_val;
        int right = min_val;
        if (root->left) left = root->val + maxPath(root->left);
        if (root->right) right = root->val + maxPath(root->right);
        int result = max(root->val, max(left, right));
        return pathDP[root] = result;
    }
    int maxPathSum_(TreeNode* root) {
        if (pathSumDP.count(root)) return pathSumDP[root];
        int left_path = maxPath(root->left);
        int right_path = maxPath(root->right);
        int max_left = maxPathSum_(root->left);
        int max_right = maxPathSum_(root->right);
        int result =
            max_({root->val, root->val + left_path, root->val + right_path,
                  root->val + left_path + right_path, max_left, max_right});
        return pathSumDP[root] = result;
        ;
    }

   public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        pathDP[nullptr] = min_val;
        pathSumDP[nullptr] = min_val;
        return maxPathSum_(root);
    }
};
```

Can be improved a lot more. But need time.