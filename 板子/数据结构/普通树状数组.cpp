template<typename T>
class BIT {
    vector<T> tree;
public:
    BIT(int n) : tree(n + 1) {}

    void update(int i, T val) {
        for (; i < tree.size(); i += i & -i) tree[i] += val;
    }

    T pre(int i) const {
        T res{};
        for (; i > 0; i &= i - 1) res += tree[i];
        return res;
    }
    
    T query(int l, int r) const {
        if (r < l) return 0;
        return pre(r) - pre(l - 1);
    }
};