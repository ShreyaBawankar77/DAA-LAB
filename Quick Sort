#include <stdio.h>
int pass = 1;
void display(int a[], int low, int high){
	for(int i = low; i<=high; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}
void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
int partition (int a[], int low, int high){
	int pivot = a[high];
	int i = low-1;
	for(int j = low; j<high; j++){
		if(a[j]<pivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1], &a[high]);
	printf("Pass: ");
	display(a,low,high);
	return i+1;
}
void quickSort(int a[], int low, int high) {
	if(low<high) {
		int pi = partition(a,low,high);

		quickSort(a,low,pi-1);
		quickSort(a,pi+1,high);
	}
}
int main() {
	int a[100], n;
	printf("number of elements: ");
	scanf("%d", &n);
	printf("elements: ");
	for(int i = 0; i<n; i++){
		scanf("%d", &a[i]);
	}
	printf("Original array: ");
	display(a,0,n-1);
	quickSort(a,0,n-1);
	printf("Sorted array: ");
	display(a,0,n-1);
	return 0;
}
