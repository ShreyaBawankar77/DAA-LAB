#include<stdio.h>
#include <stdlib.h>
void print_subarray(int a[],int l, int r){
	for(int i = l; i<=r; i++){
		printf("%d ",a[i]);
		if(i<r)printf("");
	}
	printf("\n");
}
void merge(int a[], int l, int m, int r, int temp[]){
	int i=l, j=m+1,k=l;
	while(i<=m && j<=r){
		if(a[i]<=a[j]) 
			temp[k++] = a[i++];
		else 
			temp[k++]=a[j++];
	}
	while(i<=m)
		temp[k++] = a[i++];
	while(j<=r)
		temp[k++]=a[j++];
	for(int i = l; i<=r; i++)
		a[i] = temp[i];
	printf("Pass: ");
	print_subarray(a, l,r);
}
void mergesort(int a[],int l,int r,int temp[]){
	if(l>=r)return;
	int m =(l+r)/2;
	mergesort(a,l,m,temp);
	mergesort(a,m+1,r,temp);
	merge(a,l,m,r,temp);
}
	int main(){
		int n;
		printf("no of elements: ");
		scanf("%d", &n);
		int a[n], temp[n];
		printf("elements: ");
		for(int i=0; i<n; i++){
			scanf("%d", &a[i]);
		}
		printf("Given array:\n");
		print_subarray(a,0,n-1);
		mergesort(a,0,n-1,temp);
		printf("Sorted array:\n");
		print_subarray(a,0,n-1);
    return 0;
}
		return 0;
	}
