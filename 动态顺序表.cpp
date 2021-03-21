#include<iostream>
#include<cstdlib>
using namespace std;

typedef int DateType;
typedef struct SepList{
  DateType* array;
  size_t size;//size_t:无符号整型（别名） size:元素个数
  size_t capacity;//capacity:容量,即当前可用空间
}SepList;

//顺序表初始化
void SepListInit(SepList* s){
  s->array=(DateType*)malloc(sizeof(DateType)*4);
  s->size=0;
  s->capacity=4;
}
//检查顺序表容量是否充足，否则增容
void checkCapacity(SepList* s){
  //增加顺序表容量
  if(s->size==s->capacity){
    s->capacity*=2;
    /*
		//开空间
		DateType* newArray = (DateType*)malloc(sizeof(DateType) * s1->capacity);
		//拷贝
		memcpy(newArray, s->array, s->size * sizeof(DateType);
		//释放空间
		free(s->array);
		s->array = newArray;
		*/
    s->array=(DateType*)realloc(s->array,sizeof(DateType)*s->capacity);
  }
}
//顺序表销毁
void SepListDestory(SepList* s){
  free(s->array);
  s->size=0;
  s->capacity=10;
}
//顺序表数据元素打印
void SepListPrint(SepList* s){
  for(int i=0;i<s->size;i++){
    cout << s->array[i] << " ";
  }
  cout << endl;
}
//顺序表尾插
void SepListPushBack(SepList* s,DateType date){
  checkCapacity(s);
  s->array[s->size++]=date;
}
//顺序表尾删
void SepListPopBack(SepList* s){
  if(s->size) s->size--;
}
//顺序表头插
void SepListPushFront(SepList* s,DateType date){
  checkCapacity(s);
  for(int i=s->size++;i>0;i--){
    s->array[i]=s->array[i-1];
  }
  s->array[0]=date;
}
//顺序表头删
void SepListPopFront(SepList* s){
  if(s->size){
    for(int i=0;i<s->size-1;i++){
        s->array[i]=s->array[i+1];
    }
    s->size--;
  }
}
//顺序表查找数据元素位置
int SepListFind(SepList* s,DateType date){
  for(int i=0;i<s->size;i++){
    if(s->array[i]==date) return i+1;
  }
  return -1;
}
//在顺序表pos位置处插入某一数据元素
void SepListInsert(SepList* s,size_t pos,DateType date){
  if(pos<=s->size){
    checkCapacity(s);
    for(int i=s->size++;i>pos;i--){
      s->array[i]=s->array[i-1];
    }
    s->array[pos]=date;
  }
}
//在顺序表pos位置处删除某一数据元素
void SepListErase(SepList* s,size_t pos){
  if(pos<s->size){
    for(int i=pos;i<s->size-1;i++){
        s->array[i]=s->array[i+1];
    }
    s->size--;
  }
}
int main(){
  SepList s;
  SepListInit(&s);

  SepListPushBack(&s,2);
  SepListPushBack(&s,3);
  SepListPushBack(&s,4);
  SepListPopBack(&s);

  SepListPushFront(&s,1);
  SepListPushFront(&s,0);
  SepListPopFront(&s);

  SepListInsert(&s,2,2);
  SepListErase(&s,2);

  cout << "顺序表数据元素：" << endl;
  SepListPrint(&s);
  cout << "查找元素 2 在顺序表中的位置：" << SepListFind(&s,2) << endl;
  SepListDestory(&s);
  return 0;
}
