#include<iostream>
#include<stack>
#include<queue>
using namespace std;


//划分方法：前后指针法
int partion(int* array,int begin,int end){
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

//栈实现非递归：保存待划分的区间
void quickSortNS(int* array,int n){
  stack<int> st;
  if(n>1){
    st.push(n-1);
    st.push(0);
  }
  //遍历栈，划分栈中的每一个区间
  while(st.empty()!=1){
    int begin=st.top();
    st.pop();
    int end=st.top();
    st.pop();
    //划分
    int key=partion(array,begin,end);
    //子区间入栈：先右后左
    //右：key+1，end
    if(key+1<end){
      st.push(end);
      st.push(key+1);
    }
    //左：begin，key-1
    if(begin<key-1){
      st.push(key-1);
      st.push(begin);
    }
  }
}

//队列实现非递归：保存待划分的区间
void quickSortNQ(int* array,int n){
  queue<int> qu;
  if(n>1){
    qu.push(0);
    qu.push(n-1);
  }
  while(qu.empty()!=1){
    int begin=qu.front();
    qu.pop();
    int end=qu.front();
    qu.pop();
    int key=partion(array,begin,end);
    if(key+1<end){
      qu.push(key+1);
      qu.push(end);
    }
    if(begin<key-1){
      qu.push(begin);
      qu.push(key-1);
    }
  }
}

int main(){
  int array[]={3,6,2,9,1,5,10,7,4,8};

  quickSortNQ(array,sizeof(array)/sizeof(array[0]));
  //shellSort(array,sizeof(array)/sizeof(array[0]));

  cout<< "排序后的结果为：" << endl;
  for(auto k:array){
    cout << k << " ";
  }
  cout << endl;
  return 0;
}
