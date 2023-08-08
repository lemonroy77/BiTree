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
void CreateBTree(BiTree &T,char *str)	//����������
{
    BTNode *St[Maxsize],*p=NULL;
    int top=-1,k,j=0;
    char ch;
    T=NULL;				//�����Ķ�������ʼʱΪ��
    ch=str[j];
    while (ch!='\0')  	//strδɨ����ʱѭ��
    {
        switch(ch)
        {
            case '(':top++;St[top]=p;k=1; break;		//Ϊ���ӽڵ�
            case ')':top--;break;
            case ',':k=2; break;                      		//Ϊ���ӽڵ��ҽڵ�
            default:p=(BTNode *)malloc(sizeof(BTNode));
                p->data=ch;p->lchild=p->rchild=NULL;
                if (T==NULL)                    	 	//*pΪ�������ĸ��ڵ�
                    T=p;
                else  								//�ѽ������������ڵ�
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
//��ջ
void pop(SeqStack *S,BiTree &p){
    if(S->top==-1)  return;
    p=S->data[S->top--];
}
//ȡջ������
void GetTop(SeqStack *S,BTNode*p){
    //ջΪ�յ����
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
int main()
{
    BTNode *T;
    CreateBTree(T,"A(B(D,E),C(,F))");
    printf("\n");
    preorder(T);
    return 0;
}
