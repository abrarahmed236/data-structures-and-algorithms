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
