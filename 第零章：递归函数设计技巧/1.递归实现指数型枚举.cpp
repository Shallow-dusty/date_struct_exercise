#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
int ans[10];
void print_one_result(int k) {
    for (int i = 0; i <= k; i++) {
        cout << ans[i] << (i == k ? "" : " ");
    }
    cout << endl;
    return ;
}





void f(int i, int j, int n) {
    if (j > n) return ;
    for (int k = j; k <= n; k++) {
        ans[i] = k; 
        print_one_result(i);
        f(i + 1, k + 1, n);
    }
    return ;
}
int main()
{
    int n;
    cin >> n;
    f(0, 1, n);
return 0;
}
