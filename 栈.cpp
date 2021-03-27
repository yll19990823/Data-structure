//stack实现：顺序表
#include<iostream>
#include<cstdlib>
using namespace std;

typedef int Type;
typedef struct Stack{
  Type* array;
  size_t size;
  size_t capacity;
}Stack;

//栈初始化
void StackInit(Stack* s,size_t n){
  s->array=(Type*)malloc(sizeof(Type)*n);
  s->size=0;
  s->capacity=n;
}
//栈销毁
void StackDestory(Stack* s){
  free(s->array);
  s->array=NULL;
  s->size=s->capacity=0;
}
//入栈
void StackPush(Stack* s,Type data){
  if(s->size==s->capacity){
    s->capacity*=2;
    s->array=(Type*)realloc(s->array,s->capacity);
  }
  s->array[s->size++]=data;
}
//出栈
void StackPop(Stack* s){
  if(s->size) s->size--;
}
//检查栈是否为空
bool StackEmpty(Stack* s){
  if(!s->size) return true;
  else return false;
}
//返回栈的数据元素个数
int StackSize(Stack* s){
  return s->size;
}
//返回栈顶数据元素
Type StackTop(Stack* s){
  return s->array[s->size-1];
}
//遍历并打印栈内的数据元素
void StackPrint(Stack* s){
  for(int i=s->size-1;i>=0;i--){
    cout << s->array[i] << " ";
  }
  cout << endl;
}
//以出栈的方式打印栈内的数据元素
void StackPushPrint(Stack* s){
  while(StackEmpty(s)!=1){
    cout << StackTop(s) << " ";
    StackPop(s);
  }
  cout << endl;
}

int main(){
  Stack s;
  StackInit(&s,6);//初始化一个长度为6的栈

  StackPush(&s,4);
  StackPush(&s,3);
  StackPush(&s,2);
  StackPush(&s,1);
  StackPop(&s);

  cout << "栈顶元素：" << StackTop(&s) << endl;
  cout << "栈长度：" <<  StackSize(&s) << endl;
  cout << "遍历栈元素：" << endl;
  StackPrint(&s);
  cout << "出栈方式遍历栈元素：" << endl;
  StackPushPrint(&s);
  StackDestory(&s);
  return 0;
}
