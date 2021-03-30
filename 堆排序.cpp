#include<iostream>
using namespace std;

//大堆向下调整
void shiftDown(int* array,int size,int parent){
  //左孩子位置
  int child=2*parent+1;
  while(child<size){
    //从左右两孩子中选择一个最大的
    if(child+1<size&&array[child+1]>array[child]) child++;
    //和父节点比较
    if(array[child]>array[parent]){
      swap(array[child],array[parent]);
      //更新
      parent=child;
      child=2*parent+1;
    }else break;
  }
}
void heapSort(int* array,int n){
  ////正式建堆：向下调整
  int size=n;
  for(int parent=(size-2)/2;parent>=0;parent--){
    shiftDown(array,size,parent);
  }
  //排序
  while(size>0){
    swap(array[0],array[size-1]);
    --size;
    shiftDown(array,size,0);
  }
}

int main(){
  int array[]={3,6,2,9,1,5,10,7,4,8};

  heapSort(array,sizeof(array)/sizeof(array[0]));//直接插入排序
  //shellSort(array,sizeof(array)/sizeof(array[0]));//希尔排序

  cout<< "排序后的结果为：" << endl;
  for(auto k:array){
    cout << k << " ";
  }
  cout << endl;
  return 0;
}
