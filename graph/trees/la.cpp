int la(int v, int x) {
    for (int i = 0; i <= lg; i++)
        if ((x >> i) & 1)
            v = up[v][i];
        return v;
}
