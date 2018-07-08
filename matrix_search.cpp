#include<iostream>
#include<algorithm>
#define R 3
#define C 4

using namespace std;
int bSearch_pos(int *arr,int l,int r,int val){
	if(r<l)
		return (val>arr[l])?l+1:l;
	int mid=(l+r)/2;
	if(arr[mid]==val)
		return mid+1;	
	else if(arr[mid]>val)
		return bSearch_pos(arr,l,mid-1,val);
	else
		return bSearch_pos(arr,mid+1,r,val);
}
bool matrix_search(int matrix[R][C],int k){
	int *arr=new int[R];
	for(int j=0;j<R;j++){
		arr[j]=matrix[j][0];//copy the first column to arr for b_searc_position
	}
	int idx=bSearch_pos(arr,0,R-1,k)-1;
	if(idx>=0){
		if(arr[idx]==k) return true;
		if(binary_search(matrix[idx],matrix[idx]+C,k)) return true;
	}
	return false;
}
int main(){
	int matrix[R][C]={
		{1,  2,  3,  4},
	    {5,  6,  7,  8},
	    {9, 10, 11, 12}
	};
	int k=9;
	if(matrix_search(matrix,k))
		cout<<"present\n";
	else
		cout<<"not\n";
	return 0;
}
