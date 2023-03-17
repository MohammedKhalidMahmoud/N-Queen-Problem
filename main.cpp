#include <iostream>
#include <cmath>
#define N 4
using namespace std; 

bool isSafe(int grid[N][N],int row,int col){
  for(int i=0;i<col;i++)
    if(grid[row][i]==1) return false;

  for(int i=row,j=col; i>=0 && j>=0; i--,j--)
    if(grid[i][j]==1) return false;

  for(int i=row,j=col; i<N && j>=0; i++,j--)
    if(grid[i][j]==1) return false;

  return true;
}

bool solve(int grid[N][N],int col){
    if(col==N) return true;
    for(int i=0;i<N;i++){
        if(isSafe(grid,i,col)){
           grid[i][col]=1;
           if(solve(grid,col+1)) return true;
            grid[i][col]=0;
    }
}
 return false;
}

void print_grid(int grid[N][N]){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        cout<<grid[i][j]<<" ";
    }
    cout<<"\n";
  }
}
int main(){
    int grid[N][N]={
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
if(solve(grid,0)){
    print_grid(grid);
}
else
    cout<<"There is no solution";
return 0;
}
