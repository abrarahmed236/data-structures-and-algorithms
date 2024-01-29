#include <bits/stdc++.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Node {
   public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

class LFUCache {
    int min_freq = INT_MAX;
    int capacity;

    // Information associated with each key
    struct Info {
        int value;                // Value corresponding to the key
        int freq;                 // Frequency corresponding to the key
        list<int>::iterator pos;  // Position in freq_map[info.freq] list
    };

    unordered_map<int, Info> store;          // Key -> {value, freq, pos}
    unordered_map<int, list<int>> freq_map;  // Frequency -> List of keys

   public:
    LFUCache(int capacity) : capacity(capacity) {}

    // Get the value of the key from the cache
    int get(int key) {
        // If the key is not present
        if (store.find(key) == store.end())
            return -1;

        // Remove the old frequency map entry
        freq_map[store[key].freq].erase(store[key].pos);

        // Update the frequency in the store
        store[key].freq++;

        // Insert a new frequency entry
        freq_map[store[key].freq].push_back(key);

        // Remember the position of the key in the frequency sublist
        store[key].pos = --freq_map[store[key].freq].end();

        // Increment min_freq when no elements in the list
        while (freq_map[min_freq].size() == 0) min_freq++;

        return store[key].value;
    }

    // Put a new key-value pair in the cache
    void put(int key, int value) {
        if (capacity <= 0)
            return;

        // If key already exists, update the frequency and position, and update
        // the value
        if (store.find(key) != store.end() && get(key) != -1) {
            store[key].value = value;
            return;
        }

        // If the cache is full, remove the oldest key
        if (store.size() >= capacity) {
            // Get the oldest key in the list corresponding to the least
            // frequent keys
            int oldest_key = freq_map[min_freq].front();
            freq_map[min_freq].pop_front();

            // Erase entry in the store
            store.erase(oldest_key);
        }

        // New entry has a frequency of 1
        freq_map[1].push_back(key);

        // Add a new entry to the store
        store[key] = {value, 1, --freq_map[1].end()};

        // Every time we put an unseen value, min_freq is set to 1
        min_freq = 1;
    }
};
