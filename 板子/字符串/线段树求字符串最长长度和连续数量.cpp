#include<bits/stdc++.h>
using namespace std;
struct Nodes{
    int len;
    int pre[3],suf[3],cnt[3],mx[3];
    Nodes(int c = -1):len(c==-1? 0:1){
        memset(pre,0,sizeof pre);
        memset(suf,0,sizeof suf);
        memset(cnt,0,sizeof cnt);
        memset(mx,0,sizeof mx);
        if(c>=0)pre[c] = suf[c] = cnt[c] = mx[c] = 1;
    }
};
class LazySegmentTree {
    using T = Nodes;
    using F = int;
    const F TODO_INIT = 0;
    struct Node{
        T val;
        F todo;
    };
    int n;
    vector<Node> tree;

    T merge_val(const T& a, const T& b) const {
        T res;
        res.len = a.len+b.len;
        for(int i=0;i<3;i++){
            res.pre[i]=(a.pre[i]==a.len)?a.len+b.pre[i]:a.pre[i];
            res.suf[i]=(b.suf[i]==b.len)?b.len+a.suf[i]:b.suf[i];
            res.cnt[i]=a.cnt[i]+b.cnt[i]-(a.suf[i]>0&&b.pre[i]>0?1:0);
            res.mx[i]=max({a.mx[i],b.mx[i],a.suf[i]+b.pre[i]});
        }
        return res;
    }

    F merge_todo(const F& a, const F& b) const {
       return (a+b)%3;
    }

    void apply(int node, int l, int r, F todo) {
        T& cur = tree[node].val;
        int npre[3],nsuf[3],ncnt[3],nmx[3];
        for(int i=0;i<3;i++){
            int nc = (i+todo)%3;
            npre[nc] = cur.pre[i];
            nsuf[nc] = cur.suf[i];
            ncnt[nc] = cur.cnt[i];
            nmx[nc] = cur.mx[i];
        }
        for(int i=0;i<3;i++){
            cur.pre[i] = npre[i];
            cur.suf[i] = nsuf[i];
            cur.cnt[i] = ncnt[i];
            cur.mx[i] = nmx[i];
        }
        tree[node].todo = merge_todo(todo,tree[node].todo);
    }

    void spread(int node, int l, int r) {
        Node& cur = tree[node];
        F todo = cur.todo;
        if (todo == TODO_INIT) return;
        int m = (l + r) >> 1;
        apply(node * 2, l, m, todo);
        apply(node * 2 + 1, m + 1, r, todo);
        cur.todo = TODO_INIT;
    }

    void maintain(int node) {
        tree[node].val = merge_val(tree[node * 2].val, tree[node * 2 + 1].val);
    }

    void build(const vector<T>& a, int node, int l, int r) {
        Node& cur = tree[node];
        cur.todo = TODO_INIT;
        if (l == r) {
            cur.val = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(a, node * 2, l, m);
        build(a, node * 2 + 1, m + 1, r);
        maintain(node);
    }

    void update(int node, int l, int r, int ql, int qr, F f) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, f);
            return;
        }
        spread(node, l, r);
        int m = (l + r) >> 1;
        if (ql <= m) update(node * 2, l, m, ql, qr, f);
        if (qr > m) update(node * 2 + 1, m + 1, r, ql, qr, f);
        maintain(node);
    }

    T query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[node].val;
        spread(node, l, r);
        int m = (l + r) >> 1;
        if (qr <= m) return query(node * 2, l, m, ql, qr);
        if (ql > m) return query(node * 2 + 1, m + 1, r, ql, qr);
        T l_res = query(node * 2, l, m, ql, qr);
        T r_res = query(node * 2 + 1, m + 1, r, ql, qr);
        return merge_val(l_res, r_res);
    }

public:

    LazySegmentTree(int n, T init_val = 0) : LazySegmentTree(vector<T>(n, init_val)) {}

    LazySegmentTree(const vector<T>& a) : n(a.size()), tree(2 << bit_width(a.size() - 1)) {
        build(a, 1, 0, n - 1);
    }//c++20

    void update(int ql, int qr, F f) {
        update(1, 0, n - 1, ql, qr, f);
    }

    T query(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr);
    }
    int to_ans()const{
        return tree[1].val.cnt[0];
    }
    int to_max()const{
        return tree[1].val.mx[0];
    }
};

void solve_cnt(){
    int n,q;cin>>n>>q;
    string s;cin>>s;
    vector<Nodes> a(n);
    for(int i=0;i<n;i++)a[i] = Nodes(s[i]-'A');
    LazySegmentTree seg(a);
    while(q--){
        int op;cin>>op;
        if(op==1){
            int l,r;cin>>l>>r;
            seg.update(l-1,r-1,1);
        }else{
            cout<<seg.to_ans()<<endl;
        }
    }
}

void solve_max(){
    int n,q;cin>>n>>q;
    string s;cin>>s;
    vector<Nodes> a(n);
    for(int i=0;i<n;i++)a[i] = Nodes(s[i]-'A');
    LazySegmentTree seg(a);
    while(q--){
        int op;cin>>op;
        if(op==1){
            int l,r;cin>>l>>r;
            seg.update(l-1,r-1,1);
        }else{
            cout<<seg.to_max()<<endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--){
        //solve_cnt();
        solve_max();
    }
    return 0;
}