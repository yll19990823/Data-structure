#include<iostream>
using namespace std;

/*冒泡排序
时间复杂度：最坏O(n^2) 平均O(n^2) 最好O(n)
空间复杂度：O(1)
稳定性：稳定
数据敏感：不敏感
*/
void bubbleSort(int* array,int n){
  while(n){
    int end=n;
    //一轮冒泡排序
    for(int i=0;i<end-1;i++){
      //相邻元素比较，大的向后移动
      if(array[i]>array[i+1]){
        swap(array[i],array[i+1]);
      }
    }
    n--;
  }
}

int main(){
  int array[]={3,6,2,9,1,5,10,7,4,8};

  bubbleSort(array,sizeof(array)/sizeof(array[0]));//直接插入排序
  //shellSort(array,sizeof(array)/sizeof(array[0]));//希尔排序

  cout<< "排序后的结果为：" << endl;
  for(auto k:array){
    cout << k << " ";
  }
  cout << endl;
  return 0;
}
