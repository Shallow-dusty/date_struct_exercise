/*************************************************************************
        > File Name: 1.vector.cpp
        > Author: Shallow 
        > Mail: 1737951602@qq.com 
        > Created Time: Sat 24 Aug 2024 10:48:56 PM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
//顺序表结构定义
typedef struct vector{
    int size;//表容量
    int count;//表长
    int *data;//连续整型存储区
} vector;

vector *getNewVector(int n){//初始化一个容量为n的顺序表
    vector *p = (vector *)malloc(sizeof(vector));//开辟顺序表本身的空间
    p->count = 0;
    p->size = n;
    p->data = (int *)malloc(sizeof(int) * n);
    return p;
}
//扩容操作
int expand(vector *v){
    if (v == NULL) return 0;
    printf("expand v form %d to %d\n", v->size, 2 * v->size);
    int *p = (int *)realloc(v->data, sizeof(int) * 2 * v->size);
    if (p == NULL) return 0;
//    v->data = (int *)realloc(v->data, sizeof(int) * 2 * v->size);//realloc：重新分配内存
    v->data = p;
    v->size *= 2;
    return 1;
}

//插入操作
int insert(vector *v, int pos, int val){//在pos处插入val值
    if (pos < 0 || pos > v->count) return 0;//插入位置小于0或插入位置大于当前表长时插入失败
    if (v->size == v->count && !expand(v)) return 0;//如果顺序表满(即表长等于表容量时)且扩容失败，插入操作返回0
    for (int i = v->count - 1; i >= pos; i--){
        v->data[i + 1] = v->data[i];
    }//必须为逆序遍历
    v->data[pos] = val;
    v->count += 1;//数据结构的性质勿忘维护
    return 1;
}

int erase(vector *v, int pos){
    if (pos < 0 || pos >= v->count ) return 0;//位置合理性判断:小于0或大于表长
    for (int i = pos + 1; i < v->count; i++){
        v->data[i - 1] = v->data[i];
    }
    v->count -= 1;
    return 1;
}

void output_vector(vector *v){
    int len = 0;
    for (int i = 0; i <= v->size - 1; i++){
        len += printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i <= len; i++) printf("-");
    printf("\n");
    for (int i = 0; i < v->count; i++){
        printf("%5d", v->data[i]);
    }
    printf("\n");
    printf("\n");
    return;
}
void clear(vector *v){
    if (v == NULL) return;//如果表不存在则不进行任何操作
    free(v->data);//先销毁连续的存储区
    free(v);//再销毁表本身
    return;
}
int main(){
    srand(time(0));
    #define MAX_OP 20
    vector *v = getNewVector(2);
    for (int i = 0; i < MAX_OP; i++){
        int op = rand() % 4;
        int pos = rand() % (v->count + 2);
        int val = rand() % 100;
        switch(op){
            case 0:
            case 1:
            case 2:
                printf("insert %d at %d to vector = %d\n", val, pos, insert(v, pos, val));
                break;
            case 3:
                printf("earse item at %d in vector = %d\n", pos, erase(v, pos));
                break;
        }
        output_vector(v);
    }
    clear(v);
    return 0;
}

