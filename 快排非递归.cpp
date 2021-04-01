#include<iostream>
#include<stack>
#include<queue>
using namespace std;


//���ַ�����ǰ��ָ�뷨
int partion(int* array,int begin,int end){
  //prev�����һ��С�ڻ�׼ֵ��λ��
  int prev=begin;
  //cur���·��ֵ���һ��С�ڻ�׼ֵ��λ��
  int cur=prev+1;
  int key=array[begin];
  while(cur<=end){
    //�·��ֵ�С���ݺ�βָ��ָ���λ�ò����������м京�д��ڻ�׼ֵ�����ݣ��ʽ��н���
    //����������ƶ���С������ǰ�ƶ�
    if(array[cur]<key&&++prev!=cur){
      swap(array[prev],array[cur]);
    }
    ++cur;
  }
  swap(array[begin],array[prev]);
  return prev;
}

//ջʵ�ַǵݹ飺��������ֵ�����
void quickSortNS(int* array,int n){
  stack<int> st;
  if(n>1){
    st.push(n-1);
    st.push(0);
  }
  //����ջ������ջ�е�ÿһ������
  while(st.empty()!=1){
    int begin=st.top();
    st.pop();
    int end=st.top();
    st.pop();
    //����
    int key=partion(array,begin,end);
    //��������ջ�����Һ���
    //�ң�key+1��end
    if(key+1<end){
      st.push(end);
      st.push(key+1);
    }
    //��begin��key-1
    if(begin<key-1){
      st.push(key-1);
      st.push(begin);
    }
  }
}

//����ʵ�ַǵݹ飺��������ֵ�����
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

  cout<< "�����Ľ��Ϊ��" << endl;
  for(auto k:array){
    cout << k << " ";
  }
  cout << endl;
  return 0;
}
