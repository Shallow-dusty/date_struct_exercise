/*************************************************************************
	> File Name: 2.大数回文数_双指针.cpp
	> Author: Shallow 
	> Mail: 1737951602@qq.com 
	> Created Time: Sat 08 Feb 2025 08:42:33 AM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char str[31];
    scanf("%s", str);
    for (int i = 0, I = strlen(str) - 1; str[i]; i++, I--){
        if (str[i] == str[I]) continue;
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}
