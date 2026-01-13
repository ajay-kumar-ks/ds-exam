#include <stdio.h>

int a[20][20];
int visited[20];
int n,v;

void dfs(int v){
    int i;
    for(i = 0;i < n;i++){
        if(a[v][i] != 0 && visited[i] == 0){
            visited[i] = 1;
            printf("%d ",i);
            dfs(i);
        }
    }
}

int main(){
  int i,j;
  printf("enter how many verices ");
  scanf("%d",&n);

  for(i = 0;i<n;i++)
    visited[i] = 0;

  printf("enter the adjacency matric (1 for connected,0 for non) \n");
  for(i = 0;i < n;i++){
    for(j = 0;j < n;j++){
        scanf("%d",&a[i][j]);
    }
  }

  printf("enter starting vertex ");
  scanf("%d",&v);
  visited[v] = 1;
  printf("%d ",v);
  dfs(v);
  return 0;
}
