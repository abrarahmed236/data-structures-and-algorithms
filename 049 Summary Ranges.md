# Summary Ranges (Problem 228)

Rough implementation

```cpp
class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (!nums.size()) return result;

        int begin = 0;
        int end = begin;

        auto push_back = [&nums, &begin, &end, &result]() {
            if (begin == end-1)
                result.push_back(to_string(nums[begin]));
            else
                result.push_back(to_string(nums[begin]) + "->" +
                                 to_string(nums[end-1]));
        };

        while (++end < nums.size()) {
            if (nums[end - 1] + 1 == nums[end]) continue;
            push_back();
            begin = end;
        }
        push_back();

        return result;
    }
};
```

Cleaner Code, same implementation

```cpp
class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (!nums.size()) return result;

        int begin = 0;

        for (int end = 1; end <= nums.size(); end++) {
            if (end == nums.size() || nums[end - 1] + 1 != nums[end]) {
                result.push_back(to_string(nums[begin]) +
                                 ((begin == end - 1)
                                      ? ""
                                      : "->" + to_string(nums[end - 1])));
                begin = end;
            }
        }

        return result;
    }
};
```
