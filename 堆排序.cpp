#include<iostream>
using namespace std;

//������µ���
void shiftDown(int* array,int size,int parent){
  //����λ��
  int child=2*parent+1;
  while(child<size){
    //��������������ѡ��һ������
    if(child+1<size&&array[child+1]>array[child]) child++;
    //�͸��ڵ�Ƚ�
    if(array[child]>array[parent]){
      swap(array[child],array[parent]);
      //����
      parent=child;
      child=2*parent+1;
    }else break;
  }
}
void heapSort(int* array,int n){
  ////��ʽ���ѣ����µ���
  int size=n;
  for(int parent=(size-2)/2;parent>=0;parent--){
    shiftDown(array,size,parent);
  }
  //����
  while(size>0){
    swap(array[0],array[size-1]);
    --size;
    shiftDown(array,size,0);
  }
}

int main(){
  int array[]={3,6,2,9,1,5,10,7,4,8};

  heapSort(array,sizeof(array)/sizeof(array[0]));//ֱ�Ӳ�������
  //shellSort(array,sizeof(array)/sizeof(array[0]));//ϣ������

  cout<< "�����Ľ��Ϊ��" << endl;
  for(auto k:array){
    cout << k << " ";
  }
  cout << endl;
  return 0;
}
