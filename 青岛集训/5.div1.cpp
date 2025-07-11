/*************************************************************************
	> File Name: 5.div1.cpp
	> Author: Shallow 
	> Mail: 1737951602@qq.com 
	> Created Time: Mon 10 Feb 2025 09:05:49 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
string div(string a, string b){
    memset(na, 0, sizeof(na));
    memset(nb, 0, sizeof(nb));
    memset(nc, 0, sizeof(nc));
    if (b == "0") return "wrong";
    int lena = a.size(), lenb = b.size();
    string remain;
    string ret;
    if (lena < lenb || (lena == lenb && a < b)) return "0";
    // for (int i = 0; i < lena; i++){
    //     na[i] = a[lena - 1 -i] - '0';
    // }
    // for (int i = 0; i < lenb; i++){
    //     nb[i] = b[lenb - 1 -i] - '0';
    // }
    for (int i = 0; i < lena; i++) {
        remain += a[i];
        while (remain.size() > 1 && remain[0] == '0')
            remain.erase(0, 1);
            int count = 0;
            // while (remain.size() > b.size() || (remain.size() == b.size() && remain > b)){
            while (!(remain.size() < b.size() || (remain.size() == b.size() && remain < b))) {
                remain = sub(remain, b);
                count++;
            }
        ret += count + '0';
        
    }
    int pos = 0;
    while (pos < ret.size() - 1 && ret[pos] == '0') 
        pos++;
    return ret.substr(pos);
}
