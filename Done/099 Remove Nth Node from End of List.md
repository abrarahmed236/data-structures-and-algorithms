# Remove Nth Node from End of List (Problem 19)

Quick and dirty
```cpp
class Solution {
    static const int debug = false;

   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // get size
        int N = 0;
        ListNode* ptr = head;
        while (ptr) {
            ptr = ptr->next;
            N++;
        }

        int target = N - n + 1;
        if (N == 1 || target == 1) return head->next;
        if (debug) cout << "size: " << N << " pos: " << n << endl;

        ptr = head;
        for (int i = 2; i < target; i++) {
            ptr = ptr->next;
            if (debug) cout << "ptr: " << ptr->val << " ";
        }
        if (debug) cout << endl;

        ptr->next = ptr->next->next;
        return head;
    }
};
```