# Reverse Nodes in k-Group (Problem 25)

Quick and Dirty using auxiliary vector

```cpp
class Solution {
    void flatten(ListNode* head, vector<ListNode*>& vec) {
        if (!head) return;
        while (head) {
            vec.push_back(head);
            head = head->next;
        }
    }

   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        vector<ListNode*> vec;
        flatten(head, vec);

        // do the thing
        int beg = 0;
        int end = k - 1;
        while (end < vec.size()) {
            for (int i = beg, j = end; i < j; i++, j--) {
                swap(vec[i], vec[j]);
            }
            beg += k;
            end += k;
        }

        // cleanup next pointers
        for (int i = 0; i < vec.size() - 1; i++) {
            vec[i]->next = vec[i + 1];
        }
        vec.back()->next = nullptr;

        return vec[0];
    }
};
```

Can be made better

```cpp
// later
```
