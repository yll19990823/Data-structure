#include<iostream>
using namespace std;

/*ð������
ʱ�临�Ӷȣ��O(n^2) ƽ��O(n^2) ���O(n)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ��ȶ�
�������У�������
*/
void bubbleSort(int* array,int n){
  while(n){
    int end=n;
    //һ��ð������
    for(int i=0;i<end-1;i++){
      //����Ԫ�رȽϣ��������ƶ�
      if(array[i]>array[i+1]){
        swap(array[i],array[i+1]);
      }
    }
    n--;
  }
}

int main(){
  int array[]={3,6,2,9,1,5,10,7,4,8};

  bubbleSort(array,sizeof(array)/sizeof(array[0]));//ֱ�Ӳ�������
  //shellSort(array,sizeof(array)/sizeof(array[0]));//ϣ������

  cout<< "�����Ľ��Ϊ��" << endl;
  for(auto k:array){
    cout << k << " ";
  }
  cout << endl;
  return 0;
}
