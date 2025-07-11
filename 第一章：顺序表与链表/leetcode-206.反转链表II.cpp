/*************************************************************************
	> File Name: leetcode-206.反转链表II.cpp
	> Author: Shallow 
	> Mail: 1737951602@qq.com 
	> Created Time: Wed 27 Nov 2024 02:11:31 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
typedef struct ListNode{
    int val;
    ListNode *next;
} ListNode;
//头插法
ListNode *insert_node(ListNode *head, ListNode *new_node){
    ListNode pre_head, *p;
    p = new_node;
    pre_head.next = head;
    p->next = pre_head.next;
    pre_head.next = p;
    head = p;
    return head;
}

void show_ListNode(ListNode *head){
    ListNode *p;
    p = head;
    while (p){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return ;
}
ListNode *reserve(ListNode *head){
    if (head == NULL || head->next == NULL) return head;
    ListNode *q = head, *p;
    ListNode *new_head = NULL;
    while (q){
        insert_node(new_head, q);
        q = q->next;
    }
    return new_head;
    
}
int main(){
    ListNode *head = NULL;
    ListNode node1, node2, node3, node4;
    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node4.val = 4;
    head = insert_node(head, &node1);
    head = insert_node(head, &node2);
    head = insert_node(head, &node3);
    head = insert_node(head, &node4);
    show_ListNode(head);
    head = reserve(head);
    show_ListNode(head);
    return 0;
}
