/*************************************************************************
	> File Name: 0.sort_test.h
	> Author: Shallow 
	> Mail: 1737951602@qq.com 
	> Created Time: Wed 05 Feb 2025 04:16:46 PM CST
 ************************************************************************/

#ifndef _SORT_TEST_H
#define _SORT_TEST_H

#define SMALL_DATA 5000
#define BIG_DATA 10000000

__attribute__((constructor))
void init() {
    printf("init rand\n");
    srand(time(NULL));
}

bool check(int *arr, int l, int r) {
    for (int i = l + 1; i < r; i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

int *getRandData(int n) {
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
    return arr;
}

//func为排序函数，arr为待排数组，n为数组长度
#define TEST(func, arr, n) { \
    printf("Test : %s", #func); \
    /*为保护源数据，复制数据以检验*/ \
    int *temp  = (int *)malloc(sizeof(int) * n); \
    memcpy(temp, arr, sizeof(int) * n); \
    long long b = clock(); \
    func(arr, 0, n); \
    long long e = clock(); \
    if (check(temp, 0, n)){ \
        printf("\tOK!"); \
    } else { \
        printf("Failed!\t"); \
    } \
    printf("%lld ms \n", (e - b) * 1000 / CLOCKS_PER_SEC); \
    free(temp); \
}
#endif
