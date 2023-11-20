# Lowest Common Ancestor of a Binary Tree (Problem 236)

Recursive Solution. Horribly inefficient.

```cpp
class Solution {
    bool isParent(TreeNode* root, TreeNode* child) {
        if (!root) return false;
        if (root == child) return true;
        return isParent(root->left, child) || isParent(root->right, child);
    }

   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (isParent(root, p) && isParent(root, q)) {
            TreeNode* ret = lowestCommonAncestor(root->left, p, q);
            if (ret) return ret;
            ret = lowestCommonAncestor(root->right, p, q);
            if(ret) return ret;
            return root;
        } else {
            return nullptr;
        }
    }
};
```

We could flatten the array and then use the index of the child nodes in the
array to find the lowest common ancestor. But this would be horribly memory
inefficient.

```cpp
class Solution {
    void flatten(TreeNode* root, vector<TreeNode*>& vec, int ind) {
        while (vec.size() < ind + 1) vec.push_back(nullptr);
        vec[ind] = root;
        if (root->left) flatten(root->left, vec, 2 * ind + 1);
        if (root->right) flatten(root->right, vec, 2 * ind + 2);
    }

   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vec;
        flatten(root, vec, 0);

        int pind = -1, qind = -1;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == p) pind = i;
            if (vec[i] == q) qind = i;
            if (pind != -1 && qind != -1) break;
        }

        while (pind != qind) {
            if (qind > pind)
                qind = (qind - 1) / 2;
            else
                pind = (pind - 1) / 2;
        }
        return vec[pind];
    }
};
```

Traverse the tree while keeping track of whether one of p, q are found. Return
the only node that satisfies the LCA property.

```cpp
class Solution {
    bool traverse(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& result) {
        if (!root) return false;

        bool left = traverse(root->left, p, q, result);
        bool right = traverse(root->right, p, q, result);
        bool mid = root == p || root == q;

        if (left && right || left && mid || right && mid) result = root;

        return left || mid || right;
    }

   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result = nullptr;
        traverse(root, p, q, result);
        return result;
    }
};
```
