��1������DFS/BFS
	���Եõ�������·����ֻ�������޸�Ȩ����
vector<pair<int, int>> g[N];
int n, d[N];

void dfs(int u, int fa, int dist) {
    d[u] = dist;
    for (auto& [v, w]: g[u]) {
        if (v == fa) continue;
        dfs(v, u, dist + w);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, -1, 0);
    int s = 1;
    for (int i = 1; i <= n; i++) {
        if (d[i] > d[s]) s = i;
    }
    dfs(s, -1, 0);
    int t = 1;
    for (int i = 1; i <= n; i++) {
        if (d[i] > d[t]) t = i;
    }
    cout << d[t] << endl;
}
��2������DP
	������������Ȩ�����������ܵõ�����·��
vector<pair<int, int>> g[N];
int n, ans, f[N]; // f[i]:����i������ĳ���
bool st[N];

void dfs(int u) {
    st[u] = true;
    for (auto& [v, w]: g[u]) {
        if (st[v]) continue;
        dfs(v);
        ans = max(ans, f[u] + f[v] + w);
        f[u] = max(f[u], f[v] + w);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1);
    cout << ans << endl;
}
