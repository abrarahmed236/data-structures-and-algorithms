# Binary Search Tree Iterator (Problem 173)

Use a vector to store the inorder traversal

```cpp
class BSTIterator {
    vector<int> vec;
    int next_ind;
    void get_flat(TreeNode* root, vector<int>& vec) {
        if (!root) return;
        get_flat(root->left, vec);
        vec.push_back(root->val);
        get_flat(root->right, vec);
    }

   public:
    BSTIterator(TreeNode* root) {
        vec.reserve(1024);
        get_flat(root, vec);
        next_ind = 0;
    }

    int next() { return vec[next_ind++]; }

    bool hasNext() { return next_ind < vec.size(); }
};

```

Can do better on the space complexity.

```cpp
// later
```
