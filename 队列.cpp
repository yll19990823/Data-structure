/*���У����ú���βָ��ĵ�����*/
#include<iostream>
#include<cstdlib>
using namespace std;

typedef int Type;
typedef struct Node{
  Type _data;
  struct Node* _next;
}Node;

typedef struct Queue{
  Node* _front;
  Node* _rear;
  size_t _size;
}Queue;

//�������
Node* createNode(Type data){
  Node* node=(Node*)malloc(sizeof(Node));
  node->_data=data;
  node->_next=NULL;
  return node;
}
//���г�ʼ��
void QueueInit(Queue* q){
  q->_front=q->_rear=NULL;
  q->_size=0;
}
//��������
void queueDestory(Queue* q){
  Node* cur=q->_front;
  while(cur){
    Node* next=cur->_next;
    free(cur);
    cur=next;
  }
  q->_front=q->_rear=NULL;
  q->_size=0;
}
//���
void QueuePush(Queue* q,Type data){
  Node* node=createNode(data);
  if(!q->_front){
    q->_front=q->_rear=node;
  }else{
    q->_rear->_next=node;
    q->_rear=node;
  }
  ++q->_size;
}
//����
void QueuePop(Queue* q){
  if(q->_front){
    Node* next=q->_front->_next;
    free(q->_front);
    q->_front=next;
    if(!q->_front) q->_rear=NULL;
  }
  --q->_size;
}
//���ض�ͷ����Ԫ��
Type QueueFront(Queue* q){
  return q->_front->_data;
}
//���ض�β����Ԫ��
Type QueueRear(Queue *q){
  return q->_rear->_data;
}
//�������Ƿ�Ϊ��
bool QueueEmpty(Queue* q){
  if(!q->_front) return true;
  else return false;
}
//���ض��е�����Ԫ�صĸ���
size_t QueueSize(Queue* q){
  return q->_size;
}
//��������ӡ���е�����Ԫ��
void QueuePrint(Queue* q){
  Node* cur=q->_front;
  while(cur){
    cout << cur->_data << " ";
    cur=cur->_next;
  }
  cout << endl;
}
//�Գ��ӵķ�ʽ��ӡ���е�����Ԫ��
void QueuePushPrint(Queue* q){
  while(QueueEmpty(q)!=1){
    cout << QueueFront(q) << " ";
    QueuePop(q);
  }
  cout << endl;
}

int main(){
  Queue q;
  QueueInit(&q);

  QueuePush(&q,1);
  QueuePush(&q,2);
  QueuePush(&q,3);
  QueuePush(&q,4);
  QueuePop(&q);

  cout << "��ͷԪ�أ�" << QueueFront(&q) << endl;
  cout << "��βԪ�أ�" << QueueRear(&q) << endl;
  cout << "���г��ȣ�" <<  QueueSize(&q) << endl;
  cout << "��������Ԫ�أ�" << endl;
  QueuePrint(&q);
  cout << "���ӷ�ʽ��������Ԫ�أ�" << endl;
  QueuePushPrint(&q);
  queueDestory(&q);
  return 0;
}
