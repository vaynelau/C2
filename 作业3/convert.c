#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define IS_OP(s) (strlen(s)==1 && ((s[0])=='+' || (s[0])=='-' || (s[0])=='*' || (s[0])=='/'))
#define LEFT 1
#define RIGHT 2

typedef struct node {
    char str[100];
    struct node *left, *right;
} Node;

Node *stack[50];
int top = -1;


int check_pri(char a, char b, int dir)
{
    if ((a == '*' || a == '/') && (b == '+' || b == '-')) {
        return 1;
    }
    else if (dir == RIGHT && (a == '-' && (b == '+' || b == '-') || a == '/' && (b == '*' || b == '/'))) {
        return 1;
    }
    return 0;
}

void insert_braces(Node *p)
{
    Node *tmp = p;
    while (tmp->left != NULL) {
        tmp = tmp->left;
    }
    tmp = tmp->left = (Node *)malloc(sizeof(Node));
    strcpy(tmp->str, "(");
    tmp->left = tmp->right = NULL;
    
    tmp = p;
    while (tmp->right != NULL) {
        tmp = tmp->right;
    }
    tmp = tmp->right = (Node *)malloc(sizeof(Node));
    strcpy(tmp->str, ")");
    tmp->left = tmp->right = NULL;
}

void check_braces(Node *p)
{
    if (IS_OP(p->str)) {
        check_braces(p->left);
        check_braces(p->right);
        if (IS_OP(p->left->str) && check_pri((p->str)[0], (p->left->str)[0], LEFT)) {
            insert_braces(p->left);
        }
        if (IS_OP(p->right->str) && check_pri((p->str)[0], (p->right->str)[0], RIGHT)) {
            insert_braces(p->right);
        }
    }
}

void inorder(Node *p)
{
    if (p != NULL) {
        inorder(p->left);
        printf("%s", p->str);
        inorder(p->right);
    }
}

int main(void)
{
    char s[100];
    while (scanf("%s", s) != EOF) {
        Node *p = (Node *)malloc(sizeof(Node));
        strcpy(p->str, s);
        p->left = p->right = NULL;
        if (IS_OP(s)) {
            p->right = stack[top--];
            p->left = stack[top--];
        }
        stack[++top] = p;
    }
    check_braces(stack[0]);
    inorder(stack[0]);
    return 0;
}
