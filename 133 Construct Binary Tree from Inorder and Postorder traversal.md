# Construct Binary Tree from Inorder and Postorder Traversal (Problem 106)

Same as Inorder and Preorder. Just need to change up some things about whether
the left subtree is traversed vs right subtree.

```cpp
class Solution {
    int find(int val, vector<int>& vec, int l, int r) {
        for (int i = l; i <= r; i++) {
            if (vec[i] == val) return i;
        }
        return -1;
    }
    TreeNode* util(vector<int>& inorder, int in_l, int in_r,
                   vector<int>& postorder, int& post_i) {
        if (post_i == -1) return nullptr;
        TreeNode* curr = new TreeNode(postorder[post_i--]);
        int in_i = find(curr->val, inorder, in_l, in_r);
        curr->right = in_i == in_r
                          ? nullptr
                          : util(inorder, in_i + 1, in_r, postorder, post_i);
        curr->left = in_i == in_l
                         ? nullptr
                         : util(inorder, in_l, in_i - 1, postorder, post_i);
        return curr;
    }

   public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int N = inorder.size();
        int post_i = N - 1;
        return util(inorder, 0, N - 1, postorder, post_i);
    }
};
```

Cleaner Implementation

```cpp
class Solution {
   public:
    TreeNode* util(vector<int>& inorder, int in_l, int in_r,
                   vector<int>& postorder, int& post_i,
                   unordered_map<int, int>& mp) {
        if (in_l > in_r || post_i < 0) return nullptr;
        TreeNode* curr = new TreeNode(postorder[post_i--]);
        int in_i = mp[curr->val];
        curr->right = util(inorder, in_i + 1, in_r, postorder, post_i, mp);
        curr->left = util(inorder, in_l, in_i - 1, postorder, post_i, mp);
        return curr;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int N = inorder.size();
        int post_i = N - 1;

        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;

        return util(inorder, 0, N - 1, postorder, post_i, mp);
    }
};
```
