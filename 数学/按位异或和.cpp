#include<bits/stdc++.h>
using namespace std;
//1到n的按位异或和
long long get_val(long long n){
    switch(n%4){
        case 0: return n;
        case 1: return 1;
        case 2: return n+1;
        case 3: return 0;
    }
    return -1;
}
