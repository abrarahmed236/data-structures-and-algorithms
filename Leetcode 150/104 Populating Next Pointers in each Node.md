# Populating Next Pointers in each Node (Problem 117)

Classic queue solution

```cpp
class Solution {
   public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        while (q.size() > 0) {
            const int lvl_size = q.size();
            Node* curr;
            for (int i = 0; i < lvl_size; i++) {
                curr = q.front();
                q.pop();
                if (i < lvl_size - 1) curr->next = q.front();

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            curr->next = nullptr;
        }
        return root;
    }
};
```
