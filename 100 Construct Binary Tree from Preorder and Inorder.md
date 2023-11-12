# Construct Binary Tree From Preorder and Inorder Traversal (Problem 105)

Quick and Dirty. Needs improvement.

```cpp
class Solution {
    vector<int> preO, inO;
    int N;
    int find(int val, int l, int r) {
        for (int i = l; i <= r; i++) {
            if (inO[i] == val) return i;
        }
        return -1;
    }
    TreeNode* util(int& pre_i, int in_l, int in_r) {
        if (pre_i == N) return nullptr;
        int val = preO[pre_i++];
        TreeNode* curr = new TreeNode(val);
        int in_i = find(val, in_l, in_r);
        curr->left = in_i == in_l ? nullptr : util(pre_i, in_l, in_i - 1);
        curr->right = in_i == in_r ? nullptr : util(pre_i, in_i + 1, in_r);
        return curr;
    }

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preO = preorder;
        inO = inorder;
        int pre_i = 0;
        N = preorder.size();
        int in_l = 0;
        int in_r = preorder.size() - 1;
        return util(pre_i, in_l, in_r);
    }
};
```
