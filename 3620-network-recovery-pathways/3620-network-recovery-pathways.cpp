class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> g(n);
        vector<int> indeg(n, 0);
        int hi = 0;
        for (auto &e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            indeg[e[1]]++;
            hi = max(hi, e[2]);
        }

        vector<int> topo;
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indeg[i] == 0)
                q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (auto &[v, w] : g[u]) {
                if (--indeg[v] == 0)
                    q.push(v);
            }
        }

        auto check = [&](int lim) {
            const long long INF = (1LL << 60);
            vector<long long> dp(n, INF);
            dp[0] = 0;
            for (int u : topo) {
                if (dp[u] == INF) continue;
                if (u != 0 && u != n - 1 && !online[u]) continue;
                for (auto &[v, w] : g[u]) {
                    if (w < lim) continue;
                    if (v != n - 1 && !online[v]) continue;
                    if (dp[u] + w < dp[v] && dp[u] + w <= k)
                        dp[v] = dp[u] + w;
                }
            }
            return dp[n - 1] != INF;
        };

        int lo = 0, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};