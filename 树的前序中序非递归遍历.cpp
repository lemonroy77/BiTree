#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Maxsize 100
typedef char ElemType;
typedef struct BTNode{
    ElemType data;
    struct BTNode*lchild;
    struct BTNode*rchild;
}BTNode,*BiTree;
typedef struct{
    BTNode* data[Maxsize];
    int top;
}SeqStack;
void CreateBTree(BiTree &T,char *str)	//创建二叉树
{
    BTNode *St[Maxsize],*p=NULL;
    int top=-1,k,j=0;
    char ch;
    T=NULL;				//建立的二叉树初始时为空
    ch=str[j];
    while (ch!='\0')  	//str未扫描完时循环
    {
        switch(ch)
        {
            case '(':top++;St[top]=p;k=1; break;		//为左孩子节点
            case ')':top--;break;
            case ',':k=2; break;                      		//为孩子节点右节点
            default:p=(BTNode *)malloc(sizeof(BTNode));
                p->data=ch;p->lchild=p->rchild=NULL;
                if (T==NULL)                    	 	//*p为二叉树的根节点
                    T=p;
                else  								//已建立二叉树根节点
                {
                    switch(k)
                    {
                        case 1:St[top]->lchild=p;break;
                        case 2:St[top]->rchild=p;break;
                    }
                }
        }
        j++;
        ch=str[j];
    }
}
void InitStack(SeqStack *S){
    S->top=-1;
}
void push(SeqStack *S,BiTree p){
    if(S->top==Maxsize-1) return;
    S->top++;
    S->data[S->top] = p;
}
//出栈
void pop(SeqStack *S,BiTree &p){
    if(S->top==-1)  return;
    p=S->data[S->top--];
}
//取栈顶操作
void GetTop(SeqStack *S,BTNode*p){
    //栈为空的情况
    if(S->top==-1) return;
    p=S->data[S->top];
}
void preorder(BiTree T){
    SeqStack *s = (SeqStack*)malloc(sizeof(SeqStack));
    InitStack(s);
    BTNode*p=T;
    while(p||s->top!=-1){
        if(p){
            printf("%c ",p->data);
            push(s,p);
            p=p->lchild;
        }
        else{
            pop(s,p);
            p=p->rchild;
        }
    }
}
void Inorder(BiTree T){
    SeqStack *s = (SeqStack*)malloc(sizeof(SeqStack));
    InitStack(s);
    BTNode*p=T;
    while(p||s->top!=-1){
        if(p){
            push(s,p);
            p=p->lchild;
        }
        else{
            pop(s,p);
            printf("%c ",p->data);
            p=p->rchild;
        }
    }
}
int main()
{
    BTNode *T;
    CreateBTree(T,"A(B(D,E),C(,F))");
    printf("\n");
    printf("树的前序非递归遍历为:");
    preorder(T);
    printf("树的中序非递归遍历为:");
    Inorder(T);
    return 0;
}
