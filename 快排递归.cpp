#include<iostream>
using namespace std;

/*三数取中
时间复杂度：最坏：O(nlogn) 平均：O(nlogn) 最好：O(nlogn)
空间复杂度：O(nlogn)
稳定性：不稳定
数据敏感：敏感
*/
int getMid(int* array,int begin,int end){
	int mid=begin+(end-begin)/2;
	//begin,mid,end 选择中间的位置
	if(array[begin]<array[mid]){
		//begin < mid
		if(array[mid]<array[end]){
			return mid;
		}else{
			//begin < mid, end <= mid
			if(array[begin]>array[end]) return begin;
			else return end;
		}
	}else{
		//begin >= end
		if(array[mid]>array[end]){
			return mid;
		}else{
			//begin >= mid, end >= mid
			if(array[begin]<array[end]) return begin;
			else return end;
		}
	}
}

/*快速排序
时间复杂度：最坏：O(n^2) 平均：O(nlogn) 最好：O(nlogn)
空间复杂度：O(logn) 函数调用栈   极端情况：O(n)
稳定性：不稳定
数据敏感：敏感
*/
/*递归*/
//第一种划分方法： hora划分
int partion1(int* array,int begin,int end){
  /*优化
  //三数取中
  int mid = getMid(array, begin, end);
  //交换 mid -- begin
  swap(array[begin],array[mid]);
  */

  int key=array[begin];
  int start=begin;
  //划分
  while(begin<end){
    //从后往前找第一个小于key的位置
    while(begin<end&&array[end]>=key){
      --end;
    }
    //从前往后找第一个大于key的位置
    while(begin<end&&array[begin]<=key){
      ++begin;
    }
    //交换begin，end
    swap(array[begin],array[end]);
  }
  //key和相遇位置的数据交换
  swap(array[start],array[begin]);
  //返回基准值的位置
  return begin;
}
void quickSort1(int* array,int begin,int end){
  if(begin>=end) return;
  //划分当前区间
  int pos=partion1(array,begin,end);
  //划分子区间
  quickSort1(array,begin,pos-1);
  quickSort1(array,pos+1,end);
}


//第二种划分方法：挖坑法
int partion2(int* array,int begin,int end){
  /*优化
  //三数取中
  int mid = getMid(array, begin, end);
  //交换 mid -- begin
  swap(array[begin],array[mid]);
  */

  //基准值
  int key=array[begin];
  while(begin<end){
    //从后向前找
    while(begin<end&&array[end]>=key){
      --end;
    }
    //填坑：交换begin
    array[begin]=array[end];
    //从前向后找
    while(begin<end&&array[begin]<=key){
      ++begin;
    }
    //填坑：end
    array[end]=array[begin];
  }
  //最后一个坑：相遇的位置 --> 填充基准值
  array[begin]=key;
  //返回基准值的位置
  return begin;
}
void quickSort2(int* array,int begin,int end){
  if(begin>=end) return;
  //划分当前区间
  int pos=partion2(array,begin,end);
  //划分子区间
  quickSort2(array,begin,pos-1);
  quickSort2(array,pos+1,end);
}

//第三种划分方法：前后指针法
int partion3(int* array,int begin,int end){
  /*优化
  //三数取中
  int mid = getMid(array, begin, end);
  //交换 mid -- begin
  swap(array[begin],array[mid]);
  */

  //prev：最后一个小于基准值的位置
  int prev=begin;
  //cur：新发现的下一个小于基准值的位置
  int cur=prev+1;
  int key=array[begin];
  while(cur<=end){
    //新发现的小数据和尾指针指向的位置不连续，则中间含有大于基准值的数据，故进行交换
    //大数据向后移动，小数据向前移动
    if(array[cur]<key&&++prev!=cur){
      swap(array[prev],array[cur]);
    }
    ++cur;
  }
  swap(array[begin],array[prev]);
  return prev;
}
void quickSort3(int* array,int begin,int end){
  if(begin>=end) return;
  //划分当前区间
  int pos=partion3(array,begin,end);
  //划分子区间
  quickSort3(array,begin,pos-1);
  quickSort3(array,pos+1,end);
}

int main(){
  int array[]={3,6,2,9,1,5,10,7,4,8};

  quickSort3(array,0,sizeof(array)/sizeof(array[0]));
  //shellSort(array,sizeof(array)/sizeof(array[0]));

  cout<< "排序后的结果为：" << endl;
  for(auto k:array){
    cout << k << " ";
  }
  cout << endl;
  return 0;
}
