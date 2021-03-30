#include<iostream>
#include<cstring>
using namespace std;

typedef int HPDataType;
typedef struct Heap{
  HPDataType* _array;
  int _size;
  int _capacity;
}Heap;

//小堆向下调整
void shiftDown(HPDataType* array,int size,int parent){
  //左孩子位置
  int child=2*parent+1;
  while(child<size){
    //从左右孩子中选择一个最小的
    if(child+1<size&&array[child+1]<array[child]) ++child;
    //和父节点比较
    if(array[child]<array[parent]){
      swap(array[child],array[parent]);
      //更新
      parent=child;
      child=2*parent+1;
    }else break;
  }
}
//小堆向上调整
void shiftUp(HPDataType* array,int child){
  int parent=(child-1)/2;
  while(child>0){
    if(array[child]<array[parent]){
      swap(array[child],array[parent]);
      //更新
      child=parent;
      parent=(child-1)/2;
    }else break;
  }
}

//建堆
void heapCreat(Heap* hp,HPDataType* array,int size){
  hp->_array=(HPDataType*)malloc(sizeof(HPDataType)*size);
  memcpy(hp->_array,array,sizeof(HPDataType)*size);
  hp->_capacity=size;
  //两种建堆方式选其一
  //正式建堆：向上调整
  hp->_size=0;
  for(int i=0;i<size;i++){
    hp->_size++;
    shiftUp(hp->_array,hp->_size-1);
  }
  /*//正式建堆：向下调整
  hp->_size=size;
  for(int parent=(size-2)/2;parent>=0;parent--){//(size-2)/2：最后一个非叶子结点
    shiftDown(hp->_array,size,parent);
  }*/
}

//尾插
void heapPush(Heap* hp,HPDataType data){
  if(hp->_size==hp->_capacity){
    hp->_capacity*=2;
    hp->_array=(HPDataType*)realloc(hp->_array,hp->_capacity*sizeof(HPDataType));
  }
  hp->_array[hp->_size++]=data;
  shiftUp(hp->_array,hp->_size-1);
}
//删除堆顶元素
void heapPop(Heap* hp){
  if(hp->_size>0){
    //交换：堆顶元素与最后一个叶子
    swap(hp->_array[0],hp->_array[hp->_size-1]);
    //尾删
    hp->_size--;
    //向下调整
    shiftDown(hp->_array,hp->_size-1,0);
  }
}
//返回堆顶元素
HPDataType heapTop(Heap* hp){
  return hp->_array[0];
}
//判断堆是否为空
bool heapEmpty(Heap* hp){
  if(!hp->_size) return true;
  else return false;
}
//堆排序：降序
void heapSort(Heap* hp){
  int size=hp->_size;
  HPDataType array[size];
  memcpy(array,hp->_array,sizeof(HPDataType)*size);
  //建堆
  for(int parent=(size-2)/2;parent>=0;parent--){
    shiftDown(array,size,parent);
  }

  while(size>0){
    //循环假尾删
    swap(array[0],array[size-1]);
    --size;
    shiftDown(array,size,0);
  }

  for(auto key:array){
    cout << key << " ";
  }
  cout << endl;
}
//堆数据元素打印
void heapPrint(Heap* hp){
  for(int i=0;i<hp->_size;i++){
    cout << hp->_array[i] << " ";
  }
  cout << endl;
}

int main(){
  Heap hp;
  int array[]={100,50,30,20,25,18,10,5,15,21,23};
  heapCreat(&hp,array,sizeof(array)/sizeof(array[0]));
  heapPrint(&hp);
  cout << "小根堆降序排序：" << endl;
  heapSort(&hp);
  return 0;
}
