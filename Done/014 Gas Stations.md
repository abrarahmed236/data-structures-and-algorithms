# [Gas Stations (Problem 134)](https://leetcode.com/problems/gas-station/)

```cpp
class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cycles;
        int length = 0;
        int tank = 0;
        int start = 0;
        int N = gas.size();
        for (cycles = 0; cycles < 2; cycles++) {
            for (int i = 0; i < N; i++) {
                tank += gas[i];
                tank -= cost[i];
                if (tank < 0) {
                    tank = 0;
                    length = 0;
                    start = (i + 1) % N;
                }
                length++;
                if (length > N) return start;
            }
        }
        return -1;
    }
};
```

```cpp
class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int N = gas.size();
        for (int i = 0; i < N; i++) {
            gas[i] -= cost[i];
        }

        int tank = 0;
        int start = 0;
        int length = 0;
        for (int i = 0; i < (2 * N - 1); i++) {
            tank += gas[i % N];
            if (tank < 0) {
                start = i + 1;
                length = 0;
                tank = 0;
            } else {
                length++;
            }
            if (length >= N) return start % N;
        }
        return -1;
    }
};
```