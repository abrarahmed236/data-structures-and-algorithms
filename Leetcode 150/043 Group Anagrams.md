# Group Anagrams (Problem 49)

Relatively straightforward solution.
```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        vector<vector<string>> result;
        int curr_ind = 0;
        for(string& str: strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            if(mp.find(temp)==mp.end()) {
                mp[temp] = curr_ind++;
                result.push_back({str});
            }
            else result[mp[temp]].push_back(str);
        } 
        return result;
        
    }
};
```

Same method but with a simple hash function added instead of sorting the string
```cpp
class Solution {
    const static int MOD = 1e9 + 7;
    int hashvals[26] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                        43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    long long hashfunc(const string& s) {
        long long ret = 1;
        for (const char& c : s) {
            ret = (ret * hashvals[c - 'a']) % MOD;
        }
        return ret;
    }

   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long long, int> mp;
        vector<vector<string>> result;
        int curr_ind = 0;
        for (string& str : strs) {
            long long rt = hashfunc(str);
            if (mp.find(rt) == mp.end()) {
                mp[rt] = curr_ind++;
                result.push_back({str});
            } else
                result[mp[rt]].push_back(str);
        }
        return result;
    }
};
```