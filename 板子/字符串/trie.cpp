#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
const int CNT = 36;
int trie[N][CNT];
int pass[N], endd[N];// pass: 当前记住的句子经过该节点的数量, endd: 该节点是否为某个记住句子的结尾
int cnt;
inline int get_path(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    return c - '0' + 26;         // 数字映射到 26 ~ 35
}
void build(){
    for(int i = 1; i <= cnt; i++){
        fill(trie[i], trie[i] + CNT, 0);
        pass[i] = 0;
        endd[i] = 0;
    }
    cnt = 1; 
}
// 判断一个句子当前是否被记住
bool exists(string str){
    int head = 1;
    for(char c : str){
        int p = get_path(c);
        if(trie[head][p] == 0) 
            return false;
        head = trie[head][p];
    }
    return endd[head] > 0;
}
// 插入一个新的句子
void insert(string str){
    int head = 1;
    pass[head]++;
    for(char c : str){
        int p = get_path(c);
        if(trie[head][p] == 0)
            trie[head][p] = ++cnt;
        head = trie[head][p];
        pass[head]++;
    }
    endd[head] = 1;
}
// 删除一个当前记住的句子
void erase(string str){
    int head = 1;
    pass[head]--;
    for(char c : str){
        int p = get_path(c);
        int nxt = trie[head][p];
        pass[nxt]--;
        head = nxt;
    }
    endd[head] = 0; // 不再记住
}
// 查询当前记住的句子中以 prefix 为前缀的句子数量
int prefix_num(string prefix){
    int head = 1;
    for(char c : prefix){
        int p = get_path(c);
        if(trie[head][p] == 0) 
            return 0;
        head = trie[head][p];
    }
    return pass[head];
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    build();
    unordered_map<string, int> mp; // 当前记住的每个句子的出现次数
    mp.reserve(n * 2);
    while(n--){
        int op; string str; cin >> op >> str;
        if(op == 1) {
            if(!exists(str)){
                insert(str);
                mp[str] = 1;  // 重新记忆，计数从1开始
            } 
            else
                mp[str]++; // 已经记住，累加
            cout << mp[str] << endl;
        } 
        else if(op == 2)
            cout << (prefix_num(str) > 0 ? "YES" : "NO") << endl;
        else{
            if(exists(str)){
                erase(str);
                mp.erase(str); // 忘记该句及其出现次数
            }
        }
    }

    return 0;
}
