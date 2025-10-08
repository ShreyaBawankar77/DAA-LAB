#include <stdio.h>
#include <stdlib.h>
int max(int a, int b){
	return (a>b)? a:b;
}
int knapsack(int W, int wt[], int val[], int n){
	int i, w;
	int **dp = (int**)malloc((n+1) * sizeof(int*));
	for (i = 0; i<=n; i++)
		dp[i] = (int*)malloc((W+1) * sizeof(int));
	for (i=0; i<=n; i++){
		for(w=0; w<=W; w++){
			if(i==0 || w == 0)
				dp[i][w] = 0;
			else if (wt[i-1] <= w)
				dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
			else
				dp[i][w] = dp[i-1][w];
		}
	}
	int result = dp[n][W];
	for (i=0; i<=n; i++)
		free(dp[i]);
	free(dp);
	return result;
}
int main(){
	int n, W, i;
	scanf("%d", &n);
	int *val = (int*)malloc(n*sizeof(int));
	int *wt = (int*)malloc(n*sizeof(int));
	for (i=0; i<n; i++){
		scanf("%d", &val[i]);
	}
	for (i=0; i<n; i++){
		scanf("%d", &wt[i]);
	}
	scanf("%d", &W);
	printf("%d\n", knapsack(W, wt, val, n));
	free(val);
	free(wt);
	return 0;
}
