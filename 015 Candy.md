# [Candy (Problem 135)]()

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        bool change = true;
        int N = ratings.size();

        vector<int> candies(N, 1);
        while(change) {
            change = false;
            for(int i=0; i<N; i++) {
                if(i && ratings[i] > ratings[i-1] && candies[i] < candies[i-1]+1) {
                    candies[i] = candies[i-1]+1;
                    change = true;
                }
                if(i<N-1 && ratings[i] > ratings[i+1] && candies[i] < candies[i+1]+1) {
                    candies[i] = candies[i+1]+1;
                    change = true;
                }
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
```

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();
        vector<int> candies(N, 1);
        for(int i=1; i<N; i++) {
            if(ratings[i] > ratings[i-1]) {
                candies[i] = max(candies[i], candies[i-1]+1);
            }
        }
        for(int i=N-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
```
