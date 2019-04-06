#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef string stackElement;
typedef struct{
int top;
stackElement *s;
int size ;
}stack_t;
int isFull(stack_t c);
int isEmpty(stack_t c);
int creatStack(stack_t *c,int size);
int push(stack_t *c,string x);
int pop(stack_t *c,stackElement *x);
typedef string EleType;
typedef struct node{
EleType data;
struct node *Left;
struct node *Right;
}TNode;
typedef TNode *Btree;
void preOrder(Btree t);
void inOrder(Btree t);
void postOrder(Btree);
int checker(char arr);
TNode*myinsert(Btree t,EleType arr);
int main()
{
Btree t1;
t1=NULL;
char arr[]="100+9+33-11+925";

t1=myinsert(t1,arr);
preOrder(t1);
    return 0;
}
int isFull(stack_t c){
if(c.top==c.size-1)
    return 1;
else return 0;

}
int isEmpty(stack_t c){
if(c.top==-1)
    return 1;
else return 0;
}
int creatStack(stack_t *c,int size){
c->s=(stackElement*)malloc(size*sizeof(stackElement));
if(c->s==NULL){
    return 0;
}
c->top=-1;
c->size=size;
return 1;

}
int push(stack_t *c,string x){
if(!isFull(*c))
{
    c->top++;
    c->s[c->top]=x;
    return 1;
}
return 0;

}
int pop(stack_t *c,stackElement *x){
if(!isEmpty(*c)){
    *x=c->s[c->top];
    c->top--;
    return 1;
}
return 0;

}

void preOrder(Btree t){
if(t!=NULL){
    cout<<t->data;
    preOrder(t->Left);
    preOrder(t->Right);
}

}
void inOrder(Btree t){
    if(t!=NULL){
inOrder(t->Left);
cout<<t->data;
inOrder(t->Right);
    }
}
void postOrder(Btree t){
if(t!=NULL){
    postOrder(t->Left);
    postOrder(t->Right);
    cout<<t->data;
}
}
TNode*myinsert(Btree t,EleType arr){
TNode *temp2,*temp4,*temp3=NULL;
int i=0;
string x;
stack_t s1;
string c="";
creatStack(&s1,50);
while(arr[i]!='\0'){

    if(checker(arr[i])){
c+=arr[i];
  }
 else{ if(!isFull(s1))
        push(&s1,c);
       c=" ";}
   if(arr[i]=='+'||arr[i]=='-') {
     temp2=(TNode*)malloc(sizeof(TNode));
  if(temp2==NULL)
    return 0;

  temp2->data=arr[i];
  temp2->Left=temp3;
  temp2->Right=NULL;
  temp3=temp2;
 }

i++;
}
push(&s1,c);

t=temp2;
temp4=t;


do{
TNode *temp2;
    temp2=(TNode*)malloc(sizeof(TNode));

    pop(&s1,&x);
    temp2->data=x;
    temp2->Left=temp2->Right=NULL;

if(temp4->Right==NULL){
    temp4->Right=temp2;}

else {
        temp4=temp4->Left;
        temp4->Right=temp2;
}

}while(temp4->Left!=NULL);

pop(&s1,&x);
temp2=(TNode*)malloc(sizeof(TNode));
temp2->data=x;
    temp2->Left=NULL;
    temp2->Right=NULL;
    temp4->Left=temp2;

return t;
}
int checker(char arr){
    if(arr>='0'&&arr<='9'){
        return 1;
    }
    else return 0;
}
