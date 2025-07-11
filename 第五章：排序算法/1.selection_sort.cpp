/*************************************************************************
	> File Name: 1.selection_sort.cpp
	> Author: Shallow 
	> Mail: 1737951602@qq.com 
	> Created Time: Wed 05 Feb 2025 04:16:07 PM CST
 ************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "0.sort_test.h"
using namespace std;

void selection_sort(int *arr, int l, int r) {
    for (int i = l; i < r - 1; i++) {
        int ind = i;
        for (int j = i + 1; j < r; j++) {
            if (arr[ind] > arr[j]) ind = j;
        }
        swap(arr[ind], arr[i]);
    }
    return ;
}




int main(){
    int *arr = getRandData(SMALL_DATA);
    TEST(selection_sort, arr, SMALL_DATA)
    return 0;
}
