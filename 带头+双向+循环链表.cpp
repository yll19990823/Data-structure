#include<iostream>
#include<cstdlib>
using namespace std;

typedef int Type;
typedef struct Node{
  Type _data;
  struct Node* _next;
  struct Node* _prev;
}Node;

typedef struct List{
  Node* _head;//head:表示链表真正的头结点，即第一个有效的数据的位置
}List;

//创建结点
Node* createNode(Type data){
  Node* node=(Node*)malloc(sizeof(Node));
  node->_data=data;
  node->_next=node->_prev=NULL;
  return node;
}
//链表初始化
void ListInit(List* ls){
  ls->_head=createNode(0);
  ls->_head->_next=ls->_head;
  ls->_head->_prev=ls->_head;
}
//链表销毁
void ListDestory(List* ls){
  Node* cur=ls->_head;
  while(cur!=ls->_head){
    Node* next=cur->_next;
    free(cur);
    cur=next;
  }
  free(ls->_head);
  ls->_head=NULL;
}
//尾插
void ListPushBack(List* ls,Type data){
  Node* node=createNode(data);
  Node* last=ls->_head->_prev;
  last->_next=node;
  node->_prev=last;
  node->_next=ls->_head;
  ls->_head->_prev=node;
}
//尾插
void ListPopBack(List* ls){
  if(ls->_head->_next==ls->_head) return;//空链表，无数据可删
  Node* last=ls->_head->_prev;
  Node* prev=last->_prev;
  prev->_next=ls->_head;
  ls->_head->_prev=prev;
  free(last);
}
//头插
void ListPushFront(List* ls,Type data){
  Node* node=createNode(data);
  Node* front=ls->_head->_next;
  node->_next=front;
  front->_prev=node;
  node->_prev=ls->_head;
  ls->_head->_next=node;
}
//头删
void ListPopFront(List* ls){
  if(ls->_head->_next==ls->_head) return;
  Node* front=ls->_head->_next;
  Node* next=front->_next;
  ls->_head->_next=next;
  next->_prev=ls->_head;
  free(front);
}
//在链表pos位置插入某一数据元素
void ListInsert(Node* pos,Type data){
  Node* prev=pos->_prev;
  Node* node=createNode(data);
  prev->_next=node;
  node->_prev=prev;
  node->_next=pos;
  pos->_prev=node;
}
//在链表pos位置删除某一数据元素
void ListErase(Node* pos){
  Node* prev=pos->_prev;
  Node* next=pos->_next;
  prev->_next=next;
  next->_prev=prev;
  free(pos);
}
//链表元素查找
Node* ListFind(List* ls,Type data){
  Node* node=ls->_head->_next;
  while(node!=ls->_head){
    if(node->_data==data) return node;
    else node=node->_next;
  }
}
//链表元素打印
void ListPrint(List* ls){
  Node* node=ls->_head->_next;
  while(node!=ls->_head){
    cout << node->_data << " ";
    node=node->_next;
  }
  cout << endl;
}

int main(){
  List ls;
  ListInit(&ls);

  ListPushBack(&ls,2);
  ListPushBack(&ls,3);
  ListPushBack(&ls,4);
  ListPopBack(&ls);

  ListPushFront(&ls,1);
  ListPushFront(&ls,0);
  ListPopFront(&ls);

  ListInsert(ListFind(&ls,2),2);
  ListErase(ListFind(&ls,2));

  cout << "链表数据元素：" << endl;
  ListPrint(&ls);
  ListDestory(&ls);
  return 0;
}
