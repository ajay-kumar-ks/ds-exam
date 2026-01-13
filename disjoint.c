#include <stdio.h>

#define MAX 20

int parent[MAX];

void create(int n){
   for(int i = 0;i<n;i++)
       parent[i] = i;
}

int find(int u){
    if(parent[u] != u)
       parent[u] = find(parent[u]);
    return parent[u];
}
void unionset(int u,int v){
    int pu = find(u);
    int pv = find(v);
    if(pu == pv){
        printf("cycle detected at %d,%d \n",u,v);
        return;
    }
    parent[u] = v;
}
void display(int n){
    printf("Node representation :\n");
    for(int i = 0;i<n;i++){
        printf("%d : %d\n",i,find(i));
    }
}
int main(){
    int n,u,v,count;
    printf("enter the number of elements ");
    scanf("%d",&n);
    create(n);
    printf("enter the number of union ");
    scanf("%d",&count);
    for(int i = 0;i<count;i++){
        printf("enter edge pair ");
        scanf("%d %d",&u,&v);

        unionset(u,v);
    }
    display(n);
    return 0;
}