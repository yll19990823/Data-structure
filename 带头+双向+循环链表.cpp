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
  Node* _head;//head:��ʾ����������ͷ��㣬����һ����Ч�����ݵ�λ��
}List;

//�������
Node* createNode(Type data){
  Node* node=(Node*)malloc(sizeof(Node));
  node->_data=data;
  node->_next=node->_prev=NULL;
  return node;
}
//�����ʼ��
void ListInit(List* ls){
  ls->_head=createNode(0);
  ls->_head->_next=ls->_head;
  ls->_head->_prev=ls->_head;
}
//��������
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
//β��
void ListPushBack(List* ls,Type data){
  Node* node=createNode(data);
  Node* last=ls->_head->_prev;
  last->_next=node;
  node->_prev=last;
  node->_next=ls->_head;
  ls->_head->_prev=node;
}
//β��
void ListPopBack(List* ls){
  if(ls->_head->_next==ls->_head) return;//�����������ݿ�ɾ
  Node* last=ls->_head->_prev;
  Node* prev=last->_prev;
  prev->_next=ls->_head;
  ls->_head->_prev=prev;
  free(last);
}
//ͷ��
void ListPushFront(List* ls,Type data){
  Node* node=createNode(data);
  Node* front=ls->_head->_next;
  node->_next=front;
  front->_prev=node;
  node->_prev=ls->_head;
  ls->_head->_next=node;
}
//ͷɾ
void ListPopFront(List* ls){
  if(ls->_head->_next==ls->_head) return;
  Node* front=ls->_head->_next;
  Node* next=front->_next;
  ls->_head->_next=next;
  next->_prev=ls->_head;
  free(front);
}
//������posλ�ò���ĳһ����Ԫ��
void ListInsert(Node* pos,Type data){
  Node* prev=pos->_prev;
  Node* node=createNode(data);
  prev->_next=node;
  node->_prev=prev;
  node->_next=pos;
  pos->_prev=node;
}
//������posλ��ɾ��ĳһ����Ԫ��
void ListErase(Node* pos){
  Node* prev=pos->_prev;
  Node* next=pos->_next;
  prev->_next=next;
  next->_prev=prev;
  free(pos);
}
//����Ԫ�ز���
Node* ListFind(List* ls,Type data){
  Node* node=ls->_head->_next;
  while(node!=ls->_head){
    if(node->_data==data) return node;
    else node=node->_next;
  }
}
//����Ԫ�ش�ӡ
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

  cout << "��������Ԫ�أ�" << endl;
  ListPrint(&ls);
  ListDestory(&ls);
  return 0;
}
