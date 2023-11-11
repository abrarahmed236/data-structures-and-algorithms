# Minimum Genetic Mutation (Problem 433)

Is straightforward.  
But needs cleanup.

```cpp
class Solution {
    static const int debug = false;
    unordered_map<char, string> alt;
    unordered_set<string> visited;
    unordered_set<string> bnk;

    int traverse(int moves, string& startGene,
                 const string& endGene) {
        if (debug) cout << startGene << " " << endGene << endl;
        if (startGene == endGene) return moves;
        visited.insert(startGene);

        int found = INT_MAX;
        for (int i = 0; i < startGene.size(); i++) {
            moves++;
            char letter = startGene[i];
            for (char letter2 : alt[letter]) {
                startGene[i] = letter2;
                if (bnk.find(startGene) != bnk.end() &&
                    visited.find(startGene) == visited.end())
                    found = min(found,
                                traverse(moves, startGene, endGene));
            }
            moves--;
            startGene[i] = letter;
            if (debug) cout << endl;
        }
        return found;
    }

   public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        bnk = unordered_set<string>(bank.begin(), bank.end());
        alt['A'] = "CGT";
        alt['C'] = "AGT";
        alt['G'] = "ACT";
        alt['T'] = "ACG";
        int rt = traverse(0, startGene, endGene);
        return rt == INT_MAX ? -1 : rt;
    }
};
```

Iterative BFS version.

```cpp

class Solution {
   public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st{bank.begin(), bank.end()};
        queue<string> Q;
        Q.push(start);
        int steps = 0;
        string curr;
        while (Q.size() > 0) {
            const int lvl_len = Q.size();
            for (int i = 0; i < lvl_len; i++) {
                curr = Q.front();
                Q.pop();
                if (curr == end) return steps;
                st.erase(curr);
                for (int i = 0; i < 8; i++) {
                    string temp = curr;
                    temp[i] = 'A';
                    if (st.count(temp)) Q.push(temp);
                    temp[i] = 'C';
                    if (st.count(temp)) Q.push(temp);
                    temp[i] = 'G';
                    if (st.count(temp)) Q.push(temp);
                    temp[i] = 'T';
                    if (st.count(temp)) Q.push(temp);
                }
            }
            steps++;
        }
        return -1;
    }
};
```
