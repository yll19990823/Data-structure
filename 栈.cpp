//stackʵ�֣�˳���
#include<iostream>
#include<cstdlib>
using namespace std;

typedef int Type;
typedef struct Stack{
  Type* array;
  size_t size;
  size_t capacity;
}Stack;

//ջ��ʼ��
void StackInit(Stack* s,size_t n){
  s->array=(Type*)malloc(sizeof(Type)*n);
  s->size=0;
  s->capacity=n;
}
//ջ����
void StackDestory(Stack* s){
  free(s->array);
  s->array=NULL;
  s->size=s->capacity=0;
}
//��ջ
void StackPush(Stack* s,Type data){
  if(s->size==s->capacity){
    s->capacity*=2;
    s->array=(Type*)realloc(s->array,s->capacity);
  }
  s->array[s->size++]=data;
}
//��ջ
void StackPop(Stack* s){
  if(s->size) s->size--;
}
//���ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* s){
  if(!s->size) return true;
  else return false;
}
//����ջ������Ԫ�ظ���
int StackSize(Stack* s){
  return s->size;
}
//����ջ������Ԫ��
Type StackTop(Stack* s){
  return s->array[s->size-1];
}
//��������ӡջ�ڵ�����Ԫ��
void StackPrint(Stack* s){
  for(int i=s->size-1;i>=0;i--){
    cout << s->array[i] << " ";
  }
  cout << endl;
}
//�Գ�ջ�ķ�ʽ��ӡջ�ڵ�����Ԫ��
void StackPushPrint(Stack* s){
  while(StackEmpty(s)!=1){
    cout << StackTop(s) << " ";
    StackPop(s);
  }
  cout << endl;
}

int main(){
  Stack s;
  StackInit(&s,6);//��ʼ��һ������Ϊ6��ջ

  StackPush(&s,4);
  StackPush(&s,3);
  StackPush(&s,2);
  StackPush(&s,1);
  StackPop(&s);

  cout << "ջ��Ԫ�أ�" << StackTop(&s) << endl;
  cout << "ջ���ȣ�" <<  StackSize(&s) << endl;
  cout << "����ջԪ�أ�" << endl;
  StackPrint(&s);
  cout << "��ջ��ʽ����ջԪ�أ�" << endl;
  StackPushPrint(&s);
  StackDestory(&s);
  return 0;
}
