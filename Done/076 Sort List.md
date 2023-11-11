# Sort List (Problem 148)

Copy over the contents of the list into a vector / array and sort the array.
Copy over the contents of the array into the list.  
Quick and dirty solution.

```cpp
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> vec;
        ListNode* pCrawl = head;
        while(pCrawl != nullptr) {
            vec.push_back(pCrawl->val);
            pCrawl = pCrawl->next;
        }
        sort(vec.begin(), vec.end());
        pCrawl = head;
        for(auto n: vec) {
            pCrawl->val = n;
            pCrawl = pCrawl->next;
        }
        return head;
    }
};
```

Standard Linked List Merge Sort Implementation

```cpp
class Solution {
   public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = slow->next;
        slow->next = nullptr;

        head = sortList(head);
        head2 = sortList(head2);

        return merge(head, head2);
    }

   private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }
};
```
