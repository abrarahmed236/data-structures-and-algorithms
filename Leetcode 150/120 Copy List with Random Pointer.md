# Copy List with Random Pointer (Problem 138)

Create a new node for each node in the original list and store the address in a
map.  
Iterate over the original list again and use the map to populate the copy
correctly.

```cpp
class Solution {
   public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* ptr_1 = head;
        Node* ptr_2 = nullptr;
        while (ptr_1) {
            ptr_2 = new Node(head->val);
            mp[ptr_1] = ptr_2;
            ptr_1 = ptr_1->next;
        }
        mp[nullptr] = nullptr;
        ptr_1 = head;
        while (ptr_1) {
            Node* ptr_2 = mp[ptr_1];
            ptr_2->next = mp[ptr_1->next];
            ptr_2->random = mp[ptr_1->random];
            ptr_1 = ptr_1->next;
        }

        return mp[head];
    }
};
```
