#include <stdio.h>

#define SIZE 5
int queue[SIZE];
int f=-1,r=-1;

void Enqueue(int val){
    if((r+1)%SIZE == f){
        printf("queue is full");
        return;    
    }
    if(f == -1){
        f = 0;
        r = 0;
    }else{
        r=(r+1)%SIZE;
    }
    queue[r] = val;
}
int Dequeue(){
    if(f == -1){
        printf("queue is empty \n");
        return 0;
    }
    printf("%d is deleted \n",queue[f]);
    if(f == r){
        f = -1;
        r = -1;
    }else{
        f = (f+1)%SIZE;
    }
}

int Display(){
    if(f == -1){
        printf("queue is empty \n");
        return 0;
    }
    int i = f;
    while(1){
        printf("%d ", queue[i]);
        if(i == r)
            break;
        i = (i + 1) % SIZE;
    }

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