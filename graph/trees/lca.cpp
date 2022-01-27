const int LG = 20;
 
int t = 1;
vector< vector< pair<int, int> > > g;
vector< vector<int> > up;
vector<int> tin, tout;
 
void dfs(int v, int p) {
    tin[v] = t;
    t++;
    up[0][v] = p;
    for (int i = 1; i <= LG; i++)
        up[i][v] = up[i - 1][up[i - 1][v]];
    for (auto &to : g[v]) {
        if (to.ff == p)
            continue;
        dfs(to.ff, v);
    }
    tout[v] = t;
    t++;
}
 
int isa(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a]; 
}
 
int lca(int a, int b) {
    if (isa(a, b))
        return a;
    if (isa(b, a))
        return b;
    for (int i = LG; i >= 0; i--) {
        if (!isa(up[i][a], b)) {
            a = up[i][a];
        }
    }
    return up[0][a];
}
