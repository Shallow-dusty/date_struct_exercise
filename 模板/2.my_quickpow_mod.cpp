/*************************************************************************
	> File Name: 2.my_quickpow_mod.cpp
	> Author: Shallow 
	> Mail: 1737951602@qq.com 
	> Created Time: Mon 07 Apr 2025 01:01:17 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

typedef long long ll;
ll quick_pow_mod(ll a, ll b, ll mod) {
    ll temp =  a % mod, ans = 1;
    while (b) {
        if (b & 1) ans = ans * temp % mod;
        b >>= 1;
        temp = temp * temp % mod;
    }
    return ans;
}



int main() {
    int a, b, mod;
    while (cin >> a >> b >> mod) {
        printf("%d^%d mod %d = %lld", a, b, mod, quick_pow_mod(a, b, mod));
    }

    return 0;
}
