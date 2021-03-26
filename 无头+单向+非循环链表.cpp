#include<iostream>
#include<cstdlib>
using namespace std;

typedef int Type;
typedef struct Node{
  Type _data;
  struct Node* _next;
}Node;

typedef struct SingleList{
  Node* _head;//head:��ʾ����������ͷ��㣬����һ����Ч�����ݵ�λ��
}SingleList;

//�������
Node* createNode(Type data){
  Node* node=(Node*)malloc(sizeof(Node));
  node->_data=data;
  node->_next=NULL;
  return node;
}
//�����ʼ��
void SingleListInit(SingleList* s){
  s->_head=NULL;
}
//��������
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
//β��
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
//βɾ
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
//ͷ��
void SingleListPushFront(SingleList* s,Type data){
  Node* node=createNode(data);
  if(!s->_head){
    s->_head=node;
  }else{
    node->_next=s->_head;
    s->_head=node;
  }
}
//ͷɾ
void SingleListPopFront(SingleList* s){
  if(s->_head){
    Node* cur=s->_head;
    s->_head=cur->_next;
    free(cur);
  }
}
//������posλ�ú����ĳһ����Ԫ��
void SingleListInsertAfter(Node* pos,Type data){
  Node* node=createNode(data);
  node->_next=pos->_next;
  pos->_next=node;
}
//������posλ�ú�ɾ��ĳһ����Ԫ��
void SingleListEraseAfter(Node* pos){
  if(!pos) return;
  Node* node=pos->_next;
  if(node){
    pos->_next=node->_next;
    free(node);
  }
}
//����Ԫ�ز���
Node* SingleListFind(SingleList* s,Type data){
  Node* cur=s->_head;
  while(cur){
    if(cur->_data==data) return cur;
    else cur=cur->_next;
  }
}
//����Ԫ�ش�ӡ
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

  cout << "��������Ԫ�أ�" << endl;
  SingleListPrint(&s);
  SingleListDestory(&s);
  return 0;
}
