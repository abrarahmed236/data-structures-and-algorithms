# Rotate List (Problem 61)

Traverse to the tail.  
Point tail->next to head. Making the list circular.  
Push both forward N - k times.  
Now, head points to desired head, tail points to desired tail.  
Point tail to nullptr breaking the circular linked list.  
Return head.

```cpp
class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !k) return head;

        int N = 1;
        ListNode* ptr = head;
        while (ptr->next) {
            ptr = ptr->next;
            N++;
        }
        ptr->next = head;

        k = k % N;
        int pos = N - k;
        while (pos--) {
            head = head->next;
            ptr = ptr->next;
        }
        ptr->next = nullptr;

        return head;
    }
};
```
