#include <stdio.h>
#include <stdlib.h>

// Function to Sort the files in ascending order, perform optimal file merging and return the minimum cost
int optimalMerge(int files[], int n) {
	for(int i=0; i<n-1; i++){
		for(int j = 0; j<n-i-1; j++){
			if(files[j]>files[j+1]){
				int temp = files[j];
				files[j]=files[j+1];
				files[j+1]=temp;
			}
		}
	}
	int totalCost = 0;
	while(n>1){
		int first = files[0];
		int second = files[1];
		int mergeCost = first + second;
		totalCost += mergeCost;
		files[0] = mergeCost;
		for(int i = 1; i<n-1; i++){
			files[i] = files[i+1];
		}
		n--;
		int key = files[0];
		int j = 1;
		while(j<n && files[j] <key){
			files[j-1]=files[j];
			j++;
		}
		files[j-1] = key;
	}
	return totalCost;
}

int main() {
    int n;
    printf("Number of files: ");
    scanf("%d", &n);
    int *files = (int *)malloc(n * sizeof(int));
    printf("Enter the sizes of %d files: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &files[i]);
    }
    int minCost = optimalMerge(files, n);
    printf("Minimum cost of merging is: %d\n", minCost);
    free(files);
    return 0;
}
