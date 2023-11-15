# Reverse Linked List II (Problem 92)

Use normal way of reversing a linked list. But do it for the elements specified.  
This method works with 100% score but need a lot of cleanup `//later`
```cpp
#define watch(x) \
    if (debug) cout << (#x) << ": " << ptrstr(x) << endl
#define space \
    if (debug) cout << endl

string ptrstr(ListNode* ptr) { return (ptr ? to_string(ptr->val) : "nullptr"); }

class Solution {
    const static bool debug = false;

   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = nullptr;
        ListNode *ptr, *left_prev, *left_head, *tail;
        int index = 1;
        ptr = head;
        while (ptr) {
            if (index == left) {
                left_prev = prev;
                left_head = ptr;
                watch(left_prev);
                watch(left_head);
            }
            if (index == right) {
                tail = ptr;
                watch(tail);
            }
            prev = ptr;
            index++;
            ptr = ptr->next;
        }
        ListNode* tail_next = tail->next;
        prev = tail_next;
        ptr = left_head;
        space;
        while (ptr != tail_next) {
            watch(ptr);
            ListNode* next = ptr->next;
            watch(next);
            ptr->next = prev;
            watch(ptr->next);
            prev = ptr;
            watch(prev);
            ptr = next;
            watch(ptr);

            space;
        }
        space;
        if (left_prev) left_prev->next = prev;
        watch(left_prev);
        return left == 1 ? prev : head;
    }
};
```