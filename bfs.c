#include <stdio.h>

int a[20][20];
int queue[20];
int f = -1,r = -1;
int visited[20];
int n,v,i,j;

void bfs(int v){
    for(i = 0;i < n;i++){
        if(a[v][i] != 0 && visited[i] == 0){
            queue[++r] = i;
            visited[i] = 1;
            printf("%d ",i);
        }
    }
    f++;
    if(f > r)
      return;
    bfs(queue[f]);
}

int main(){
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
  f = 0;
  r = 0;
  visited[v] = 1;
  queue[r] = v;
  printf("%d ",v);
  bfs(v);
  return 0;
}
