class Dsu {
public:
    vector<int> parent;
    vector<int> rank;

    Dsu(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);

        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int father(int i) {
        if(parent[i] == i)
            return i;

        return parent[i] = father(parent[i]);
    }

    void join(int u, int v) {
        int pu = father(u);
        int pv = father(v);

        if(pu == pv) return;

        if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
            rank[pu]++;
        }
        else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(
        vector<int>& source,
        vector<int>& target,
        vector<vector<int>>& allowedSwaps
    ) {
        int n = source.size();

        Dsu dsu(n);

        for(auto &it : allowedSwaps) {
            dsu.join(it[0], it[1]);
        }

        unordered_map<int, vector<int>> hash;

        for(int i = 0; i < n; i++) {
            hash[target[i]].push_back(i);
        }

        vector<bool> used(n, false);

        int ans = 0;

        for(int i = 0; i < n; i++) {

            int p1 = dsu.father(i);
            int el = source[i];

            bool found = false;

            if(hash.find(el) != hash.end()) {

                for(int pos : hash[el]) {

                    if(used[pos])
                        continue;

                    int p2 = dsu.father(pos);

                    if(p1 == p2) {
                        used[pos] = true;
                        found = true;
                        break;
                    }
                }
            }

            if(!found)
                ans++;
        }

        return ans;
    }
};