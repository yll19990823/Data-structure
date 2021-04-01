#include<iostream>
using namespace std;

/*����ȡ��
ʱ�临�Ӷȣ����O(nlogn) ƽ����O(nlogn) ��ã�O(nlogn)
�ռ临�Ӷȣ�O(nlogn)
�ȶ��ԣ����ȶ�
�������У�����
*/
int getMid(int* array,int begin,int end){
	int mid=begin+(end-begin)/2;
	//begin,mid,end ѡ���м��λ��
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

/*��������
ʱ�临�Ӷȣ����O(n^2) ƽ����O(nlogn) ��ã�O(nlogn)
�ռ临�Ӷȣ�O(logn) ��������ջ   ���������O(n)
�ȶ��ԣ����ȶ�
�������У�����
*/
/*�ݹ�*/
//��һ�ֻ��ַ����� hora����
int partion1(int* array,int begin,int end){
  /*�Ż�
  //����ȡ��
  int mid = getMid(array, begin, end);
  //���� mid -- begin
  swap(array[begin],array[mid]);
  */

  int key=array[begin];
  int start=begin;
  //����
  while(begin<end){
    //�Ӻ���ǰ�ҵ�һ��С��key��λ��
    while(begin<end&&array[end]>=key){
      --end;
    }
    //��ǰ�����ҵ�һ������key��λ��
    while(begin<end&&array[begin]<=key){
      ++begin;
    }
    //����begin��end
    swap(array[begin],array[end]);
  }
  //key������λ�õ����ݽ���
  swap(array[start],array[begin]);
  //���ػ�׼ֵ��λ��
  return begin;
}
void quickSort1(int* array,int begin,int end){
  if(begin>=end) return;
  //���ֵ�ǰ����
  int pos=partion1(array,begin,end);
  //����������
  quickSort1(array,begin,pos-1);
  quickSort1(array,pos+1,end);
}


//�ڶ��ֻ��ַ������ڿӷ�
int partion2(int* array,int begin,int end){
  /*�Ż�
  //����ȡ��
  int mid = getMid(array, begin, end);
  //���� mid -- begin
  swap(array[begin],array[mid]);
  */

  //��׼ֵ
  int key=array[begin];
  while(begin<end){
    //�Ӻ���ǰ��
    while(begin<end&&array[end]>=key){
      --end;
    }
    //��ӣ�����begin
    array[begin]=array[end];
    //��ǰ�����
    while(begin<end&&array[begin]<=key){
      ++begin;
    }
    //��ӣ�end
    array[end]=array[begin];
  }
  //���һ���ӣ�������λ�� --> ����׼ֵ
  array[begin]=key;
  //���ػ�׼ֵ��λ��
  return begin;
}
void quickSort2(int* array,int begin,int end){
  if(begin>=end) return;
  //���ֵ�ǰ����
  int pos=partion2(array,begin,end);
  //����������
  quickSort2(array,begin,pos-1);
  quickSort2(array,pos+1,end);
}

//�����ֻ��ַ�����ǰ��ָ�뷨
int partion3(int* array,int begin,int end){
  /*�Ż�
  //����ȡ��
  int mid = getMid(array, begin, end);
  //���� mid -- begin
  swap(array[begin],array[mid]);
  */

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
void quickSort3(int* array,int begin,int end){
  if(begin>=end) return;
  //���ֵ�ǰ����
  int pos=partion3(array,begin,end);
  //����������
  quickSort3(array,begin,pos-1);
  quickSort3(array,pos+1,end);
}

int main(){
  int array[]={3,6,2,9,1,5,10,7,4,8};

  quickSort3(array,0,sizeof(array)/sizeof(array[0]));
  //shellSort(array,sizeof(array)/sizeof(array[0]));

  cout<< "�����Ľ��Ϊ��" << endl;
  for(auto k:array){
    cout << k << " ";
  }
  cout << endl;
  return 0;
}
