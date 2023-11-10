# Convert Sorted Array to BST (Problem 108)

As good as it gets for this problem

```cpp
class Solution {
    TreeNode* get_bst(vector<int>& nums, int beg, int end) {
        if (beg > end) return nullptr;
        int mid = (beg + end) / 2;
        TreeNode* result = new TreeNode(nums[mid]);
        result->left = get_bst(nums, beg, mid - 1);
        result->right = get_bst(nums, mid + 1, end);
        return result;
    }

   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return get_bst(nums, 0, nums.size() - 1);
    }
};
```
