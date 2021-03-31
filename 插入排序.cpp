#include<iostream>
using namespace std;

//直接插入排序
void insertSort(int* array,int n){
  for(int i=0;i<n-1;i++){
    //新数据插入
    //end：有序序列的最后一个位置
    int end=i;
    //key：待插入的数据
    int key=array[end+1];
    //找到第一个小于等于key的位置
    while(array[end]>key&&end>=0){
      //当前数据向后移动
      array[end+1]=array[end];
      --end;
    }
    array[end+1]=key;
  }
}

/*希尔排序
时间复杂度：最坏O(n^2) 平均O(n^1,3) 最好O(n)
空间复杂度：O(1)
稳定性：不稳定 -->分组时相同值的元素未必分到同一组，预
排序可能导致相对位置发送改变
数据敏感：敏感
*/
void shellSort(int* array,int n){
  int gap=n;
  //多轮插入排序
  while(gap>1){
    gap=gap/3+1;
    //一轮插入排序
    for(int i=0;i<n-gap;i++){
      //通过步长gap进行逻辑分组
      //组内进行插入排序
      //不同组的元素交替进行排序
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

  insertSort(array,sizeof(array)/sizeof(array[0]));//直接插入排序
  //shellSort(array,sizeof(array)/sizeof(array[0]));//希尔排序

  cout<< "排序后的结果为：" << endl;
  for(auto k:array){
    cout << k << " ";
  }
  cout << endl;
  return 0;
}
