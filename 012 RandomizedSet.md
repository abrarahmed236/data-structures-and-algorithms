# [Randomized Set (Problem 380)](https://leetcode.com/problems/insert-delete-getrandom-o1/)

```cpp
class RandomizedSet {
   private:
    unordered_set<int> elements;

   public:
    RandomizedSet() {
        srand(time(NULL));
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    bool insert(int val) { return elements.insert(val).second; }

    bool remove(int val) { return elements.erase(val) > 0; }

    int getRandom() {
        return *next(elements.begin(), rand() % elements.size());
    }
};
```


```cpp
class RandomizedSet {
   private:
    unordered_map<int, int> mapToIndices;
    vector<int> elements;

   public:
    RandomizedSet() {
        srand(time(NULL));
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    bool insert(int val) {
        if (mapToIndices.find(val) != mapToIndices.end()) {
            return false;
        }
        elements.push_back(val);
        mapToIndices[val] = elements.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (mapToIndices.find(val) == mapToIndices.end()) {
            return false;
        }

        // swap in last element to found elements position
        // and update index map
        int index = mapToIndices[val];
        int lastElement = elements.back();
        elements[index] = lastElement;
        mapToIndices[lastElement] = index;

        // remove element
        elements.pop_back();
        mapToIndices.erase(val);
        return true;
    }

    int getRandom() { return elements[rand() % elements.size()]; }
};
```

Beats 100% at the time of submission.