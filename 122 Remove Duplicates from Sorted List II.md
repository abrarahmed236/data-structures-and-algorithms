# Remove Duplicates from Sorted List II (Problem 82)

Iterate through the linked list while remembering the previous node. If you see
a repeated node, skip it and all duplicates.

```cpp
class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;

        ListNode* prev = nullptr;
        ListNode* ptr = head;
        while (ptr) {
            if (ptr->next && ptr->val == ptr->next->val) {
                ListNode* next = ptr->next;
                while (next && ptr->val == next->val) {
                    next = next->next;
                }
                if (prev) {
                    prev->next = next;
                } else {
                    head = next;
                }
                ptr = next;
            } else {
                prev = ptr;
                ptr = ptr->next;
            }
        }

        return head;
    }
};
```
