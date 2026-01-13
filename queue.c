#include <stdio.h>

#define SIZE 5
int queue[SIZE];
int f=-1,r=-1;

int Enqueue(int val){
    if(r == SIZE-1){
        printf("queue is full");
        return 0;
    }
    queue[++r] = val;
    if(f == -1)
      f = 0;
}
int Dequeue(){
    if(f == -1){
        printf("queue is empty \n");
        return 0;
    }
    printf("%d is deleted \n",queue[f]);
    f++;
    if(f > r){
        f = -1;
        r = -1;
    }
}

int Display(){
    if(f == -1){
        printf("queue is empty \n");
        return 0;
    }
    int i;
    for(i = f;i <= r;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main(){
    int c,val;
    while(1){
        printf("\n 1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d",&c);
        switch(c){
            case 1:
              printf("\n enter the number to insert ");
              scanf("%d",&val);
              Enqueue(val);
              break;
            case 2:
              Dequeue();
              break;
            case 3:
              printf("queue elements are ");
              Display();
              break;
            default:
              printf("invalid input");      
        }
    }
    return 0;
}