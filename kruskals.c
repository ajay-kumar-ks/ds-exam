#include <stdio.h>

#define MAX 10
#define INF 9999

int parent[MAX];

int find(int i){
    while(parent[i] != i){
        i = parent[i];
    }
    return i;
}
int uni(int i,int j){
    if(i != j){
        parent[j] = i;
        return 1;
    }
    return 0;
}
int main(){
    int i,j,v1,v2,v,u,n,min;
    int cost[MAX][MAX];
    int mincost = 0;
    int numedges = 1;

    printf("enter the number of edges ");
    scanf("%d",&n);
    printf("enter the matrix \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j] == 0){
                cost[i][j] = INF;
            }
        }
    }
    for(i = 1;i<=n;i++)
       parent[i] = i;
    while(numedges < n){
        min = INF;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(cost[i][j] < min){
                    min = cost[i][j];
                    v1 = i;
                    v2 = j;
                }
            }
        }
        u = find(v1);
        v = find(v2);
        if(uni(u,v)){
            printf("Edge %d : (%d - %d) cost = %d \n",numedges,v1,v2,min);
            numedges ++;
            mincost += min;
        }
        cost[v1][v2] = cost[v2][v1] = INF;
    }
    printf("min cost = %d",mincost);
    return 0;
}