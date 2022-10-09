#include<bits/stdc++.h>
using namespace std;

// RECURSIVE 

int find(int *arr,int low,int high, int x){
	if(high<low){
		return -1;
	}
	else{
		int mid=(high+low)/2;
		if(arr[mid]<x){
			return find(arr,mid+1,high,x);
		}
		else if(arr[mid]>x){
			return find(arr,low,mid-1,x);
		}
		else{
			if(mid==0||(arr[mid]!=arr[mid-1])){
				// cout<<"hello";
				return mid;
			}
			else{
				return find(arr,low,mid-1,x);
			}
		}
	}
}


// ITERATIVE

int findIterative(int *arr,int n,int x){
	int low=0,high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]<x){
			low=mid+1;
		}
		else if (arr[mid]>x){
			high=mid-1;
		}
		else{
			if(mid==0||(arr[mid]!=arr[mid-1])){
				return mid;
			}
			else{
				high=mid-1;
			}
		}
	}
	return -1;
}

int findLastOccu(int *arr,int n,int x){
	int low=0,high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]<x){
			low=mid+1;
		}
		else if (arr[mid]>x){
			high=mid-1;
		}
		else{
			if(mid==n-1||arr[mid]!=arr[mid+1]){
				return mid;
			}
			else{
				low=mid+1;
			}
		}
	}
	return -1;
}

int numberOccu(int *arr,int n,int x){
	int first=findIterative(arr,n,x);
	if(first==-1){
		return 0;
	}
	else{
		return (findLastOccu(arr,n,x)-first+1);
	}
}

int main(){
	int arr[]={10,10,15,20,20,20};
	int n=6;
	// cout<<find(arr,0,n,15);
	cout<<findIterative(arr,n,10)<<endl;
	cout<<findLastOccu(arr,n,15)<<endl;
	cout<<numberOccu(arr,n,10);
}