/*************************************************************************
	> File Name: 6.div2.cpp
	> Author: Shallow 
	> Mail: 1737951602@qq.com 
	> Created Time: Mon 10 Feb 2025 09:06:01 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
string div(string b, string a){//返回a / b的值
    memset(na, 0, sizeof(na));
    memset(nb, 0, sizeof(nb));
    string remain;//余数
    string ret;//商
    int lena = a.size(), lenb = b.size();
    //特殊判断：除数为0/被除数小于除数
    if (b == "0") return "wrong";
    if (lena < lenb || (lena == lenb && a < b)) return "0";
    //除法为高位向低位运算，无需逆置
    for (int i = 0; i < lena; i++) {
        remain += a[i];
        //去除余数的前导0
        while (remain.size() > 1 && remain[0] == '0')
            remain.erase(0, 1);
            int count = 0;
            //当余数位数足够，则开始商
            while (remain.size() > b.size() || (remain.size() == b.size() && remain >= b)){
                remain = sub(remain, b);
                count++;
            }
        ret += count + '0';
        
    }
    //消除前导0（取子串输出）
    int pos = 0;
    while (pos < ret.size() - 1 && ret[pos] == '0') 
        pos++;
    return ret.substr(pos);
}
