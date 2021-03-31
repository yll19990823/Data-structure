#include<iostream>
using namespace std;

//ֱ�Ӳ�������
void insertSort(int* array,int n){
  for(int i=0;i<n-1;i++){
    //�����ݲ���
    //end���������е����һ��λ��
    int end=i;
    //key�������������
    int key=array[end+1];
    //�ҵ���һ��С�ڵ���key��λ��
    while(array[end]>key&&end>=0){
      //��ǰ��������ƶ�
      array[end+1]=array[end];
      --end;
    }
    array[end+1]=key;
  }
}

/*ϣ������
ʱ�临�Ӷȣ��O(n^2) ƽ��O(n^1,3) ���O(n)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ����ȶ� -->����ʱ��ֵͬ��Ԫ��δ�طֵ�ͬһ�飬Ԥ
������ܵ������λ�÷��͸ı�
�������У�����
*/
void shellSort(int* array,int n){
  int gap=n;
  //���ֲ�������
  while(gap>1){
    gap=gap/3+1;
    //һ�ֲ�������
    for(int i=0;i<n-gap;i++){
      //ͨ������gap�����߼�����
      //���ڽ��в�������
      //��ͬ���Ԫ�ؽ����������
      int end=i;
      int key=array[end+gap];
      while(end>=0&&array[end]>key){
        array[end+gap]=array[end];
        end-=gap;
      }
      array[end+gap]=key;
    }
  }
}

int main(){
  int array[]={3,6,2,9,1,5,10,7,4,8};

  insertSort(array,sizeof(array)/sizeof(array[0]));//ֱ�Ӳ�������
  //shellSort(array,sizeof(array)/sizeof(array[0]));//ϣ������

  cout<< "�����Ľ��Ϊ��" << endl;
  for(auto k:array){
    cout << k << " ";
  }
  cout << endl;
  return 0;
}
