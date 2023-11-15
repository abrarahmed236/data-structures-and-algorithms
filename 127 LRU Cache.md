# LRU Cache (Problem 146)

list splicing takes O(1) time. We can use this if we remember the list element
iterator in a map.

```cpp
class LRUCache {
    size_t cache_capacity;
    unordered_map<int, list<pair<int, int>>::iterator>
        cache_map;                    // key, list element iterator
    list<pair<int, int>> cache_list;  // key, value
   public:
    LRUCache(int capacity) : cache_capacity(capacity) {}

    int get(int key) {
        auto ret = cache_map.find(key);
        if (ret == cache_map.end()) return -1;
        cache_list.splice(cache_list.begin(), cache_list, ret->second);
        return ret->second->second;
    }

    void put(int key, int value) {
        auto ret = cache_map.find(key);
        if (ret == cache_map.end()) {
            if (cache_list.size() == cache_capacity) {
                cache_map.erase(cache_list.back().first);
                cache_list.pop_back();
            }
            cache_list.push_front({key, value});
            cache_map[key] = cache_list.begin();
        } else {
            cache_list.splice(cache_list.begin(), cache_list, ret->second);
            ret->second->second = value;
        }
    }
};
```
