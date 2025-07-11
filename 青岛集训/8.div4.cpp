#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//@ 大整数模板（c++风格字符串模拟）

int na[1005], nb[1005];
int nc[10000005];//本质上是1000位x1000位，开到七位足以

//# 大数加法
string add(string a, string b){
    //内存清理
    memset(na, 0, sizeof(na));
    memset(nb, 0, sizeof(nb));
    //倒置 + 转为数字,输入
    int lena = a.size(), lenb = b.size();
    for (int i = 0; i < lena; i++){
        na[lena - 1 - i] = a[i] - '0';
    }
    for (int i = 0; i < lenb; i++){
        nb[lenb - 1 - i] = b[i] - '0';
    }
    //在位数较多的那个数上操作
    int lmax = lena > lenb ? lena : lenb;
    //计算 + 处理进位
    for (int i = 0; i < lmax; i++){
        na[i] += nb[i];
        na[i + 1] += na[i] / 10;
        na[i] %= 10;
    }
    //最高位的进位处理
    if (na[lmax]) lmax++;
    //倒转回正序 + 字符，输出
    string ans;
    for (int i = lmax - 1; i >= 0; i--){
        ans += na[i] + '0';
    }
    return ans;
}

//# 大数减法
string sub(string a, string b){
    memset(na, 0, sizeof(na));
    memset(nb, 0, sizeof(nb));
    //负数标记，真为负，假为正
    bool neg = false;
    //特殊判断：相等直接为0
    if (a == b) return "0";
    //// cout << lena << " " << lenb << endl;
    //以大的那个数上操作，有需要再转负
    if (a.size() < b.size() || (a.size() == b.size() && a < b)){
        swap(a, b);
        neg = true;
    }
    //! 注意这里a,b长度的计算不可优化，否则a,b互换后长度未能即使更新
    int lena = a.size(), lenb = b.size();
    int lmax = lena;
    // cout << lmax;
    //倒置输入
    for (int i = 0; i < lena; i++){
        na[i] = a[lena - 1 - i] - '0';
    }
    for (int i = 0; i < lenb; i++){
        nb[i] = b[lenb - 1 - i] - '0';
    }
    //计算 + 进位处理
    for (int i = 0; i < lmax; i++){
        na[i] -= nb[i];
        if (na[i] < 0){
            na[i] += 10;
            na[i + 1] -= 1;
        }
    }
    //消除前导0（最高位为0则位数--）
    while (lmax > 0 && !na[lmax - 1]){
        lmax--;
    }
    //倒转回正序输出，有需要加上负号
    string ans;
    for (int i = lmax - 1; i >= 0; i--){
        ans += na[i] + '0';
    }
    if (neg) ans = "-" + ans;
    return ans;
}

//# 大整数乘法
string mul(string a, string b){
    memset(na, 0, sizeof(na));
    memset(nb, 0, sizeof(nb));
    memset(nc, 0, sizeof(nc));
    //特殊判断，有0则0
    if (a == "0" || b == "0") return "0";
    int lena = a.size(), lenb = b.size();
    //倒置输入
    for (int i = 0; i < lena; i++){
        na[i] = a[lena - 1 - i] - '0';
    }
    for (int i = 0; i < lenb; i++){
        nb[i] = b[lenb - 1 - i] - '0';
    }
    //计算 + 进位处理
    for (int i = 0; i < lena; i++){
        for (int j = 0; j < lenb; j++){
            nc[i + j] += na[i] * nb[j];
            nc[i + j + 1] += nc[i + j] / 10;
            nc[i + j] %= 10;
        } 
    }
    //倒回正序输出
    string ans;
    int m_pos = lena + lenb - 1;
    //前导0处理
    while (m_pos >= 0 && !nc[m_pos]) m_pos--;
    for (int i = m_pos; i >= 0; i--){
        ans += nc[i] + '0';
    }
    return ans;
}

//# 大整数除法
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

int main()
{   
    int m, n;
    cin >> m >> n;
    string a, b;
    cin >> a >> b;
    // //cout << a << endl << b << endl;
    // cout << add(a, b) << endl;
    cout << sub(a, b) << endl;
    // cout << mul(a, b) << endl;
    // cout << div(a, b) << endl;
    return 0;
}

