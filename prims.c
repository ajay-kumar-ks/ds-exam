#include <stdio.h>

#define INF 9999
#define MAX 20

void prims(int n,int cost[MAX][MAX],int t[MAX][2]){
    int near[MAX],i,j,k,l;
    int min = INF;
    int mincost = 0;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i != j && cost[i][j] < min){
                min = cost[i][j];
                k = j;
                l = i;
            }
        }
    }
    t[1][0] = k;
    t[1][1] = l;
    mincost += cost[k][l];
    for(i=1;i<=n;i++){
        if(cost[i][k] < cost[i][l])
            near[i] = k;
        else
            near[i] = l;
    }
    near[k] = 0;
    near[l] = 0;

    for(i=2;i<n;i++){
       int next = 0;
       min = INF;
       for(j=1;j<=n;j++){
            if(near[j] != 0 && cost[j][near[j]]<min){
                min = cost[j][near[j]];
                next = j;
            }
       }
        t[i][0] = next;
        t[i][1] = near[next];
        mincost += cost[next][near[next]];
        near[next] = 0;
        for(j=1;j<=n;j++){
           if(near[j] != 0 && cost[j][next] < cost[j][near[j]]){
             near[j] = next;
           }
        }
    }
    for(i=1;i<n;i++){
        printf("vertices are %d, %d \n",t[i][0],t[i][1]);
    }
    printf("min cost = %d \n",mincost);
}
int main(){
    int n,t[MAX][2],cost[MAX][MAX];

    printf("enter the number of edges ");
    scanf("%d",&n);
    printf("enter the edges cost \n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
          scanf("%d",&cost[i][j]);
        }
    }
    prims(n,cost,t);
    return 0;
}