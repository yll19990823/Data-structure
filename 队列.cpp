/*队列：常用含有尾指针的单链表*/
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

//创建结点
Node* createNode(Type data){
  Node* node=(Node*)malloc(sizeof(Node));
  node->_data=data;
  node->_next=NULL;
  return node;
}
//队列初始化
void QueueInit(Queue* q){
  q->_front=q->_rear=NULL;
  q->_size=0;
}
//队列销毁
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
//入队
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
//出队
void QueuePop(Queue* q){
  if(q->_front){
    Node* next=q->_front->_next;
    free(q->_front);
    q->_front=next;
    if(!q->_front) q->_rear=NULL;
  }
  --q->_size;
}
//返回队头数据元素
Type QueueFront(Queue* q){
  return q->_front->_data;
}
//返回队尾数据元素
Type QueueRear(Queue *q){
  return q->_rear->_data;
}
//检查队列是否为空
bool QueueEmpty(Queue* q){
  if(!q->_front) return true;
  else return false;
}
//返回队列的数据元素的个数
size_t QueueSize(Queue* q){
  return q->_size;
}
//遍历并打印队列的数据元素
void QueuePrint(Queue* q){
  Node* cur=q->_front;
  while(cur){
    cout << cur->_data << " ";
    cur=cur->_next;
  }
  cout << endl;
}
//以出队的方式打印队列的数据元素
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

  cout << "队头元素：" << QueueFront(&q) << endl;
  cout << "队尾元素：" << QueueRear(&q) << endl;
  cout << "队列长度：" <<  QueueSize(&q) << endl;
  cout << "遍历队列元素：" << endl;
  QueuePrint(&q);
  cout << "出队方式遍历队列元素：" << endl;
  QueuePushPrint(&q);
  queueDestory(&q);
  return 0;
}
