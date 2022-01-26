struct line {
    int k, b;
};

vector<line> lines;
vector<ld> p;

ld cross(line a, line b) {
    return (ld)(b.b - a.b) / (ld)(a.k - b.k);
}

void upd(line cur) {
    while (sz(lines)) {
        line a = lines.back();
        int x = p.back();
        if (cross(cur, a) < p.back()) {
            lines.pop_back();
            p.pop_back();
        } else {
            break;
        }
    }
    if (lines.empty())
        p.push_back(-INF);
    else 
        p.push_back(cross(lines.back(), cur));
    lines.push_back(cur);
}

int get(int x) {
    int l = 0, r = sz(lines);
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (p[m] <= x) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return lines[l].k * x + lines[l].b;
}
