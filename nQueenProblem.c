#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isSafe(int **board, int row, int col, int n){
	int i,j;
	for(i=0; i<row; i++)
		if(board[i][col])
			return false;
	for(i=row-1,j=col-1; i>=0 && j>=0; i--, j--)
		if(board[i][j])
			return false;
	for(i=row-1,j=col+1; i>=0 && j<n; i--, j++)
		if(board[i][j])
			return false;
	return true;
}
void solveNQueens(int **board, int row, int n, int *count){
	if(row == n){
		(*count)++;
		return;
	}
	for(int col = 0; col<n; col++){
		if(isSafe(board,row,col,n)){
			board[row][col] = 1;
			solveNQueens(board, row + 1,n,count);
			board[row][col] = 0;
		}
	}
}
int totalNQueens(int n){
	int**board = (int**)malloc(n*sizeof(int *));
	for(int i = 0; i<n; i++)
		board[i] = (int *)calloc(n,sizeof(int));
	int count = 0;
	solveNQueens(board,0,n,&count);
	for(int i = 0; i<n; i++)
		free(board[i]);
	free(board);
	return count;
}
int main(){
	int n;
	scanf("%d", &n);
	int **board = (int **)malloc(n*sizeof(int*));
	for(int i = 0; i<n; i++)
		board[i] = (int*)calloc(n,sizeof(int));
	int count = 0;
	solveNQueens(board,0,n,&count);
	printf("%d",count);
	for(int i = 0; i<n; i++)
		free(board[i]);
	free(board);
	return 0;
}
