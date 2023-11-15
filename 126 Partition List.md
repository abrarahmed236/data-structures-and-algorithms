# Partition List (Problem 86)

Create Two Lists one for left partition, one for right partition.  
Move nodes into the correct lists and then join them up.  
Return the head of the joined list.

```cpp
class Solution {
   public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;
        ListNode dummy1, dummy2;
        ListNode *tail1 = &dummy1, *tail2 = &dummy2;
        ListNode* ptr = head;
        while (ptr) {
            if (ptr->val < x) {
                tail1->next = ptr;
                tail1 = tail1->next;
            } else {
                tail2->next = ptr;
                tail2 = tail2->next;
            }
            ptr = ptr->next;
        }
        tail1->next = tail2->next = nullptr;
        if (dummy1.next) tail1->next = dummy2.next;
        return dummy1.next ? dummy1.next : dummy2.next;
    }
};
```
