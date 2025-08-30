#include <stdio.h>
#define SIZE 5

int q[SIZE], front=-1, rear=-1;

void enqueue(int x){
    if(rear==SIZE-1) printf("Queue Full\n");
    else{
        if(front==-1) front=0;
        q[++rear]=x;
    }
}
void dequeue(){
    if(front==-1 || front>rear) printf("Queue Empty\n");
    else printf("Dequeued: %d\n",q[front++]);
}
void display(){
    if(front==-1 || front>rear) printf("Queue Empty\n");
    else{
        printf("Queue: ");
        for(int i=front;i<=rear;i++) printf("%d ",q[i]);
        printf("\n");
    }
}

int main(){
    enqueue(10); enqueue(20); enqueue(30);
    display(); dequeue(); display();
}
