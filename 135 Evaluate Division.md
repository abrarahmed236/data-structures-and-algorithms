# Evaluate Division (Problem 399)

Rough NaN based DP. Needs fix `//later`

```cpp
#define watch(x) \
    if (debug) cout << (#x) << ": " << (x) << endl
#define pair(i, j) \
    if (debug) cout << i << "," << j << endl

class Solution {
    static const bool debug = false;

    double nan0 = std::nan("0");
    double nan1 = std::nan("1");
    uint64_t get_nan(double a) {
        uint64_t result;
        memcpy(&result, &a, sizeof a);
        return result;
    }
    bool isnaneq(double a, double b) {
        return isnan(a) && isnan(b) && (get_nan(a) == get_nan(b));
    }
    void DFS(vector<vector<double>>& DP, int i, int j) {
        watch(DP[i][j]);
        pair(i, j);
        if (!isnan(DP[i][j]) || isnaneq(DP[i][j], nan1)) return;
        watch(isnaneq(DP[i][j], nan1));
        DP[i][j] = nan1;
        for (int x = 0; x < DP.size() && isnan(DP[i][j]); x++) {
            watch(x);
            if (x == i || x == j) continue;
            if (isnan(DP[i][x])) {
                DFS(DP, i, x);
            }
            if (isnan(DP[x][j])) {
                DFS(DP, x, j);
            }
            if (!isnan(DP[i][x]) && !isnan(DP[x][j])) {
                DP[i][j] = DP[i][x] * DP[x][j];
                return;
            }
        }
    }

   public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int N = equations.size();

        // Assign idx for each unique variable name
        unordered_map<string, int> idx_mp;
        int idx = 0;
        for (auto& equation : equations) {
            string q1 = equation[0];
            string q2 = equation[1];
            if (!idx_mp.count(q1)) idx_mp[q1] = idx++;
            if (!idx_mp.count(q2)) idx_mp[q2] = idx++;
        }

        // create DP with size=num(unique variables)
        vector<vector<double>> DP(idx, vector<double>(idx, nan0));
        for (int i = 0; i < idx; i++) {
            DP[i][i] = 1;
        }

        // populate DP with given values
        for (int i = 0; i < N; i++) {
            string q1 = equations[i][0];
            string q2 = equations[i][1];
            double val = values[i];
            DP[idx_mp[q1]][idx_mp[q2]] = val;
            DP[idx_mp[q2]][idx_mp[q1]] = (double)1 / val;
        }

        // Fully populate DP
        for (int i = 0; i < idx; i++) {
            for (int j = i + 1; j < idx; j++) {
                if (isnaneq(DP[i][j], nan0)) DFS(DP, i, j);
            }
        }

        // Answer each query
        vector<double> result;
        for (auto& q : queries) {
            string q1 = q[0];
            string q2 = q[1];
            if (!idx_mp.count(q1) || !idx_mp.count(q2))
                result.push_back(-1.0);
            else {
                double res = DP[idx_mp[q1]][idx_mp[q2]];
                result.push_back(isnan(res) ? -1 : res);
            }
        }
        return result;
    }
};
```

Good reference solution below. `//later`

```cpp
class Solution {
   public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        vector<double> results;
        for (const auto& query : queries) {
            if (graph.find(query[1]) == graph.end()) {
                results.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                results.push_back(dfs(query[0], query[1], visited));
            }
        }
        return results;
    }

   private:
    unordered_map<string, unordered_map<string, double>> graph;
    double dfs(const string& current, const string& target,
               unordered_set<string>& visited) {
        if (graph.find(current) == graph.end() || visited.count(current))
            return -1.0;
        if (current == target) return 1.0;
        visited.insert(current);

        for (const auto& neighbor : graph.at(current)) {
            double result = dfs(neighbor.first, target, visited);
            if (result != -1.0) return neighbor.second * result;
        }
        return -1.0;
    }
};
```
