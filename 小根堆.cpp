#include<iostream>
#include<cstring>
using namespace std;

typedef int HPDataType;
typedef struct Heap{
  HPDataType* _array;
  int _size;
  int _capacity;
}Heap;

//С�����µ���
void shiftDown(HPDataType* array,int size,int parent){
  //����λ��
  int child=2*parent+1;
  while(child<size){
    //�����Һ�����ѡ��һ����С��
    if(child+1<size&&array[child+1]<array[child]) ++child;
    //�͸��ڵ�Ƚ�
    if(array[child]<array[parent]){
      swap(array[child],array[parent]);
      //����
      parent=child;
      child=2*parent+1;
    }else break;
  }
}
//С�����ϵ���
void shiftUp(HPDataType* array,int child){
  int parent=(child-1)/2;
  while(child>0){
    if(array[child]<array[parent]){
      swap(array[child],array[parent]);
      //����
      child=parent;
      parent=(child-1)/2;
    }else break;
  }
}

//����
void heapCreat(Heap* hp,HPDataType* array,int size){
  hp->_array=(HPDataType*)malloc(sizeof(HPDataType)*size);
  memcpy(hp->_array,array,sizeof(HPDataType)*size);
  hp->_capacity=size;
  //���ֽ��ѷ�ʽѡ��һ
  //��ʽ���ѣ����ϵ���
  hp->_size=0;
  for(int i=0;i<size;i++){
    hp->_size++;
    shiftUp(hp->_array,hp->_size-1);
  }
  /*//��ʽ���ѣ����µ���
  hp->_size=size;
  for(int parent=(size-2)/2;parent>=0;parent--){//(size-2)/2�����һ����Ҷ�ӽ��
    shiftDown(hp->_array,size,parent);
  }*/
}

//β��
void heapPush(Heap* hp,HPDataType data){
  if(hp->_size==hp->_capacity){
    hp->_capacity*=2;
    hp->_array=(HPDataType*)realloc(hp->_array,hp->_capacity*sizeof(HPDataType));
  }
  hp->_array[hp->_size++]=data;
  shiftUp(hp->_array,hp->_size-1);
}
//ɾ���Ѷ�Ԫ��
void heapPop(Heap* hp){
  if(hp->_size>0){
    //�������Ѷ�Ԫ�������һ��Ҷ��
    swap(hp->_array[0],hp->_array[hp->_size-1]);
    //βɾ
    hp->_size--;
    //���µ���
    shiftDown(hp->_array,hp->_size-1,0);
  }
}
//���ضѶ�Ԫ��
HPDataType heapTop(Heap* hp){
  return hp->_array[0];
}
//�ж϶��Ƿ�Ϊ��
bool heapEmpty(Heap* hp){
  if(!hp->_size) return true;
  else return false;
}
//�����򣺽���
void heapSort(Heap* hp){
  int size=hp->_size;
  HPDataType array[size];
  memcpy(array,hp->_array,sizeof(HPDataType)*size);
  //����
  for(int parent=(size-2)/2;parent>=0;parent--){
    shiftDown(array,size,parent);
  }

  while(size>0){
    //ѭ����βɾ
    swap(array[0],array[size-1]);
    --size;
    shiftDown(array,size,0);
  }

  for(auto key:array){
    cout << key << " ";
  }
  cout << endl;
}
//������Ԫ�ش�ӡ
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
  cout << "С���ѽ�������" << endl;
  heapSort(&hp);
  return 0;
}
