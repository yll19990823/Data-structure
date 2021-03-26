#include<iostream>
#include<cstdlib>
using namespace std;

typedef int Type;
typedef struct Node{
  Type _data;
  struct Node* _next;
}Node;

typedef struct SingleList{
  Node* _head;//head:表示链表真正的头结点，即第一个有效的数据的位置
}SingleList;

//创建结点
Node* createNode(Type data){
  Node* node=(Node*)malloc(sizeof(Node));
  node->_data=data;
  node->_next=NULL;
  return node;
}
//链表初始化
void SingleListInit(SingleList* s){
  s->_head=NULL;
}
//链表销毁
void SingleListDestory(SingleList* s){
  Node* cur=s->_head;
  while(cur){
    Node* next=cur->_next;
    free(cur);
    cur=next;
  }
  free(s->_head);
  s->_head=NULL;
}
//尾插
void SingleListPushBack(SingleList* s,Type data){
  Node* node=createNode(data);
  if(!s->_head){//s->_head==NULL
    s->_head=node;
  }else{
    Node* last=s->_head;
    while(last->_next){
      last=last->_next;
    }
    last->_next=node;
  }
}
//尾删
void SingleListPopBack(SingleList* s){
  if(s->_head){
    Node* lastf=NULL;
    Node* last=s->_head;
    while(last->_next){
      lastf=last;
      last=last->_next;
    }
    if(last==s->_head) s->_head=NULL;
    else lastf->_next=NULL;
    free(last);
  }
}
//头插
void SingleListPushFront(SingleList* s,Type data){
  Node* node=createNode(data);
  if(!s->_head){
    s->_head=node;
  }else{
    node->_next=s->_head;
    s->_head=node;
  }
}
//头删
void SingleListPopFront(SingleList* s){
  if(s->_head){
    Node* cur=s->_head;
    s->_head=cur->_next;
    free(cur);
  }
}
//在链表pos位置后插入某一数据元素
void SingleListInsertAfter(Node* pos,Type data){
  Node* node=createNode(data);
  node->_next=pos->_next;
  pos->_next=node;
}
//在链表pos位置后删除某一数据元素
void SingleListEraseAfter(Node* pos){
  if(!pos) return;
  Node* node=pos->_next;
  if(node){
    pos->_next=node->_next;
    free(node);
  }
}
//链表元素查找
Node* SingleListFind(SingleList* s,Type data){
  Node* cur=s->_head;
  while(cur){
    if(cur->_data==data) return cur;
    else cur=cur->_next;
  }
}
//链表元素打印
void SingleListPrint(SingleList* s){
  Node* cur=s->_head;
  while(cur){
    cout << cur->_data << " ";
    cur=cur->_next;
  }
  cout << endl;
}

int main(){
  SingleList s;
  SingleListInit(&s);

  SingleListPushBack(&s,2);
  SingleListPushBack(&s,3);
  SingleListPushBack(&s,4);
  SingleListPopBack(&s);

  SingleListPushFront(&s,1);
  SingleListPushFront(&s,0);
  SingleListPopFront(&s);

  SingleListInsertAfter(SingleListFind(&s,2),2);
  SingleListEraseAfter(SingleListFind(&s,2));

  cout << "链表数据元素：" << endl;
  SingleListPrint(&s);
  SingleListDestory(&s);
  return 0;
}
