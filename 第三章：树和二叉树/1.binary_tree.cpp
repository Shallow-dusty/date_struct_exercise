/*************************************************************************
	> File Name: 1.binary_tree.cpp
	> Author: Shallow 
	> Mail: 1737951602@qq.com 
	> Created Time: Thu 13 Mar 2025 04:21:55 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int key;
    struct Node *lchild, *rchild;
};

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->rchild);
    clear(root->lchild);
    free(root);
    return ;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (rand() % 2) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;
}

#define MAX_N 20
Node* queue[MAX_N + 5];
int head, tail;
void bfs(Node *root) {
    head = tail = 0;
    queue[tail++] = root;
    while (head < tail) {
        Node* node = queue[head];
        printf("\nnode : %d\n", node->key);
        if (node->lchild) {
            queue[tail++] = node->lchild;
            printf("\t%d->%d(left)\n", node->key, node->lchild->key);
        }
        if (node->rchild) {
            queue[tail++] = node->rchild;
            printf("\t%d->%d(right)\n", node->key, node->rchild->key);
        }
        head++;
    }
    return ; 
}

int tot = 0;
void dfs(Node *root) {
    if (root == NULL) return ;
    int start, end;
    tot += 1;
    start = tot;
    if (root->lchild) dfs(root->lchild);
    if (root->rchild) dfs(root->rchild);
    end = tot;
    printf("%d : [%d, % d]\n", root->key, start, end);
    tot += 1;
    return ;
}




int main () {
    srand(time(NULL));
    Node *root = NULL;
    for (int i = 0; i < MAX_N; i++) {
        root = insert(root, rand() % 100);
    }
    bfs(root);
    dfs(root);
    return 0;
} 
