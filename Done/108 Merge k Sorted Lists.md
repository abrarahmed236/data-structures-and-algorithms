# Merge K Sorted Lists (Problem 23)

Using the method to merge two linked lists.  
Merge lists in the vector, two at a time.  
Iterate until you have only one list left.  
Return that one list;

```cpp
class Solution {
   public:
    ListNode* merge2(ListNode* l1, ListNode* l2) {
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
    ListNode* mergeKLists(vector<ListNode*>& lists_) {
        vector<ListNode*> lists = lists_;
        while (lists.size() > 1) {
            vector<ListNode*> temp;
            int begin = 0, end = lists.size() - 1;
            while (begin < end) {
                temp.push_back(merge2(lists[begin], lists[end]));
                begin++;
                end--;
            }
            if (begin == end) temp.push_back(lists[begin]);
            swap(lists, temp);
            temp.clear();
        }
        return lists.empty() ? nullptr : lists[0];
    }
};
```

Simpler method but performs significantly worse. Will analyze later

```cpp
class Solution {
   public:
    ListNode* merge2(ListNode* l1, ListNode* l2) {
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        for (auto list : lists) {
            head = merge2(head, list);
        }
        return head;
    }
};
```
