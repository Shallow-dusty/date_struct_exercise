/*************************************************************************
	> File Name: 1.myquickpow.cpp
	> Author: Shallow 
	> Mail: 1737951602@qq.com 
	> Created Time: Mon 07 Apr 2025 12:48:53 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

typedef long long ll;
ll quick_pow(ll a, ll b) {
    ll temp = a, ans = 1;
    while (b) {
        if (b % 2) ans = ans * temp;
        b /= 2;
        temp = temp * temp;
    }
    return ans;
}





int main(){
    int a, b;
    while (cin >> a >> b) {
        printf("%d^%d = %lld\n", a, b, quick_pow(a, b));
    }
    return 0;
}
