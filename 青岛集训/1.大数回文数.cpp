/*************************************************************************
	> File Name: 1.大数回文数.cpp
	> Author: Shallow 
	> Mail: 1737951602@qq.com 
	> Created Time: Fri 07 Feb 2025 07:02:16 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char arr[100];
    scanf("%s", arr);
    char temp[100];
    strcpy(temp, arr);
    int len = strlen(arr);
    for (int i = 0; i < len / 2; i++){
        arr[i] ^= arr[len - i - 1];
        arr[len - i - 1] ^= arr[i];
        arr[i] ^= arr[len - i - 1];
    }
    if (strcmp(temp, arr) == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
     
    return 0;
}
