/*************************************************************************
	> File Name: 2.linklist.cpp
	> Author: Shallow 
	> Mail: 1737951602@qq.com 
	> Created Time: Tue 24 Sep 2024 12:10:29 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define DL 3
#define STR(n) #n//c语言字符串转换操作符#，#n会吧n转化为一个字符串字面量
#define DIGIT_LEN(n) "%" STR(n) "d"//先调用宏STR,将结果拼接为一个格式字符串%nd
typedef struct Node{
    int data;
    struct Node *next;
} Node;
//初始化
Node *getNewNode(int val){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

//插入操作
Node *insert(Node *head, int pos, int val){
    Node new_head, *p = &new_head, *node = getNewNode(val);//虚拟头结点，指向原链表的第一个节点，指针p指向虚拟头结点
    new_head.next = head;
    for (int i = 0; i < pos; i++){
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
    return new_head.next;

}

//销毁链表
void clear(Node *head){
    if (head == NULL)   return ;
    for (Node *p = head, *q; p; p = q){
        q = p->next;//需先将下一个节点的地址保存到q才能销毁当前节点
        free(p);
    }
    return ;
}

void output_linklist(Node *head, int flag = 0){
    int  n = 0;
    for (Node *p = head; p; p = p->next) n += 1;//统计节点个数
    for (int i = 0; i < n; i++){
        printf(DIGIT_LEN(DL), i);
        printf("  ");
    }
    printf("\n");
    for (Node *p = head; p; p = p->next){
        printf(DIGIT_LEN(DL), p->data);
        printf("->");
    }
    printf("\n");
    if (flag = 0) printf("\n\n");
}

//查找操作
int find(Node *head, int val){
    Node *p = head;
    int n = 0;
    while(p){
        if (p->data == val){
            output_linklist(head);
            int len = n * (DL + 2) + 2;
            for (int i = 0; i < len; i++) printf(" ");
            printf("^\n");
            for (int i = 0; i < len; i++) printf(" ");
            printf("|\n");
            return 1;
        }
        n += 1;
        p = p->next;
    }
    return 0;
}




int main(){
    srand(time(0));
    #define MAX_OP 20
    Node *head = NULL;
    for (int i = 0; i < MAX_OP; i++){
        int pos = rand() % (i + 1), val = rand() % 100;
        printf("insert %d at %d to linklist\n", val, pos);
        head = insert(head, pos, val);
        output_linklist(head);
    }
    int val;
    while (~scanf("%d", &val)){
        if (!find(head, val)){
            printf("not found\n");
        }
    }
    clear(head);
    return 0;
}
